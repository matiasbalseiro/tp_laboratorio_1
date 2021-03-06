#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaInputs.h"
#include "calculosFloat.h"

#define DESCUENTO 0.90
#define INTERES 1.25
#define BITCOIN 4800744.71

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int menuPrecios;
	int validacionRetorno;
	int kilometros;
	int flagKm;
	int flagCalculos;
	int flagAerolineas;
	int flagLatam;
	float precioAerolineas;
	float precioLatam;
	float precioTarjetaDebitoAerolineas;
	float precioTarjetaCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioTarjetaDebitoLatam;
	float precioTarjetaCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaDePrecios;

	precioAerolineas = 0;
	precioLatam = 0;
	kilometros = 0;
	flagKm = 0;
	flagCalculos = 0;
	flagAerolineas = 0;
	flagLatam = 0;

	do {
		system("cls");
		printf("1) Ingresar los kilometros: (km=%d)\n", kilometros);
		printf("2) Ingresar Precio de Vuelos: (Aerolineas= $ %.2f, Latam= $ %.2f) \n", precioAerolineas, precioLatam);
		printf("3) Calcular todos los costos \n");
		printf("4) Informar Resultados \n");
		printf("5) Carga forzada de datos \n");
		printf("6) Salir \n\n");

		validacionRetorno = getInt(&opcionMenu, "\nIngrese una opcion: \n", "\nLa opcion es incorrecta\n", 6, 1, 1);

		if (validacionRetorno == 0) {
			if (opcionMenu == 1 || opcionMenu == 5 || opcionMenu == 6 || flagKm == 1) {
				switch (opcionMenu) {
				case 1:
					if(flagAerolineas == 0 && flagLatam == 0){
						validacionRetorno = getInt(&kilometros, "\nIngrese cantidad de Kilometros: (200km - 18000km) \n", "\nError, ingrese los km dentro del rango establecido.\n\n", 18000, 200, 3);
						flagKm = 1;
					} else {
						printf("\nYa ingresaste los datos. Calcula los precios.\n\n");
						system("pause");
					}

					break;
				case 2:
					if(flagKm == 1 && flagAerolineas == 0 && flagLatam == 0){
					do {
						system("cls");
						printf("1) Precio vuelo Aerolineas. ($ %.2f) \n", precioAerolineas);
						printf("2) Precio vuelo Latam. ($ %.2f) \n", precioLatam);
						printf("3) Volver al menu principal. \n");

						validacionRetorno = getInt(&menuPrecios, "\nIngrese una opcion:\n", "La opcion es incorrecta\n", 3, 1, 1);

						if (validacionRetorno == 0) {
								switch (menuPrecios) {
								case 1:
									validacionRetorno = getFloat(&precioAerolineas, "\nIngresar precio de vuelo Aerolineas: ($0 - $ 3M) \n", "\n\nError, ingrese el precio dentro del rango establecido.\n\n", 3000000, 0, 3);
									flagAerolineas = 1;

									break;
								case 2:
									validacionRetorno = getFloat(&precioLatam, "\nIngresar precio de vuelo Latam: ($0 - $ 3M) \n", "\n\nError, ingrese el precio dentro del rango establecido.\n\n", 3000000, 0, 3);
									flagLatam = 1;

									break;
								case 3:
									system("cls");
									printf("\nRegresando al menu principal...\n\n");
									system("pause");

									break;
								}
						} else {
							system("pause");
						}

					} while (menuPrecios != 3);
					} else {
						printf("\nYa ingresaste los datos. Calcula los precios.\n\n");
						system("pause");
					}

					break;

				case 3:
					if (flagKm == 1 && flagAerolineas == 1 && flagLatam == 1) {
						precioTarjetaDebitoAerolineas = utn_multiplicar(precioAerolineas, DESCUENTO);
						precioTarjetaCreditoAerolineas = utn_multiplicar(precioAerolineas, INTERES);
						precioBitcoinAerolineas = utn_dividir(precioAerolineas,BITCOIN);
						precioUnitarioAerolineas = utn_dividir(precioAerolineas,kilometros);
						precioTarjetaDebitoLatam = utn_multiplicar(precioLatam,DESCUENTO);
						precioTarjetaCreditoLatam = utn_multiplicar(precioLatam,INTERES);
						precioBitcoinLatam = utn_dividir(precioLatam, BITCOIN);
						precioUnitarioLatam = utn_dividir(precioLatam,kilometros);
						diferenciaDePrecios = utn_restarConResultadoPositivo(precioLatam, precioAerolineas);

						flagCalculos = 1;

						printf("\nSe realizaron los calculos. Informe los resultados.\n");
						system("pause");
					} else {
						printf("\nDebes cargar los precios de los vuelos. \n\n");
						system("pause");
					}

					break;
				case 4:
					if(flagKm == 1 && flagAerolineas == 1 && flagLatam == 1){
					if (flagCalculos == 1) {
					printf("\nKMs Ingresados: %d\n\n", kilometros);
					printf("Precio Aerolineas: $ %.2f\n", precioAerolineas);
					printf("a) Precio con tarjeta de debito: $ %.2f\n", precioTarjetaDebitoAerolineas);
					printf("b) Precio con tarjeta de credito: $ %.2f\n", precioTarjetaCreditoAerolineas);
					printf("c) Precio pagando con bitcoin: %.8f BTC\n", precioBitcoinAerolineas);
					printf("d) Precio unitario: $ %.2f\n\n", precioUnitarioAerolineas);
					printf("Precio Latam: $ %.2f\n", precioLatam);
					printf("a) Precio con tarjeta de debito: $ %.2f\n", precioTarjetaDebitoLatam);
					printf("b) Precio con tarjeta de credito: $ %.2f\n", precioTarjetaCreditoLatam);
					printf("c) Precio pagando con bitcoin: %.8f BTC\n", precioBitcoinLatam);
					printf("d) Precio unitario: $ %.2f\n\n", precioUnitarioLatam);
					printf("La diferencia de precio es: $ %.2f\n\n", diferenciaDePrecios);
					system("pause");
					} else {
						printf("\nDebes hacer los calculos antes de informarlos.\n\n");
						system("pause");
					}
				} else {
					printf("\nDebes cargar los precios de los vuelos.\n");
					system("pause");
				}

					break;
				case 5:
					kilometros = 7090;
					precioAerolineas = 162965;
					precioLatam = 159339;

					precioTarjetaDebitoAerolineas = utn_multiplicar(precioAerolineas, DESCUENTO);
					precioTarjetaCreditoAerolineas = utn_multiplicar(precioAerolineas, INTERES);
					precioBitcoinAerolineas = utn_dividir(precioAerolineas, BITCOIN);
					precioUnitarioAerolineas = utn_dividir(precioAerolineas, kilometros);
					precioTarjetaDebitoLatam = utn_multiplicar(precioLatam, DESCUENTO);
					precioTarjetaCreditoLatam = utn_multiplicar(precioLatam, INTERES);
					precioBitcoinLatam = utn_dividir(precioLatam, BITCOIN);
					precioUnitarioLatam = utn_dividir(precioLatam, kilometros);
					diferenciaDePrecios = utn_restarConResultadoPositivo(precioLatam, precioAerolineas);

					system("cls");

					printf("KMs Ingresados: %d\n\n", kilometros);
					printf("Precio Aerolineas: $ %.2f\n", precioAerolineas);
					printf("a) Precio con tarjeta de debito: $ %.2f\n", precioTarjetaDebitoAerolineas);
					printf("b) Precio con tarjeta de credito: $ %.2f\n", precioTarjetaCreditoAerolineas);
					printf("c) Precio pagando con bitcoin: %.8f BTC\n", precioBitcoinAerolineas);
					printf("d) Precio unitario: $ %.2f\n\n", precioUnitarioAerolineas);
					printf("Precio Latam: $ %.2f\n", precioLatam);
					printf("a) Precio con tarjeta de debito: $ %.2f\n", precioTarjetaDebitoLatam);
					printf("b) Precio con tarjeta de credito: $ %.2f\n", precioTarjetaCreditoLatam);
					printf("c) Precio pagando con bitcoin: %.8f BTC\n", precioBitcoinLatam);
					printf("d) Precio unitario: $ %.2f\n\n", precioUnitarioLatam);
					printf("La diferencia de precio es: $ %.2f\n\n", diferenciaDePrecios);
					system("pause");

					break;
				case 6:
					printf("\nAdios. \n");
					system("pause");

					break;
				}
			} else {
				system("cls");
				printf("\nError, para empezar, debes ingresar los kilometros.\n\n");
				system("pause");
			}
		}

	} while (opcionMenu != 6);

	return 0;
}

