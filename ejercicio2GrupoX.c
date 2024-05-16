/*
 ============================================================================
 Name        : ejercicio2GrupoX.c
 Author      : Eduardo Sanchez Domingo y Esther del Pico Garcia
 Version     : v1.0
 Copyright   : Your copyright notice
 Description : Ejercicio 2 laboratorio C de informatica
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Numero de veces que se repiten los procesos en el programa*/
int n=10;

void PedirBoleto (int* boleto, int* FalloNum, float* apuesta){							/*Funcion PedirBoleto*/
	int i,j,k; 																			/*Declaramos variables*/
	for(i=0;i<n;i++){
		printf("Euromillon: introduzca el numero que desee agregar al boleto: \n");		/*Pedimos al usuario que introduzca los numeros de su boleto*/
		scanf("%d",&boleto[i]);
		for (j=0;j<i;j++){																/*Si el usuario repite numero, le saltará error*/
			if(boleto[j]==boleto[i]){
				*FalloNum=2;}}
		if (boleto[i]>50 || boleto[i]<0){												/*Si el usuario introduce un numero fuera del rango, se finalizará la ejecución*/
			*FalloNum=1;}
		if (*FalloNum!=0){
			break;}
		}
	if (*FalloNum==1){
		printf("Error. Los numeros introducidos deben valer de 0 a 50\n");				/*Se visualiza por pantalla el primer tipo de error cometido por el usuario*/
		system("pause");
		exit(-1);}																		/*Se finalizara la ejecucion del programa tras mostrar el error*/
	if (*FalloNum==2){
		printf("Error. No pueden introducirse dos numeros iguales\n");					/*Se visualiza por pantalla el segundo tipo de error cometido por el usuario*/
		system("pause");
		exit(-1);}																		/*Se finalizara la ejecucion del programa tras mostrar el error*/
	/*Se muestran por pantalla los numeros escogidos*/
	printf("Sus numeros son: ");
	for (k=0;k<n;k++){
		printf("%d ",boleto[k]);}
	printf("\nIntroduzca el dinero que desee apostar: \n");								/*Imprimimos por pantalla el dinero apostado*/
	scanf("%f", apuesta);
	}
void GenerarBoletoSistema (int* BoletoSistema){											/*Funcion GenerarBoletoSistema*/
	int i,j,aleatorio=0,numerosvalidos=0,repetido, P=0, U=50;							/*Declaramos variables*/
	srand(time(NULL));
	do{
		aleatorio = P+(int)(((U-P+1.0)*rand())/(RAND_MAX+1.0));							/*Se genera un numero aleatorio para el boleto*/
		repetido=0;
		for (i=0;i<n;i++){
			if (BoletoSistema[i]==aleatorio){											/*Se comprueba si el numero ya ha salido, en caso afirmativo, se repetira la ejecucion*/
				repetido=1;}
		}
		if (repetido==0){																/*En caso de no haber ningun repetido,se suma 1 a la condicion de ejecucion*/
			BoletoSistema[numerosvalidos]=aleatorio;
			numerosvalidos++;}
	} while (numerosvalidos<9);															/*Condicion para la ejecucion hasta la creacion de 10 numeros no repetidos*/
	printf("\nLos numeros premiados son: ");											/*Muestra los numeros generados aleatoriamente*/
			for (j=0;j<n;j++){
					printf("%d ",BoletoSistema[j]);}
}
int ComprobarPremio (int* boleto, int* BoletoSistema, int* devolver, int* contador){	/*Funcion ComprobarPremio*/
	int i,j;
	for (i=0; i<n; i++){																/*Se comprueba si los numeros coinciden*/
		for (j=0;j<n;j++){
			if (BoletoSistema[i]==boleto[j]){
				*contador+=1;}}}
	if (*contador>=5){																	/*Corresponde al caso de ganar el primer premio*/
		*devolver=1;}
	else if (*contador==3 || *contador ==4){											/*Corresponde al caso de ganar el segundo premio*/
		*devolver=2;}
	else if (*contador<3){																/*Corresponde al caso de acertar menos de 3*/
		*devolver=0;}
	return (*devolver);																	/*Se devuelve el resultado*/
}
float DineroPremio (float* apuesta,float* premio,int* devolver,int* contador){			/*Funcion DineroPremio*/
	/*Operaciones para el calculo de los distintos premios*/
	if (*devolver==1){																	/*Corresponde al caso de ganar el primer premio*/
	*premio=*apuesta*(*contador);}
		else if (*devolver==2){															/*Corresponde al caso de ganar el segundo premio*/
			*premio=*apuesta*(*contador);
		}
		else if (*devolver==0){															/*Corresponde al caso de acertar menos de 3*/
			*premio=*apuesta*(-10+(*contador));
		}
	/*Se visualiza por pantalla el balance de la apuesta*/
	if (*devolver==1){																	/*Felicitacion si gana el primer premio, indicando los aciertos*/
		printf("\nHa ganado el primer premio, con un total de %d aciertos\n",*contador);}
	else if (*devolver==2){																/*Felicitacion si gana el segundo premio, indicando los aciertos*/
		printf("\nHa ganado el segundo premio, con un total de %d aciertos\n",*contador);}
	else if (*devolver==0){																/*Mensaje visualizado si pierde*/
		printf("\nNo ha ganado ningun premio. Ha acertado un total de %d numeros\n",*contador);}
	if (*premio>0){
		printf("\nFelicidades, ha ganado %f euros\n",*premio);}							/*Dinero visualizado si gana*/
		else{
			printf("\nLamentablemente, ha perdido %f euros\n",*premio);					/*Dinero visualizado si pierde*/
		}
	return (*premio);																	/*Se devuelve el resultado*/
}

int main(void) {
	/*Declaracion de variables*/
	int boleto[10]={0,0,0,0,0,0,0,0,0,0}, BoletoSistema[10]={0,0,0,0,0,0,0,0,0,0}, devolver=0, FalloNum=0, contador=0;
	float apuesta=0.0, premio=0.0;
	/*Llamada a la funcion para pedir los numeros y la apuesta al usuario, y los muestra por pantalla*/
	PedirBoleto(boleto, &FalloNum, &apuesta);
	/*Llamada a la funcion que genera numeros aleatorios y los muestra por pantalla*/
	GenerarBoletoSistema(BoletoSistema);
	/*Llamada a la funcion que comprueba el numero de aciertos y devuelve el resultado*/
	ComprobarPremio(boleto, BoletoSistema, &devolver, &contador);
	/*Llamada a la funcion que comprueba la cuantia ganada o perdida y muestra los resultados por pantalla*/
	premio=DineroPremio(&apuesta, &premio,&devolver, &contador);
	system("pause");																			/*Pausa para la correcta visualizacion*/
	return 0;
}
