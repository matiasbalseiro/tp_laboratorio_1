#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){

	int retorno = -1;
	Passenger* nuevoPasajero;
	char id[128];
	char nombre[128];
	char apellido[128];
	char precio[128];
	char codigoVuelo[128];
	char tipoPasajero[128];
	char estadoVuelo[128];

	if(pFile != NULL && pArrayListPassenger != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo) == 7){
				nuevoPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
				if(nuevoPasajero != NULL){
					ll_add(pArrayListPassenger, nuevoPasajero);
					retorno = 0;
				}
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){

	int retorno = 0;

	if(pFile != NULL && pArrayListPassenger != NULL){

	}

    return retorno;
}
