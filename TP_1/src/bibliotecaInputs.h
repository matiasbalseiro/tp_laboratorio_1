#ifndef BIBLIOTECA_INPUTS_H_
#define BIBLIOTECA_INPUTS_H_

/// @brief Solicita un número al usuario y lo valida
/// @param pNumeroIngresado - Se carga el numero ingresado
/// @param mensaje - Es el mensaje a ser mostrado
/// @param mensajeError - Es el mensaje a ser mostrado en caso de error
/// @param maximo - Limite superior a validar
/// @param minimo - Limite inferior a validar
/// @param maximoDeReintentos - Numero de intentos en caso de error
/// @return - Si obtuvo el numero [0] si no [-1]

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo, int minimo, int maximoDeReintentos);

/// @brief Solicita un número al usuario y lo valida
/// @param pNumeroIngresado - Se carga el numero ingresado
/// @param mensaje - Es el mensaje a ser mostrado
/// @param mensajeError - Es el mensaje a ser mostrado en caso de error
/// @param maximo - Limite superior a validar
/// @param minimo - Limite inferior a validar
/// @param maximoDeReintentos - Numero de intentos en caso de error
/// @return - Si obtuvo el numero [0] si no [-1]

int getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError, float maximo, float minimo, int maximoDeReintentos);

#endif
