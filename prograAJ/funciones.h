void buscarPorTamano(int *numHabitacion, char habitaciones[][3][40], double precios[]);
void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]);
void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]);
void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]);
void imprimirReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[], char clientes[][2][40]);
void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]);
void leerClientes(char clientes[][2][40], const char *filename);
void leerReservas(int reservas[][4], const char *filename);
void guardarClientes(char clientes[][2][40], const char *filename);
void guardarReservas(int reservas[][4], const char *filename);