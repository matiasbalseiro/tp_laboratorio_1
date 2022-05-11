#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn.h"

static int increaseId();

static int increaseId(){
    static int id = 3000;
    id++;
    return id;
}


int initPassengers(Passenger *list, int len) {

	int retorno;
	retorno = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight){
	int retorno;
	int indexLibre;
	char bufferName[LEN_NAME];
	char bufferLastName[LEN_NAME];
	float bufferPrice;
	int bufferTypePassenger;
	char bufferFlyCode[LEN_NAME];
	int bufferStatusFlight;
	retorno = -1;
	int flagName;
	int flagLastName;
	int flagPrice;
	int flagTypePassenger;
	int flagFlyCode;
	flagName = 0;
	flagLastName= 0;
	flagPrice= 0;
	flagTypePassenger= 0;
	flagFlyCode = 0;




	if(list != NULL && len > 0 && name != NULL && lastName != NULL && flycode != NULL){
			indexLibre = findIndexByIsEmpty(list, len);
			if(indexLibre != -1){
				if(utn_getNombre(bufferName,LEN_NAME,"\nIndique el nombre del pasajero: ","\nERROR, ingrese un nombre valido.\n",2) == 0){
					strncpy(list[indexLibre].name, bufferName, sizeof(list[indexLibre].name));
					flagName = 1;
				}
				if(flagName == 1){
					if(utn_getNombre(bufferLastName,LEN_NAME,"\nIndique el apellido del pasajero: ","\nERROR, ingrese un apellido valido.\n",2) == 0){
						strncpy(list[indexLibre].lastName, bufferLastName, sizeof(list[indexLibre].lastName));
						flagLastName = 1;
					}
				}
				if(flagLastName == 1){
					if(utn_getNumeroFlotante(&bufferPrice, "\nIndique el precio del pasaje. ($0 - $3000000): $", "ERROR\n", 0, 3000000, 2) == 0){
						list[indexLibre].price = bufferPrice;
						flagPrice = 1;
					}
				}
				if(flagPrice == 1){
					if(utn_getNumero(&bufferTypePassenger, "\n1: Primera clase.\n2: Clase ejecutiva.\n3: Clase premium.\n4: Clase turista.\n\nIndique clase de viaje: ", "ERROR\n", 1, 4, 2) == 0){
					list[indexLibre].typePassenger = bufferTypePassenger;
					flagTypePassenger = 1;
					}
				}
				if(flagTypePassenger == 1){
					if(utn_getDescripcion(bufferFlyCode, LEN_CODE,"\nIndique codigo de vuelo. (Hasta 9 caracteres): ", "ERROR\n", 2) == 0){
					strncpy(list[indexLibre].flycode, bufferFlyCode, sizeof(list[indexLibre].flycode));
					flagFlyCode = 1;
					}
				}
				if(flagFlyCode == 1){
					if(utn_getNumero(&bufferStatusFlight, "\n1: ACTIVO.\n2: DEMORADO.\n\nIndique, estado de vuelo: ", "ERROR\n", 1, 4, 2) == 0){
					list[indexLibre].statusFlight = bufferStatusFlight;
					list[indexLibre].id = increaseId();
					list[indexLibre].isEmpty = 0;
					retorno = 0;
					printHeader();
					printPassenger(list[indexLibre]);

					printf("\nCARGA EXITOSA. SE DIO DE ALTA AL PASAJERO\n");
				}
			}
		}
	}
	return retorno;
}

int findPassengerById(Passenger *list, int len, int id) {
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0 && id > 0 ){
				for(int i = 0; i < len; i++){
					if(list[i].id == id && list[i].isEmpty == 0){
						retorno = i;
						break;
					}
				}
			}
		return retorno;
	}

