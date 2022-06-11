#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
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
    int flagTxt = 0;
    int flagBin = 0;
    int flagAdd = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	opcion = menuPrincipal();
        switch(opcion){
            case 1:
                controller_loadFromText(ARCHIVO_TXT,listaPasajeros);
                flagTxt = 1;
                break;

            case 2:
            	controller_loadFromBinary(ARCHIVO_BIN,listaPasajeros);
            	flagBin = 1;
            	break;

			case 3:
				controller_addPassenger(listaPasajeros);
				flagAdd = 1;
				break;

			case 4:
				if(flagTxt == 1 || flagBin == 1 || flagAdd == 1){

				}
				controller_editPassenger(listaPasajeros);
				break;

			case 5:
				if(flagTxt == 1 || flagBin == 1 || flagAdd == 1){

				}
				controller_removePassenger(listaPasajeros);
				break;

			case 6:
				if(flagTxt == 1 || flagBin == 1 || flagAdd == 1){

				}
				controller_ListPassenger(listaPasajeros);
				break;

			case 7:
				if(flagTxt == 1 || flagBin == 1 || flagAdd == 1){

				}
				controller_sortPassenger(listaPasajeros);
				break;

			case 8:
				if(flagTxt == 1 || flagBin == 1 || flagAdd == 1){

				}
				controller_saveAsText(ARCHIVO_TXT , listaPasajeros);
				break;

			case 9:
				if(flagTxt == 1 || flagBin == 1 || flagAdd == 1){

				}
				controller_saveAsBinary(ARCHIVO_BIN , listaPasajeros);
				break;
        }
    }while(opcion != 10);
    return 0;
}

