#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "utn.h"
#define ARCHIVO_TXT "data.csv"
#define ARCHIVO_BIN "data.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main(){
	setbuf(stdout, NULL);

    int opcion;
    char respuesta;
    int flagCarga = 0;
    LinkedList* pArrayListPassenger;

    pArrayListPassenger = ll_newLinkedList();
    do{
    	opcion = menuPrincipal();
        switch(opcion){
            case 1:
            	if(flagCarga == 0){
            		controller_loadFromText(ARCHIVO_TXT,pArrayListPassenger);
            		flagCarga = 1;
            	} else {
            		printf("ERROR, no se puede cargar el archivo dos veces.\n");
            	}
                break;

            case 2:
            	if(flagCarga == 0){
                	controller_loadFromBinary(ARCHIVO_BIN,pArrayListPassenger);
                	flagCarga = 1;
            	} else {
					printf("ERROR, no se puede cargar el archivo dos veces.\n");
				}
            	break;

			case 3:
				controller_addPassenger(pArrayListPassenger);
            	flagCarga = 1;
				break;

			case 4:
				if(flagCarga == 1){
					controller_editPassenger(pArrayListPassenger);

				} else {
					printf("ERROR, primero debes cargar al menos un pasajero.\n");
				}
				break;

			case 5:
				if(flagCarga == 1){
					controller_removePassenger(pArrayListPassenger);

				} else {
					printf("ERROR, primero debes cargar al menos un pasajero.\n");
				}
				break;

			case 6:
				if(flagCarga == 1){
					controller_ListPassenger(pArrayListPassenger);

				} else {
					printf("ERROR, primero debes cargar al menos un pasajero.\n");
				}
				break;

			case 7:
				if(flagCarga == 1){
					controller_sortPassenger(pArrayListPassenger);

				} else {
					printf("ERROR, primero debes cargar al menos un pasajero.\n");
				}
				break;

			case 8:
				if(flagCarga == 1){
					controller_saveAsText(ARCHIVO_TXT , pArrayListPassenger);

				} else {
					printf("ERROR, primero debes cargar al menos un pasajero.\n");
				}
				break;

			case 9:
				if(flagCarga == 1){
					controller_saveAsBinary(ARCHIVO_BIN , pArrayListPassenger);
				} else {
					printf("ERROR, primero debes cargar al menos un pasajero.\n");
				}
				break;

			case 10:
				if(flagCarga == 1){
					utn_getString(&respuesta, "No guardaste ningun cambio.\nEstas seguro que deseas salir del programa? s/n\n", "ERROR\n");
				} else {
					utn_getString(&respuesta, "Estas seguro que deseas salir del programa? s/n\n", "ERROR\n");
				}
				if(respuesta == 's'){
					Passenger_deleteAll(pArrayListPassenger);
					ll_deleteLinkedList(pArrayListPassenger);

					printf("\nAdios\n");
				}
				break;
        }
    }while(respuesta != 's');
    return 0;
}