int removePassenger(Passenger *list, int len, int id) {

	int retorno;
	retorno = -1;
	int index;
	int bufferId;
	int idPassenger;

	if (list != NULL && len > 0) {
		printHeader();
		printPassengers(list, len);
			if(utn_getNumero(&bufferId, "\n\nIndique ID a dar de baja. \n", "ERROR\n", 3000, 7000, 2) == 0){
				idPassenger = bufferId;
		}
		index = findPassengerById(list, len, idPassenger);
		if (index != -1) {
			list[index].isEmpty = 1;
			printf("BAJA EXITOSA. SE HAN GUARDADO LOS CAMBIOS");
			retorno = 0;
		} else {
			printf("ERROR, no se ha encontrado pasajero asociado a ese ID.");
		}
	}
	return retorno;
}

int modifyPassenger(Passenger *list, int len, int id){

	int retorno = -1;
	int index;
	int opcionMenu;
	int bufferId;
	int idPassenger;
	char bufferName[LEN_NAME];
	char bufferLastName[LEN_NAME];
	float bufferPrice;
	int bufferTypePassenger;
	char bufferFlyCode[LEN_NAME];

	if (list != NULL && len > 0) {
		printHeader();
		printPassengers(list, len);
		if (utn_getNumero(&bufferId, "\nIndique ID a modificar. \n", "ERROR\n", 3000, 7000, 2) == 0) {
			idPassenger = bufferId;
		}
		index = findPassengerById(list, len, idPassenger);
		if (index != -1){
			printHeader();
			printPassenger(list[index]);
				do{
					if (utn_getNumero(&opcionMenu,

							"\n*****************************MENU MODIFICAR*****************************\n\n"
									"1. NOMBRE \n"
									"2. APELLIDO \n"
									"3. PRECIO\n"
									"4. TIPO DE PASAJERO\n"
									"5. CODIGO DE VUELO\n"
									"6. REGRESAR AL MENU PRINCIPAL\n"
									"\nElija una opcion: ",

							"\nError opcion invalida", 1, 6, 2) == 0) {
							switch(opcionMenu){
							case 1:
								if(utn_getNombre(bufferName,LEN_NAME,"\nIndique el nombre del pasajero: ","\nERROR, ingrese un nombre valido.\n",2) == 0){
									strncpy(list[index].name, bufferName, sizeof(list[index].name));
									printf("Modificacion realizada.");
								}
								break;
							case 2:
								if(utn_getNombre(bufferLastName,LEN_NAME,"\nIndique el apellido del pasajero: ","\nERROR, ingrese un apellido valido.\n",2) == 0){
									strncpy(list[index].lastName, bufferLastName, sizeof(list[index].lastName));
									printf("Modificacion realizada.");
								}
								break;
							case 3:
								if(utn_getNumeroFlotante(&bufferPrice, "\nIndique el precio del pasaje. ($0 - $3000000): $", "\nERROR, ingrese el precio dentro del rango establecido.\n", 0, 3000000, 2) == 0){
									list[index].price = bufferPrice;
									printf("Modificacion realizada.");
								}
								break;
							case 4:
								if(utn_getNumero(&bufferTypePassenger, "\n1: Primera clase.\n2: Clase ejecutiva.\n3: Clase premium.\n4: Clase turista.\n\nIndique clase de viaje: ", "ERROR, indique clase de viaje.", 1, 4, 2) == 0){
									list[index].typePassenger = bufferTypePassenger;
									printf("Modificacion realizada.");
								}
								break;
							case 5:
								if(utn_getDescripcion(bufferFlyCode, LEN_CODE,"Indique codigo de vuelo. (Hasta 10 caracteres): ", "ERROR, ingrese el codigo dentro del rango establecido.", 2) == 0){
									strncpy(list[index].flycode, bufferFlyCode, sizeof(list[index].flycode));
									printf("Modificacion realizada.");
									printHeader();
									printPassenger(list[index]);
								}
								break;
							case 6:
								printf("Regresando al menu principal...");
								retorno = 0;
								break;
							}
					}
				}while(opcionMenu != 6);
		} else {
			printf("ERROR, no se ha encontrado pasajero asociado a ese ID.");
		}
	}
	return retorno;
}

