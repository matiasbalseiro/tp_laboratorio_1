
#ifndef UTN_H_
#define UTN_H_


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getFechaDeNacimiento(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_isLetter(char* pResultado);
int utn_getString(char* pResultado, char* mensaje, char* mensajeError);
#endif /* UTN_H_ */
