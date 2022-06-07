#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

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

	if(nuevoPasajero != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoVueloStr != NULL && tipoPasajeroStr){
		idStrAux = atoi(idStr);
		tipoPasajeroStrAux = atoi(tipoPasajeroStr);
		precioStrAux = atof(precioStr);
		estadoVueloStrAux = atoi(estadoVueloStr);

		if(Passenger_setId(nuevoPasajero, idStrAux) == -1 ||
			Passenger_setNombre(nuevoPasajero, nombreStr) == -1 ||
			Passenger_setApellido(nuevoPasajero, apellidoStr) == -1 ||
			Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr) == -1 ||
			Passenger_setTipoPasajero(nuevoPasajero, tipoPasajeroStrAux) == -1 ||
			Passenger_setPrecio(nuevoPasajero, precioStrAux) == -1 ||
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
	}

	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre) {

	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strncpy(this->nombre, nombre, 128);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger *this, char *nombre) {

	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strncpy(nombre, this->nombre, 128);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido) {

	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strncpy(this->apellido, apellido, sizeof(this->apellido));
		retorno = 0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger *this, char *apellido) {

	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strncpy(apellido, this->apellido, sizeof(&apellido));
		retorno = 0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {

	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
		strncpy(this->codigoVuelo, codigoVuelo, sizeof(this->codigoVuelo));
		retorno = 0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
		strncpy(codigoVuelo, this->codigoVuelo, sizeof(&codigoVuelo));
		retorno = 0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero) {

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

int Passenger_printPassenger(Passenger* this){

	int retorno = -1;
	if(this != NULL){

	}
	return retorno;
}

//int Passenger_lastId(Passenger* this){
//
//
//}

