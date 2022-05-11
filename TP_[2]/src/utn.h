
#ifndef UTN_H_
#define UTN_H_

/// @brief
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/// @brief
/// @param pResultado
/// @param longitud
/// @param mensaje
/// @param mensajeError
/// @param reintentos
/// @return
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

/// @brief
/// @param pResultado
/// @param longitud
/// @param mensaje
/// @param mensajeError
/// @param reintentos
/// @return
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

/// @brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param longitud Es la longitud del array resultado
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param reintentos Cantidad de reintentos
/// @return Retorna 0 si se obtuvo el numero flotante y -1 si no
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
#endif /* UTN_H_ */
