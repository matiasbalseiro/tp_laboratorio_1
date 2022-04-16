#include "calculosFloat.h"
#include <stdio.h>
#include <stdlib.h>


float utn_multiplicar(float numeroUno, float numeroDos) {

	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}


float utn_dividir(float numeroUno, float numeroDos) {

	float resultado;

	if(numeroDos != 0){
	resultado = numeroUno / numeroDos;
	}

	return resultado;
}


float utn_restarConResultadoPositivo(float numeroUno, float numeroDos) {

	float resultado;

	if (numeroUno > numeroDos) {
		resultado = numeroUno - numeroDos;
	} else {
		resultado = numeroDos - numeroUno;
	}

	return resultado;
}


float utn_sumar(float numeroUno, float numeroDos){

	float resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}


