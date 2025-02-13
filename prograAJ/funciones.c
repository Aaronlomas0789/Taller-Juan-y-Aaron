#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
void buscarPorTamano(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char tipo[40];
    printf("Ponga el tamano de habitacion que deseea: ");
    scanf("%s", tipo);
    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][1], tipo) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Escoga la habitacion que quiera reservar: ");
    scanf("%d", numHabitacion);
}
 
void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char nombreHotel[40];
    printf("Ponga el nombre del hotel que le interesa: ");
    scanf("%s", nombreHotel);
    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], nombreHotel) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Ponga la habitacion que mas se ajuste a sus necesidades: ");
    scanf("%d", numHabitacion);
}
 
void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]) {
    int clienteNuevo = -1;
    for (int i = 0; i < 5; i++) {
        if (clientes[i][0][0] == '\0') {
            clienteNuevo = i;
            break;
        }
    }
    if (clienteNuevo == -1) {
        printf("No hay mas aforo para clientes.\n");
        return;
    }
 
    if (reservas[numHabitacion - 1][1] != -1) {
        printf("Ya ser reservo la habitacion %d .\n", numHabitacion);
        return;
    }
 
    printf("Ponga el nombre del cliente: ");
    scanf("%s", clientes[clienteNuevo][0]);
    printf("Ponga la cédula del cliente: ");
    scanf("%s", clientes[clienteNuevo][1]);
 
    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == -1) {
            reservas[i][0] = clienteNuevo;
            reservas[i][1] = numHabitacion - 1;
            reservas[i][2] = 0;
            reservas[i][3] = 0;
            printf("Reserva hecha exsitosamente.\n");
            return;
        }
    }
 
    printf("Aforo no disponible para reservas.\n");
}
 
void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]) {
    char cedula[40];
    printf("Ponga la cedula que desea buscar la reserva: ");
    scanf("%s", cedula);
    for (int i = 0; i < 10; i++) {
        if ((reservas[i][0] != -1) && (strcmp(clientes[reservas[i][0]][1], cedula) == 0)) {
            *numReserva = i;
            return;
        }
    }
    *numReserva = -1;
}
 
void imprimirReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[], char clientes[][2][40]) {
    if (numReserva != -1) {
        int clienteIndex = reservas[numReserva][0];
        int habitacionIndex = reservas[numReserva][1];
        char *nombreCliente = clientes[clienteIndex][0];
        printf("Reserva %d: Cliente %s en Habitación %s (%s) de %s con precio %.2lf\n",
               numReserva+1, nombreCliente, habitaciones[habitacionIndex][0], habitaciones[habitacionIndex][1],
               habitaciones[habitacionIndex][2], precios[habitacionIndex]);
        if (reservas[numReserva][3] == 1) {
            printf("Estado: Pagada\n");
        } else {
            printf("Estado: No Pagada\n");
        }
    } else {
        printf("Reserva no encontrada.\n");
    }
}
 
void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    if (numReserva != -1) {
        if (reservas[numReserva][3] == 1) {
            printf("Reserva pagada.\n");
        } else {
            reservas[numReserva][3] = 1;
            printf("Reserva %d pagada.\n", numReserva+1);
            guardarReservas(reservas, "C:/Users/aaron/OneDrive/Escritorio/prograAJ/reservas.txt");
        }
    } else {
        printf("No se encontro reserva.\n");
    }
}
 
void leerClientes(char clientes[][2][40], const char *filename) {
    FILE *file = fopen("C:/Users/aaron/OneDrive/Escritorio/prograAJ/clientes.txt", "r");
 
    for (int i = 0; i < 5; i++) {
        if (fscanf(file, "%s %s", clientes[i][0], clientes[i][1]) != 2) {
            break;
        }
    }
    fclose(file);
}
 
void leerReservas(int reservas[][4], const char *filename) {
    FILE *file = fopen("C:/Users/aaron/OneDrive/Escritorio/prograAJ/reservas.txt", "r");
 
    for (int i = 0; i < 10; i++) {
        if (fscanf(file, "%d %d %d %d", &reservas[i][0], &reservas[i][1], &reservas[i][2], &reservas[i][3]) != 4) {
            break;
        }
    }
   
    fclose(file);
}
 
void guardarClientes(char clientes[][2][40], const char *filename) {
    FILE *file = fopen("C:/Users/aaron/OneDrive/Escritorio/prograAJ/clientes.txt", "w");
 
    for (int i = 0; i < 5; i++) {
        if (clientes[i][0][0] != '\0') {
            fprintf(file, "%s %s\n", clientes[i][0], clientes[i][1]);
        }
    }
    fclose(file);
}
 
void guardarReservas(int reservas[][4], const char *filename) {
    FILE *file = fopen("C:/Users/aaron/OneDrive/Escritorio/prograAJ/reservas.txt", "a+");
 
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%d %d %d %d\n", reservas[i][0], reservas[i][1], reservas[i][2], reservas[i][3]);
    }
    fclose(file);
}