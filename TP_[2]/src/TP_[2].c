#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayPassenger.h"

#define CANTIDAD_PASAJEROS 2000
#define LENGH_NAME 50
#define LEN_FLYCODE 50

int main(void) {
	setbuf(stdout, NULL);

	Passenger pasajeros[CANTIDAD_PASAJEROS];
	int opcionMenu;
	int id;
	char name[LENGH_NAME];
	char lastName[LENGH_NAME];
	int price;
	int typePassenger;
	char flycode[LEN_FLYCODE];
	int statusFlight;

	id = 0;
	price = 0;
	typePassenger = 0;
	statusFlight = 0;

	if(initPassengers(pasajeros, CANTIDAD_PASAJEROS) == 0){
		do
			{
			if (utn_getNumero(&opcionMenu,

					"\n*****************************MENU PRINCIPAL*****************************\n\n"
							"1. ALTA \n"
							"2. MODIFICAR \n"
							"3. BAJA\n"
							"4. INFORMAR\n"
							"5. ALTA FORZADA\n"
							"6. SALIR\n"
							"\nElija una opcion: ",

					"\nError opcion invalida", 1, 6, 2) == 0) {
					switch(opcionMenu){
					case 1:
						addPassenger(pasajeros, CANTIDAD_PASAJEROS, id, name, lastName, price, typePassenger, flycode, statusFlight);
						break;
					case 2:
						if(aPassenger(pasajeros, CANTIDAD_PASAJEROS) == 1){
							modifyPassenger(pasajeros, CANTIDAD_PASAJEROS, id);
						} else {
							printf("\nERROR, primero debes cargar al menos un pasajero.\n");
						}

						break;

					case 3:
						if(aPassenger(pasajeros, CANTIDAD_PASAJEROS) == 1){
							removePassenger(pasajeros, CANTIDAD_PASAJEROS, id);
						} else {
							printf("\nERROR, primero debes cargar al menos un pasajero.\n");
						}

						break;
					case 4:
						if(aPassenger(pasajeros, CANTIDAD_PASAJEROS) == 1){
							reportPassenger(pasajeros, CANTIDAD_PASAJEROS);

						} else {
							printf("\nERROR, primero debes cargar al menos un pasajero.\n");
						}

						break;
					case 5:
						printHeader();
						forcedCharge(pasajeros);

						break;
					case 6:
						printf("\nAdios.");
						break;
					}
				}
			}while(opcionMenu != 6);
	}
	return 0;
}

