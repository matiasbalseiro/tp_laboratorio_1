#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

int menuPrincipal(){

	int opc;

	utn_getNumero(&opc,
					"\n*****************************MENU PRINCIPAL*****************************\n\n"
							" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
							" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
							" 3. Alta de empleado\n"
							" 4. Modificar datos de empleado\n"
							" 5. Baja de empleado\n"
							" 6. Listar empleados\n"
							" 7. Ordenar empleados\n"
							" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
							" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
							" 10. Salir\n\n"
							"\nElija una opcion: ",
							"Error, no es una opcion valida\n", 1, 10, 3);

	return opc;
}