int sortPassengers(Passenger *list, int len, int order) {

	Passenger bufferLastName;
	int bufferOrder;
	int retorno;
	int i;
	int isOrder;
	retorno = -1;

	if (list != NULL && len > 0) {
		if (utn_getNumero(&bufferOrder, "\n1: Orden ascendente (A - Z) \n2: Orden descendente (Z - A).\n\nIndique orden: \n", "ERROR\n", 1, 2, 2) == 0) {
			order = bufferOrder;
			}

		do {
			isOrder = 1;
			len--;
			for (i = 0; i < len; i++) {
				if (order == 1) {
					if (stricmp(list[i].lastName, list[i + 1].lastName) > 0) {
						bufferLastName = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferLastName;
						isOrder = 0;
					} else if (stricmp(list[i].lastName, list[i + 1].lastName) == 0 && list[i].typePassenger > list[i + 1].typePassenger) {
						bufferLastName = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferLastName;
						isOrder = 0;
					}
				} else {
					if (stricmp(list[i].lastName, list[i + 1].lastName) < 0) {
						bufferLastName = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferLastName;
						isOrder = 0;
					} else if (stricmp(list[i].lastName, list[i + 1].lastName) == 0 && list[i].typePassenger < list[i + 1].typePassenger) {
						bufferLastName = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferLastName;
						isOrder = 0;
					}
				}
			}
		} while (isOrder == 0);
		retorno = 0;
	}
	return retorno;
}

int printPassengers(Passenger *list, int length) {
	int retorno;
	retorno = -1;

	if(list != NULL && length > 0){
		for(int i = 0; i < length; i++){
			printPassenger(list[i]);
		}
		retorno = 0;
	}

return retorno;
}

int sortPassengersByCode(Passenger *list, int len, int order) {
	int retorno;
	retorno = -1;

	Passenger bufferFlyCode;
	int i;
	int bufferOrder;
	int isOrder;
	retorno = -1;

	if (list != NULL && len > 0){
		if (utn_getNumero(&bufferOrder, "\n1: Orden dascendente (A - Z), (1 - 9) \n2: Orden descendente (Z - A), (9 - 1).\n\nIndique orden: \n", "ERROR\n", 1, 2, 2) == 0) {
			order = bufferOrder;
			}

		do {
			isOrder = 1;
			len--;
			for (i = 0; i < len; i++){
				if (isOrder){
					if (stricmp(list[i].flycode, list[i + 1].flycode) < 0){
						bufferFlyCode = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferFlyCode;
						isOrder = 0;
					} else if (stricmp(list[i].flycode, list[i + 1].flycode) == 0 && list[i].typePassenger < list[i + 1].typePassenger){
						bufferFlyCode = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferFlyCode;
						isOrder = 0;
					}
				}else{
					if (stricmp(list[i].flycode, list[i + 1].flycode) > 0){
						bufferFlyCode = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferFlyCode;
						isOrder = 0;
					} else if (stricmp(list[i].flycode, list[i + 1].flycode) == 0 && list[i].typePassenger > list[i + 1].typePassenger){
						bufferFlyCode = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferFlyCode;
						isOrder = 0;
					}
				}
			}
		}while (isOrder == 0);

		return retorno;
	}

return 0;
}

