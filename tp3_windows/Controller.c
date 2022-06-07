#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){

	FILE* parch;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL){
		if((parch = fopen(path, "r")) != NULL){
			parser_PassengerFromText(parch , pArrayListPassenger);
			printf("Archivo en modo texto cargado correctamente.");
			retorno = 0;
		}
	}
	fclose(parch);

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){

	FILE* parch;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL){
		if((parch = fopen(path, "rb")) != NULL){
			parser_PassengerFromBinary(parch , pArrayListPassenger);
			printf("Archivo en modo binario abierto correctamente.");
			retorno = 0;
		}
	}
	fclose(parch);

	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger){

	//Passenger* nuevoPasajero;

	if(pArrayListPassenger != NULL){

//		if (!utn_getNombre(bufferName, LEN_NAME, "\nIndique el nombre del pasajero: ", "\nERROR, ingrese un nombre valido.\n", 2) &&
//			!utn_getNombre(bufferLastName, LEN_NAME, "\nIndique el apellido del pasajero: ", "\nERROR, ingrese un apellido valido.\n", 2) &&
//			!utn_getNumeroFlotante(&bufferPrice, "\nIndique el precio del pasaje. ($0 - $3000000): $", "ERROR\n", 0, 3000000, 2) &&
//			!utn_getNumero(&bufferTypePassenger, "\n1: Primera clase.\n2: Clase ejecutiva.\n3: Clase premium.\n4: Clase turista.\n\nIndique clase de viaje: ", "ERROR\n", 1, 4, 2) &&
//			!utn_getDescripcion(bufferFlyCode, LEN_CODE, "\nIndique codigo de vuelo. (Hasta 9 caracteres): ", "ERROR\n", 2) &&
//			!utn_getNumero(&bufferStatusFlight, "\n1: ACTIVO.\n2: CANCELADO.\n\nIndique, estado de vuelo: ", "ERROR\n", 1, 2, 2)) {
//			nuevoPasajero = Passenger_newParametros(char *idStr, char *nombreStr, char *apellidoStr, char *precioStr, char *codigoVueloStr, char *tipoPasajeroStr, char *estadoVueloStr);
//		}
//
//								addPassenger(pasajeros, MAX_PASSENGERS, id, bufferName, bufferLastName, bufferPrice, bufferTypePassenger, bufferFlyCode, bufferStatusFlight);

	}

    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){


    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){


    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger){

	int retorno = -1;
	Passenger* nuevoPasajero;
	int id;
	char nombre[128];
	char apellido[128];
	char codigoVuelo[128];
	int tipoPasajero;
	float precio;
	int estadoVuelo;

	if(pArrayListPassenger != NULL){
		printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n\n",-13,"ID",-13, "Nombre", -13, "Apellido", -13, "Precio", -13, "Clase", -13, "Codigo", -13, "Estado");
		for(int i = 0; i < ll_len(pArrayListPassenger); i++){
			nuevoPasajero = (Passenger*) ll_get(pArrayListPassenger, i); //como es puntero a void hay que castear // el get obtiene algo que esta creado en memoria
			Passenger_getId(nuevoPasajero, &id);
			Passenger_getNombre(nuevoPasajero, nombre);
			Passenger_getApellido(nuevoPasajero, apellido);
			Passenger_getPrecio(nuevoPasajero, &precio);
			Passenger_getCodigoVuelo(nuevoPasajero, codigoVuelo);
			Passenger_getTipoPasajero(nuevoPasajero, &tipoPasajero);
			Passenger_getEstadoVuelo(nuevoPasajero, &estadoVuelo);

			printf("|%*d|%*s|%*s|%*.2f|%*s|%*d|%*d|\n", -13, id, -13, nombre, -13, apellido, -13, precio, -13, codigoVuelo, -13, tipoPasajero, -13, estadoVuelo);

			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger){


    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){


    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){


    return 1;
}

