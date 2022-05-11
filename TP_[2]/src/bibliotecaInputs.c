#include "bibliotecaInputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError, int maximo, int minimo, int maximoDeReintentos){
//
//	int auxNumeroIngresado;
//	int retorno;
//	retorno = -1;
//
//	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
//		do{
//			printf("%s", mensaje);
//			scanf("%d", &auxNumeroIngresado);
//			maximoDeReintentos--;
//
//			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
//						*pNumeroIngresado = auxNumeroIngresado;
//						retorno = 0;
//						break;
//			}else{
//				printf("%s", mensajeError);
//			}
//
//		}while(maximoDeReintentos > 0);
//	}
//
//	return retorno;
//}

int getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError,
		float maximo, float minimo, int maximoDeReintentos){

	float auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}

/// @brief Verifica si la cadena ingresada es numerica.
///
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 (VERDADERO) si la cadena es numerica y 0 (FALSO) si no lo es
int esNumerica(char* cadena, int len){

	int retorno = -1; // ERROR
	int i;

	if(cadena != NULL && len > 0){
		retorno = 1; // VERDADERO
		for(i=0;i<len && cadena[i] != '\0';i++){
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9'){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// @brief Obtiene un numero entero
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
int getInt(int* pResultado){

	 int retorno=-1;
	    char bufferString[50];

	    if(	pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString))){
			retorno=0;
			*pResultado = atoi(bufferString) ;

		}
	    return retorno;
	}
	//char bufferString[4096];

//	bufferInt = pResultado;

//	do {
//		if (bufferInt <= 5 && bufferInt >= 1) {
//			retorno = 0;
//			*pResultado = bufferInt;
//			break;
//		} else {
//			printf("te equivocaste");
//		}
//	} while (bufferInt > 5 || bufferInt < 1);




//	if (pResultado != NULL) {
//		if(myGets(bufferString, sizeof(bufferString) == 0) && esNumerica(bufferString, sizeof(bufferString)) == 0) {
//			retorno = 0;
//			*pResultado = atoi(bufferString);
//		}
//	}


//	return retorno;
//}

/// @brief Recibe una cadena y no se pasa del largo
///
/// @param cadena Cadena de caracteres a ser analizada
/// @param len Largo de la cadena
/// @return
int myGets(char* cadena, int len){

	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && len > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len){
				strncpy(cadena,bufferString,len);
				retorno=0;
			}
		}
	}

	return retorno;
}
/// @brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param maximo Es el numero maximo a ser aceptado
/// @param minimo Es el numero minimo a ser aceptado
/// @param reintentos Reintentos
/// @return Retorna 0 si se obtuvo el numero y -1 si no
//int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int maximo, int minimo, int reintentos){
//
//	int retorno = -1;
//	int bufferInt;
//
//	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){
//		do {
//			printf("%s", mensaje);
//			if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo) {
//				retorno = 0;
//				*pResultado = bufferInt;
//				break;
//			}
//			printf("%s", mensajeError);
//			reintentos--;
//		} while (reintentos >= 0);
//	}
//
//return retorno;
//}


