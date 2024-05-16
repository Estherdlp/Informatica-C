/*
 ============================================================================
 Name        : Ejercicio3GrupoX.c
 Author      : Eduardo Sanchez Domingo y Esther del Pico Garcia
 Version     : v1.0
 Copyright   : Your copyright notice
 Description : Ejercicio 3 laboratorio C de informatica
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>																		/*Biblioteca que añade funciones para manipular
																						las cadenas de caracteres*/
#define MAXLINE 1000																	/*Creamos una variable para definir el tamaño de la
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	cadena de caracteres*/

int main(void) {
	char nombreapellidos[2][2][MAXLINE];												/*Declaramos la matriz para el nombre y apellidos de los usuarios*/
	strcpy(nombreapellidos[0][0],"Pepito");												/*Asignamos un valor para cada componente de la matriz*/
	strcpy(nombreapellidos[0][1],"Perez");
	strcpy(nombreapellidos[1][0],"Luisito");
	strcpy(nombreapellidos[1][1],"Rodriguez");
	/*Declaramos una variable para guardar nombre y apellidos introducidos por el usuario*/
	char nombre[MAXLINE], apellido[MAXLINE];
	int i=0, ntarjeta=0,pin=0, comparacionNombre=0,comparacionApellido=0;				/*Declaramos variables*/
	float dineroretirar=0.0, numerotarjeta[2][3]={{12345,123,3400.23},{54321,456,1221.32}};
	printf("Bienvenido al banco.\n");
	printf("Por favor, introduzca su nombre y apellidos\n");							/*Pedimos al usuario que introduzca su nombre y apellidos*/
	scanf ("%s %s", &nombre, &apellido);												/*Se guarda en la primera variable el nombre , y en la segunda el apellido*/
	printf("Buenos dias, %s %s\n",nombre,apellido);
	printf("Por favor, introduzca su codigo pin\n");									/*Pedimos al usuario que introduzca su codigo pin*/
	scanf("%d",&pin);																	/*Se guarda el valor introducido en la variable pin*/
	printf("Por favor, introduzca su numero de tarjeta\n");								/*Pedimos al usuario que introduzca su numero de tarjeta*/
	scanf("%d",&ntarjeta);																/*Se guarda el valor introducido en la variable tarjeta*/
	for (i=0;i<2;i++){																	/*Bucle para la comprobacion de los datos introducidos*/
		comparacionNombre=0;
		comparacionApellido=0;
		comparacionNombre=strcmp(nombreapellidos[i][0],nombre);							/*Comprobamos si el nombre introducido coincide con la base de datos*/
		comparacionApellido=strcmp(nombreapellidos[i][1],apellido);						/*Comprobamos si el apellido introducido coincide con la base de datos*/
		if (comparacionApellido==0 && comparacionNombre==0){							/*Si ambas coinciden, se continua con la ejecucion*/
			if (numerotarjeta[i][0]==ntarjeta){											/*Se comprueba si el numero de tarjeta coincide con el de la base de datos*/
				if (numerotarjeta[i][1]==pin){											/*Se comprueba si el pin introducido coincide con el de la base de datos*/
					printf("Acceso autorizado. Indique la cantidad que desee retirar: \n");	/*Se indica al usuario que cantidad desea retirar si se cumplen las condiciones anteriores*/
					scanf("%f,",&dineroretirar);										/*Guardamos en la variable retirar el numero introducido*/
					if (dineroretirar>numerotarjeta[i][2]){								/*Se comprueba si el usuario dispone del saldo que desea retirar*/
						printf("Error, no dispone de saldo suficiente\n");				/*Se indica al usuario que no dispone de ese dinero*/
						}
					else{																/*Si el usuario dispone de ese dinero*/
						numerotarjeta[i][2]-=dineroretirar;								/*Restamos al total la cuantia retirada*/
						printf("El saldo actual de su tarjeta es: %f\n",numerotarjeta[i][2]);/*Se muestra el nuevo saldo del usuario*/
						}
					break;}}}															/*Finaliza el bucle tras haberse completado la operacion con exito*/
		/*En caso de no cumplirse las condiciones, se impedira el acceso*/
		if((i==1) && ((comparacionApellido!=0) || (comparacionNombre!=0) || (numerotarjeta[i][0]!=ntarjeta) || (numerotarjeta[i][1]!=pin))){
			printf("Acceso no autorizado\n");
			}
	}
	printf("Muchas gracias por su visita\n");
	system("pause");																	/*Pausa para la correcta visualizacion*/
	return 0;
}
