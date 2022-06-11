#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "menu.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){

	FILE* parch = NULL;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL){
		parch = fopen(path, "r");
		if(parch != NULL){
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

	FILE* parch = NULL;
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

	int retorno = 0;
	Passenger* auxPasajero = NULL;
	char auxNombre[128];
	char auxApellido[128];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[128];
	int auxEstadoVuelo;
	int nextId;


	if(pArrayListPassenger != NULL){
		if (!utn_getNombre(auxNombre, 128, "\nIndique el nombre del pasajero: ", "\nERROR, ingrese un nombre valido.\n", 2) &&
			!utn_getNombre(auxApellido, 128, "\nIndique el apellido del pasajero: ", "\nERROR, ingrese un apellido valido.\n", 2) &&
			!utn_getNumeroFlotante(&auxPrecio, "\nIndique el precio del pasaje. ($0 - $3000000): $", "ERROR\n", 0, 3000000, 2) &&
			!utn_getNumero(&auxTipoPasajero, "\n1: FirstClass.\n2: EconomyClass.\n3: ExecutiveClass.\n\nIndique clase de viaje: ", "ERROR\n", 1, 3, 2) &&
			!utn_getDescripcion(auxCodigoVuelo, 128, "\nIndique codigo de vuelo. (Hasta 9 caracteres): ", "ERROR\n", 2) &&
			!utn_getNumero(&auxEstadoVuelo, "\n1: Aterrizado.\n2: En Horario.\n3: En Vuelo.\n4: Demorado.\n\nIndique, estado de vuelo: ", "ERROR\n", 1, 4, 2)) {
			auxPasajero = Passenger_new();
			nextId = Passenger_lastId(pArrayListPassenger) + 1;
			Passenger_setId(auxPasajero, nextId);
			Passenger_setNombre(auxPasajero, auxApellido);
			Passenger_setApellido(auxPasajero, auxNombre);
			Passenger_setPrecio(auxPasajero, auxPrecio);
			Passenger_setTipoPasajero(auxPasajero, auxTipoPasajero);
			Passenger_setCodigoVuelo(auxPasajero, auxCodigoVuelo);
			Passenger_setEstadoVuelo(auxPasajero, auxEstadoVuelo);
			ll_add(pArrayListPassenger, auxPasajero);
			printf("\nCARGA EXITOSA. SE DIO DE ALTA AL PASAJERO\n");
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){

	int retorno = -1;

	if(pArrayListPassenger != NULL){
		Passenger_edit(pArrayListPassenger);
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){

	int retorno = -1;
	Passenger* auxPasajero = NULL;
	int auxId;
	int lastId;
	int index;
	char respuesta;

	lastId = Passenger_lastId(pArrayListPassenger);

	if(pArrayListPassenger != NULL){
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumero(&auxId, "\n\nIndique ID a dar de baja. \n", "ERROR\n", 1, lastId, 2);
		index = controller_findPassengerById(pArrayListPassenger, auxId);
		if(index != -1){
			printHeader();
			Passenger_printPassenger(pArrayListPassenger, index);
			auxPasajero = (Passenger*)ll_get(pArrayListPassenger, index);
			utn_getString(&respuesta, "\nDesea remover ese pasajero? s/n \n", "ERROR\n");
			if(respuesta == 's'){
				ll_remove(pArrayListPassenger, index);
				Passenger_delete(auxPasajero);
				printf("\nBAJA EXITOSA. SE HAN GUARDADO LOS CAMBIOS\n");
				retorno = 0;
			}
		} else {
			printf("ERROR, no se ha encontrado pasajero asociado a ese ID.\n");

		}
	}
    return retorno;
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
	Passenger* auxPasajero = NULL;
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
			auxPasajero = (Passenger*)ll_get(pArrayListPassenger, i); //como es puntero a void hay que castear // el get obtiene algo que esta creado en memoria
			Passenger_getId(auxPasajero, &id);
			Passenger_getNombre(auxPasajero, nombre);
			Passenger_getApellido(auxPasajero, apellido);
			Passenger_getPrecio(auxPasajero, &precio);
			Passenger_getCodigoVuelo(auxPasajero, codigoVuelo);
			Passenger_getTipoPasajero(auxPasajero, &tipoPasajero);
			Passenger_getEstadoVuelo(auxPasajero, &estadoVuelo);

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

	int retorno = -1;

	if(pArrayListPassenger != NULL){
		Passenger_sort(pArrayListPassenger);
		retorno = 0;
	}
	return retorno;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){

	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL){

	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return inT
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){

	int retorno = -1;
	Passenger* auxPasajero = NULL;
	FILE* parch = NULL;

	if(path != NULL && pArrayListPassenger != NULL){
		parch = fopen(path, "wb");
		if(parch != NULL){
			for(int i = 0; i < ll_len(pArrayListPassenger); i++){
				auxPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
				fwrite(auxPasajero, sizeof(Passenger), 1, parch);
				retorno = 0;
			}
			printf("\nArchivo en modo binario guardado correctamente.\n");
		}
	}
    return retorno;
}

int controller_findPassengerById(LinkedList* pArrayListPassenger, int idBuscado){

	int retorno = -1;
	int idAux;
	int len = ll_len(pArrayListPassenger);
	Passenger* unPasajero = NULL;

	if(pArrayListPassenger != NULL && idBuscado >= 0){
			for(int i = 0; i < len; i++){
				unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
				if(!Passenger_getId(unPasajero, &idAux) && idAux == idBuscado){
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}