int findIndexById(Passenger *list, int len, int id){

	int retorno = -1;

	if(list != NULL && len > 0 && id > 0 ){
			for(int i = 0; i < len; i++){
				if(list[i].id == id && list[i].isEmpty == 0){
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}

int findIndexByIsEmpty(Passenger *list, int len){

	int retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int aPassenger(Passenger *list, int len) {
	int retorno = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

void printPassenger(Passenger list) {

	if (list.isEmpty == 0) {
		printf("|%*d|%*s|%*s|%*.2f|%*d|%*s|%*d|\n", -13, list.id, -13, list.name, -13, list.lastName, -13, list.price, -13, list.typePassenger, -13, list.flycode, -13, list.statusFlight);
	}
}

void printHeader(){

	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n\n",-13,"ID",-13, "Nombre", -13, "Apellido", -13, "Precio", -13, "Clase", -13, "Codigo", -13, "Estado");
}



int forcedCharge(Passenger *list){
	int retorno = -1;
	int i;
	Passenger passengers[LEN_FORCED_CHARGE] = {{4001, "BART", "SIMPSON", 165000.50, "65QWE4", 3, 1, 0},
												{4002, "MARGE", "BOUVIE", 156000.90, "1D23AS", 2, 2, 0},
												{4003, "NELSON", "MUNTZ", 110000.00, "5E6W4E", 1, 1, 0},
												{4004, "PATTY", "SELMA", 320000.65, "3E12QW", 3, 1, 0},
												{4005, "NED", "FLANDERS", 245000.00, "89WQE7", 1, 2, 0}};

	if(list != NULL){
		for(i = 0; i < 5; i++){
			list[i] = passengers[i];
			list[i].isEmpty = 0;
			retorno = 0;
			printPassenger(list[i]);
		}
	}
	return retorno;
}

int countPassengers(Passenger *list, int len){

	int countPassenger;
	int i;
	countPassenger = 0;

	if(list != NULL && len > 0){
		for(i = 0; i < len; i++){
			if(list[i].isEmpty == 0){
				countPassenger++;
			}
		}
	}
	return countPassenger;
}

float totalPrice(Passenger *list, int len){

	float total;
	int i;

	total = 0;

	if(list != NULL && len > 0){
		for(i = 0; i < len; i++){
			if(list[i].isEmpty == 0){
				total += list[i].price;
			}
		}
	}
	return total;
}

float averagePrice(Passenger *list, int len){

	float average;
	int quantityPassengers;
	float total;

	if(list != NULL && len > 0){
		total = totalPrice(list, len);
		quantityPassengers = countPassengers(list, len);

		average = total / quantityPassengers;
	}
	return average;
}

int exceedAverage(Passenger *list, int len){

	int count;
	float promedio;
	int i;

	count = 0;

	promedio = averagePrice(list, len);

	if(list != NULL && len > 0){
		for(i = 0; i < len; i++){
			if(list[i].isEmpty == 1 && list[i].price > promedio){
				count++;
			}
		}

	}


	return count;
}

int reportPassenger(Passenger *list, int len){

	int retorno = -1;
	int opcionMenu;
	float totalPric;
	float averagePric;
	int exceedAverag;
	int order;
	order = 0;

	if (list != NULL && len > 0) {
				do{
					if (utn_getNumero(&opcionMenu,

							"\n*****************************MENU INFORMAR*****************************\n\n"
									"1. LISTADO DE PASAJEROS POR APELLIDO Y TIPO DE PASAJERO \n"
									"2. TOTAL, PROMEDIO DE PRECIO DE PASAJES Y CUANTOS PASAJEROS SUPERAN EL PROMEDIO \n"
									"3. LISTADO DE PASAJEROS POR CODIGO DE VUELO Y ESTADO DE VUELO 'ACTIVO' \n"
									"4. REGRESAR AL MENU PRINCIPAL\n"

									"\nElija una opcion: ",

							"\ERROR, opcion invalida", 1, 4, 2) == 0) {
							switch(opcionMenu){
							case 1:

								sortPassengers(list, len, order);
								printHeader();
								printPassengers(list, len);

								break;
							case 2:
								totalPric = totalPrice(list, len);
								averagePric = averagePrice(list, len);
								exceedAverag = exceedAverage(list, len);

								printf("\nPrecio total de los pasajes: $%.2f\n", totalPric);
								printf("Promedio de precios de los pasajes: $%.2f\n", averagePric);
								printf("%d pasajeros superan el precio promedio.\n", exceedAverag);

								break;
							case 3:

								printf("ALGO POR HACER");
								break;
							case 4:
								printf("Regresando al menu principal...");
								retorno = 0;
								break;
							}
					}
				}while(opcionMenu != 4);
		} else {
			printf("ERROR, no se ha encontrado pasajero asociado a ese ID.");
		}
	return retorno;
}

