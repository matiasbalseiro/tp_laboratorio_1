#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include "menu.h"

Passenger* Passenger_new() {

	Passenger* nuevoPasajero;

	nuevoPasajero = NULL;
	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));

	return nuevoPasajero;
}
Passenger* Passenger_newParametros(char *idStr, char *nombreStr, char *apellidoStr, char *precioStr, char *codigoVueloStr, char *tipoPasajeroStr, char *estadoVueloStr) {

	Passenger *nuevoPasajero;
	int idStrAux;
	float precioStrAux;
	int tipoPasajeroStrAux;
	int estadoVueloStrAux;

	nuevoPasajero = NULL;
	nuevoPasajero = Passenger_new(); // reservo espacio para pasajero

	if(nuevoPasajero != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoVueloStr != NULL && tipoPasajeroStr && estadoVueloStr != NULL){
		idStrAux = atoi(idStr);
		tipoPasajeroStrAux = Passenger_traductorTipoVueloChar(tipoPasajeroStr);
		precioStrAux = atof(precioStr);
		estadoVueloStrAux = Passenger_traductorEstadoVueloChar(estadoVueloStr);

		if(Passenger_setId(nuevoPasajero, idStrAux) == -1 || Passenger_setNombre(nuevoPasajero, nombreStr) == -1 ||
			Passenger_setApellido(nuevoPasajero, apellidoStr) == -1 || Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr) == -1 ||
			Passenger_setTipoPasajero(nuevoPasajero, tipoPasajeroStrAux) == -1 || Passenger_setPrecio(nuevoPasajero, precioStrAux) == -1 ||
			Passenger_setEstadoVuelo(nuevoPasajero, estadoVueloStrAux) == -1){
			Passenger_delete(nuevoPasajero);
		}
	}
	return nuevoPasajero;
}
void Passenger_delete(Passenger *this) {

	if(this != NULL){
		free(this);
		this = NULL;
	}
}

