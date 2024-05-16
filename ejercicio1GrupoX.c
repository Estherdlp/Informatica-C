/*
 ============================================================================
 Name        : ejercicio1GrupoX.c
 Author      : Esther del Pico García y Eduardo Sanchez Domingo
 Version     : v1.0, Ejercicio 1
 Copyright   : Libre
 Description : Ejercicio 1 laboratorio 1. Loteria.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	/*Declaracion de variables*/
	int num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0,num10=0;
	float Apuesta=0.0, premio=0.0;
	/*Se pide al usuario que introduzca por pantalla los numeros por los que quiere apostar y la cuantia de la apuesta*/
	printf("Introduzca diez numeros del 0 al 99: \n");
	scanf("%d %d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10);
	/*Se almacenan los valores introducidos en un vector*/
	int introducidos[10]={num1,num2,num3,num4,num5,num6,num7,num8,num9,num10};
	/*Se pide al usuario que introduzca por pantalla el dinero que quiere apostar*/
	printf("Introduzca el valor de la apuesta: ");
	scanf("%f", &Apuesta);
	/*Generar diez numeros aleatorios*/
	int i,j,k, n=10, aleatorio, P=0, U=99;								/*n= numero de numeros aleatorios, P y U el rango de numeros posibles*/
	int generados[10];													/*vector para guardar los numeros aleatorios generados*/
	printf("Los numeros premiados son: ");								/*Muestra los numeros generados aleatoriamente*/
	srand(time(NULL));
	for (i = 0; i < n; i ++){											/*Bucle que genera los numeros aleatorios*/
		aleatorio = P+(int)(((U-P+1.0)*rand())/(RAND_MAX+1.0));
		generados[i] = aleatorio;
		printf("%d ",aleatorio);}
	/*Declaramos una variable donde contar los aciertos*/
	int contadorAciertos=0;
	/*Para cada valor de los numeros generados, se va a comprobar si el usuario ha introducido un numero igual*/
	for (j=0; j < 10; j++){
		for (k = 0; k < 10; k++){
			if (generados[j] == introducidos[k]){
				contadorAciertos++;}									/*Se acumula el numero de aciertos*/
		}
	}
	/*Condiciones para otorgar los premios*/
	if (contadorAciertos>=5){
		premio=contadorAciertos*Apuesta;								/*Si el usuario ha acertado cinco o mas, se muestra por pantalla*/
		printf("\nPrimer premio.\n Usted ha ganado %f euros\n",premio);}
		else if(contadorAciertos>=3)									/*Si el usuario ha acertado tres o cuatro, se muestra por pantalla*/
		{
		premio=contadorAciertos*Apuesta;
			printf("\nSegundo premio.\n Usted ha ganado %f euros\n",premio);}
		else{
			premio=(10-contadorAciertos)*Apuesta;						/*Si el usuario ha acertado dos o menos, se muestra por pantalla*/
			printf("\nUsted ha perdido. Ha acertado un total de %d numeros. Debe abonar %f euros\n",contadorAciertos,premio);}
	system("pause");
	return 0;
}