int Passenger_setId(Passenger *this, int id) {

	int retorno = -1;

	if(this != NULL && id >= 0){
		this->id = id; // inserto datos a la estructura
		retorno = 0;
	}

	return retorno;
}
int Passenger_getId(Passenger *this, int *id) {

	int retorno = -1;

	if(this != NULL && id >= 0){
		*id = this->id; // obtengo el dato de la estructura
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre) {

	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger *this, char *nombre) {

	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido) {

	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger *this, char *apellido) {

	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {

	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero) {

	int retorno = -1;

	if(this != NULL && tipoPasajero >= 0){
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {

	int retorno = -1;

	if(this != NULL && tipoPasajero >= 0){
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger *this, float precio) {

	int retorno = -1;

	if(this != NULL && precio >= 0){
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger *this, float *precio) {

	int retorno = -1;

	if(this != NULL && precio >= 0){
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo){
	int retorno = -1;

	if(this != NULL && estadoVuelo >= 0){
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}

		return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo){
	int retorno = -1;

	if(this != NULL && estadoVuelo >= 0){

		*estadoVuelo = this->estadoVuelo;
		retorno = 0;
	}

	return retorno;
}

int Passenger_lastId(LinkedList* pArrayListPassenger){

	Passenger* unPasajero;
	int auxId;
	int lastId = 0;
	int flag = 0;

	if(pArrayListPassenger != NULL){
		for(int i = 0; i < ll_len(pArrayListPassenger); i++){
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(unPasajero, &auxId);
			if(auxId > lastId || flag == 0){
				lastId = auxId;
				flag = 1;
			}
		}
	}
	return lastId;
}

int Passenger_printPassenger(LinkedList* pArrayListPassenger, int index){

	int retorno = -1;
	int id;
	char nombre[128];
	char apellido[128];
	float precio;
	char codigoVuelo[128];
	int tipoPasajero;
	int estadoVuelo;
	Passenger* unPasajero;

	if(pArrayListPassenger != NULL){
		unPasajero = (Passenger*)ll_get(pArrayListPassenger, index);
		Passenger_getId(unPasajero, &id);
		Passenger_getNombre(unPasajero, nombre);
		Passenger_getApellido(unPasajero, apellido);
		Passenger_getPrecio(unPasajero, &precio);
		Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
		Passenger_getTipoPasajero(unPasajero, &tipoPasajero);
		Passenger_getEstadoVuelo(unPasajero, &estadoVuelo);

		printf("|%*d|%*s|%*s|%*.2f|%*s|%*d|%*d|\n", -13, id, -13, nombre, -13, apellido, -13, precio, -13, codigoVuelo, -13, tipoPasajero, -13, estadoVuelo);

		retorno = 0;
	}
	return retorno;
}

void printHeader(){

	printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",-13,"ID",-13, "Nombre", -13, "Apellido", -13, "Precio", -13, "Codigo", -13, "Clase", -13, "Estado");
	printf("+-------------+-------------+-------------+-------------+-------------+-------------+-------------+\n");

}

int Passenger_edit(LinkedList* pArrayListPassenger){

	int retorno = -1;
	int auxId;
	int lastId;
	int index;
	char auxNombre[128];
	char auxApellido[128];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[128];
	int auxEstadoVuelo;
	int opcion;
	Passenger *unPasajero = NULL;

	lastId = Passenger_lastId(pArrayListPassenger);

	if (pArrayListPassenger != NULL) {
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumero(&auxId, "\n\nIndique ID a modificar. \n", "ERROR\n", 1, lastId, 2);
		index = controller_findPassengerById(pArrayListPassenger, auxId);
		if (index != -1) {
			printHeader();
			Passenger_printPassenger(pArrayListPassenger, index);
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, index);
			do {
				opcion = menuModificar();
				switch (opcion) {
				case 1:
					if (!utn_getNombre(auxNombre, 128, "\nIndique el nombre del pasajero: ", "\nERROR, ingrese un nombre valido.\n", 2)) {
						Passenger_setNombre(unPasajero, auxNombre);
						printf("SE HA MODIFICADO EL NOMBRE\n");
					}
					break;
				case 2:
					if (!utn_getNombre(auxApellido, 128, "\nIndique el apellido del pasajero: ", "\nERROR, ingrese un apellido valido.\n", 2)) {
						Passenger_setApellido(unPasajero, auxApellido);
						printf("SE HA MODIFICADO EL APELLIDO\n");
					}
					break;
				case 3:
					if (!utn_getNumeroFlotante(&auxPrecio, "\nIndique el precio del pasaje. ($0 - $3000000): $", "\nERROR, ingrese el precio dentro del rango establecido.\n", 0, 3000000, 2)) {
						Passenger_setPrecio(unPasajero, auxPrecio);
						printf("SE HA MODIFICADO EL PRECIO\n");
					}
					break;
				case 4:
					if (!utn_getNumero(&auxTipoPasajero, "\n1: FirstClass.\n2: EconomyClass.\n3: ExecutiveClass.\n\nIndique clase de viaje: ", "ERROR\n", 1, 3, 2)) {
						Passenger_setTipoPasajero(unPasajero, auxTipoPasajero);
						printf("SE HA MODIFICADO EL TIPO DE PASAJERO\n");
					}
					break;
				case 5:
					if (!utn_getDescripcion(auxCodigoVuelo, 128, "Indique codigo de vuelo. (Hasta 9 caracteres): ", "ERROR, ingrese el codigo dentro del rango establecido.", 2)) {
						Passenger_setCodigoVuelo(unPasajero, auxCodigoVuelo);
						printf("SE HA MODIFICADO EL CODIGO DE VUELO\n");
					}
					break;
				case 6:
					if (!utn_getNumero(&auxEstadoVuelo, "\n1: Aterrizado.\n2: En Horario.\n3: En Vuelo.\n4: Demorado.\n\nIndique, estado de vuelo: ", "ERROR\n", 1, 4, 2)) {
						Passenger_setEstadoVuelo(unPasajero, auxEstadoVuelo);
						printf("SE HA MODIFICADO EL ESTADO DE VUELO\n");
					}
					break;
				case 7:
					printf("Regresando al menu principal...\n");
					retorno = 0;
					break;
				}
			} while (opcion != 7);
		}
	}
	return retorno;
}

int Passenger_sort(LinkedList* pArrayListPassenger){

	int retorno = -1;
	int opcion;
	int orden;

	if(pArrayListPassenger != NULL){
		do{
			opcion = menuOrdenar();
			switch(opcion){
				case 1:
					if(!utn_getNumero(&orden, "\n0: Ascendente.\n1: Descendente.\n\nIndique clase de viaje: ", "ERROR\n", 0, 1, 2)){
						printf("Ordenando, espere unos segundos...");
						ll_sort(pArrayListPassenger, Passenger_sortById, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;
				case 2:
					if(!utn_getNumero(&orden, "\n0: Ascendente.\n1: Descendente.\n\nIndique clase de viaje: ", "ERROR\n", 0, 1, 2)){
						printf("Ordenando, espere unos segundos...");
						ll_sort(pArrayListPassenger, Passenger_sortByName, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;
				case 3:
					if(!utn_getNumero(&orden, "\n0: Ascendente.\n1: Descendente.\n\nIndique clase de viaje: ", "ERROR\n", 0, 1, 2)){
						printf("Ordenando, espere unos segundos...");
						ll_sort(pArrayListPassenger, Passenger_sortByLastName, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;
				case 4:
					if(!utn_getNumero(&orden, "\n0: Ascendente.\n1: Descendente.\n\nIndique clase de viaje: ", "ERROR\n", 0, 1, 2)){
						printf("Ordenando, espere unos segundos...");
						ll_sort(pArrayListPassenger, Passenger_sortByPrice, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;
				case 5:
					if(!utn_getNumero(&orden, "\n0: Ascendente.\n1: Descendente.\n\nIndique clase de viaje: ", "ERROR\n", 0, 1, 2)){
						printf("Ordenando, espere unos segundos...");
						ll_sort(pArrayListPassenger, Passenger_sortTypePassenger, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;
				case 6:
					if(!utn_getNumero(&orden, "\n0: Ascendente.\n1: Descendente.\n\nIndique clase de viaje: ", "ERROR\n", 0, 1, 2)){
						printf("Ordenando, espere unos segundos...");
						ll_sort(pArrayListPassenger, Passenger_sortFlyCode, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;
				case 7:
					if(!utn_getNumero(&orden, "\n0: Ascendente.\n1: Descendente.\n\nIndique clase de viaje: ", "ERROR\n", 0, 1, 2)){
						printf("Ordenando, espere unos segundos...");
						ll_sort(pArrayListPassenger, Passenger_sortTypePassenger, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;
				case 8:
					printf("Regresando al menu principal...\n");
					retorno = 0;
					break;
				}
			}while(opcion != 8);
		}
	return retorno;
}

int Passenger_sortById(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pasajeroUno = NULL;
	Passenger* pasajeroDos = NULL;
	int idUno;
	int idDos;

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		Passenger_getId(pasajeroUno, &idUno);
		Passenger_getId(pasajeroDos, &idDos);
		if(idUno > idDos){
			retorno = 1;
		}
		else if(idUno < idDos){
			retorno = -1;
		}
	}

	return retorno;
}

int Passenger_sortByName(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pasajeroUno = NULL;
	Passenger* pasajeroDos = NULL;
	char nombreUno[128];
	char nombreDos[128];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		Passenger_getNombre(pasajeroUno, nombreUno);
		Passenger_getNombre(pasajeroDos, nombreDos);
		if(strcmp(nombreUno, nombreDos) > 0){
			retorno = 1;
		}
		else if(strcmp(nombreUno, nombreDos) < 0){
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_sortByLastName(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pasajeroUno = NULL;
	Passenger* pasajeroDos = NULL;
	char apellidoUno[128];
	char apellidoDos[128];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		Passenger_getApellido(pasajeroUno, apellidoUno);
		Passenger_getApellido(pasajeroDos, apellidoDos);
		if(strcmp(apellidoUno, apellidoDos) > 0){
			retorno = 1;
		}
		else if(strcmp(apellidoUno, apellidoDos) < 0){
			retorno = -1;
		}
	}

	return retorno;
}

int Passenger_sortByPrice(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pasajeroUno = NULL;
	Passenger* pasajeroDos = NULL;
	float precioUno;
	float precioDos;

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		Passenger_getPrecio(pasajeroUno, &precioUno);
		Passenger_getPrecio(pasajeroDos, &precioDos);
		if(precioUno > precioDos){
			retorno = 1;
		}
		else if(precioUno < precioDos){
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_sortFlyCode(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pasajeroUno = NULL;
	Passenger* pasajeroDos = NULL;
	char codigoVueloUno[128];
	char codigoVueloDos[128];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		Passenger_getCodigoVuelo(pasajeroUno, codigoVueloUno);
		Passenger_getCodigoVuelo(pasajeroDos, codigoVueloDos);
		if(strcmp(codigoVueloUno, codigoVueloDos) > 0){
			retorno = 1;
		}
		else if(strcmp(codigoVueloUno, codigoVueloDos) < 0){
			retorno = -1;
		}
	}

	return retorno;
}

int Passenger_sortTypePassenger(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pasajeroUno = NULL;
	Passenger* pasajeroDos = NULL;
	int tipoPasajeroUno;
	int tipoPasajeroDos;

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		Passenger_getTipoPasajero(pasajeroUno, &tipoPasajeroUno);
		Passenger_getTipoPasajero(pasajeroDos, &tipoPasajeroDos);
		if(tipoPasajeroUno > tipoPasajeroDos){
			retorno = 1;
		}
		else if(tipoPasajeroUno < tipoPasajeroDos){
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_sortStatusFlight(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pasajeroUno = NULL;
	Passenger* pasajeroDos = NULL;
	int estadoVueloUno;
	int estadoVueloDos;

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		Passenger_getEstadoVuelo(pasajeroUno, &estadoVueloUno);
		Passenger_getEstadoVuelo(pasajeroDos, &estadoVueloDos);
		if(estadoVueloUno > estadoVueloDos){
			retorno = 1;
		}
		else if(estadoVueloUno < estadoVueloDos){
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_traductorTipoVueloChar(char* tipoPasajero){

	int auxTipoPasajero;

	if(!stricmp(tipoPasajero, "FirstClass")){
		auxTipoPasajero = 1;
	}
	else if(!stricmp(tipoPasajero, "EconomyClass")){
		auxTipoPasajero = 2;
	}
	else if(!stricmp(tipoPasajero, "ExecutiveClass")){
		auxTipoPasajero = 3;
	}

	return auxTipoPasajero;
}
int Passenger_traductorEstadoVueloChar(char* estadoVuelo){
	int auxestadoVuelo;

	if(!stricmp(estadoVuelo, "Aterrizado")){
		auxestadoVuelo = 1;
	}
	else if(!stricmp(estadoVuelo, "En Horario")){
		auxestadoVuelo = 2;
	}
	else if(!stricmp(estadoVuelo, "En Vuelo")){
		auxestadoVuelo = 3;
	}
	else if(!stricmp(estadoVuelo, "Demorado")){
		auxestadoVuelo = 4;
	}

	return auxestadoVuelo;

}


