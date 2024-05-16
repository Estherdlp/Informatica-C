/*
 ============================================================================
 Name        : ejercicioParte1Continua.c
 Author      : Esther del Pico García
 Version     : v2.0
 Copyright   : No copiar!
 Description : Proyecto evaluación continua C. Examen IA - TIPO A3
 ============================================================================
 */

#include <stdio.h>														/*Librerias utilizadas*/
#include <stdlib.h>
#define MAXSTR 50														/*Tamaño para la cadena de caracteres de nombre y apellidos*/
struct submarino {														/*Definicion estructura con los datos del submarino*/
	int distancia[8];
	int profundidad[8];
	int velocidad[8];
};

int correctoDNI (){														/*Funcion que calcula la letra del DNI*/
	int i=0, CalculoLetra=0, correcto=1, fallo=0;						/*Declaracion de variables*/
	char LetraControlDNI[23]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'}, DNI[9]={'0','0','0','0','0','0','0','0','\0'};
	do {																/*Bucle para pedir el DNI al usuario. Maximo 3 intentos*/
		correcto=1;
		printf("Introduzca el DNI que desee comprobar: \n");			/*Pide por pantalla al usuario el DNI y lo almacena en la variable DNI*/
		gets(DNI);
		for (i=0;i<sizeof(DNI);i++){									/*Bucle de control del DNI*/
			if (DNI[i] == 0){											/*Finaliza el bucle al encontrar el caracter nulo de la cadena de caracteres*/
				break;
			}
			if (DNI[i]<48 || DNI[i]>57){								/*Si los valores de DNI no se corresponden con los numeros en codigo ASCII, da error*/
				fallo++;
				correcto=0;
				printf("El DNI debe contener unicamente numeros. Intentos restantes: %d\n",3-fallo);
				break;
			}
		}
		if (i>8){														/*Si la longitud del DNI introducido es mayor que 8, da error*/
			fallo++;
			correcto=0;
			printf("El DNI  es demasiado largo. Intentos restantes: %d\n",3-fallo);
		}
		if (fallo>2){													/*Si se han cometido tres errores, finaliza el bucle de control*/
			correcto=-1;
		}
	} while(correcto==0);
	if (correcto>0){													/*Ejecucion si el DNI introducido es correcto*/
		CalculoLetra= (atoi(DNI)+23)%23;								/*Se suman 23 al DNI para que la operacion del calculo de la letra funcione con DNI<23*/
		printf("Su DNI completo es: %s%c\n", DNI, LetraControlDNI[CalculoLetra]);
		return (atoi(DNI));												/*Devuelve el valor del DNI como tipo entero*/
	}
	else{																/*Ejecucion si se ha introducido el DNI mal tres veces*/
		printf("Se ha excedido el numero de intentos\n");
		return (-1);													/*Devuelve -1*/
	}
}

void CalcularValorMinimo (struct submarino datos, int* mindistancia,int* minprofundidad,int* minvelocidad){ /*Funcion que calcula el minimo*/
	int fila1,fila2,fila3,distanciaMinimo=0,profundidadMinimo=0,velocidadMinimo=0;		/*Declaracion de variables*/
	printf("\nLa distancia en metros desde el inicio del trayecto del submarino: \n");	/*Muestra por pantalla el valor del primer vector de la estructura*/
	for (fila1=0;fila1<8;fila1++){
		if (datos.distancia[fila1]>6){
			printf("Alerta, el submarino esta demasiado lejos\n");		/*Si el valor es >6, muestra alerta por pantalla*/
		}
		printf("%d m\n",datos.distancia[fila1]);
		if (datos.distancia[fila1]<*mindistancia){
			*mindistancia=datos.distancia[fila1];						/*Almacena el valor minimo del vector*/
			distanciaMinimo=fila1;										/*Almacena la posicion del valor minimo*/
		}
	}
	printf("\nLa profundidad a la que se encuentra el submarino para cada una de las distancias dadas: \n");	/*Muestra por pantalla el valor del segundo vector de la estructura*/
		for (fila2=0;fila2<8;fila2++){
			if (datos.profundidad[fila2]>6){
				printf("Alerta, la profundidad es demasiado elevada\n");/*Si el valor es >6, muestra alerta por pantalla*/
			}
			printf("%d m\n",datos.profundidad[fila2]);
			if (datos.profundidad[fila2]<*minprofundidad){
				*minprofundidad=datos.profundidad[fila2];				/*Almacena el valor minimo del vector*/
				profundidadMinimo=fila2;									/*Almacena la posicion del valor minimo*/
			}
		}
		printf("\nVelocidad del submarino para una de las medidas registradas: \n");	/*Muestra por pantalla el valor del tercer vector de la estructura*/
		for (fila3=0;fila3<8;fila3++){
			if (datos.velocidad[fila3]>6){
				printf("Alerta, la velocidad es excesiva\n");			/*Si el valor es >6, muestra alerta por pantalla*/
			}
			printf("%d m/s\n",datos.velocidad[fila3]);
			if (datos.velocidad[fila3]<*minvelocidad){
				*minvelocidad=datos.velocidad[fila3];					/*Almacena el valor minimo del vector*/
				velocidadMinimo=fila3;									/*Almacena la posicion del valor minimo*/
			}
		}
		printf("\n======================================================================================================\n" /*Se muestran por pantalla los resultados*/
				"La distancia minima a la que se encuentra el submarino es %d y se encuentra en la posicion %d\n",*mindistancia,distanciaMinimo);
		printf("La profundidad minima a la que se encuentra el submarino es %d y se encuentra en la posicion %d\n",*minprofundidad,profundidadMinimo);
		printf("La velocidad minima a la que viaja el submarino es %d y se encuentra en la posicion %d\n"
				"======================================================================================================\n",*minvelocidad,velocidadMinimo);
}

int main(void) {														/*Programa principal*/
	int DNI=0, mindistancia=0, minprofundidad=0,minvelocidad=0,menu=0;	/*Declaracion de variables*/
	char nombre[MAXSTR], apellido[MAXSTR],basura;
	struct submarino datos=												/*Instancio estructura submarino*/
			{{0,1,3,5,21,9,12,15},{1,-5,2,8,6,7,25,-1},{0,5,6,5,6,8,9,14}};
	while (menu!=2){													/*Menu del programa*/
		menu=0;															/*Inicializacion del menu en cada ejecucion*/
		printf("Buenos dias. Por favor, introduzca sus datos personales: \nNombre: ");	/*Peticion de nombre y apellidos, almacenados en las variables nombre y apellido*/
		gets (nombre);
		printf("Apellido: ");
		gets (apellido);
		printf("Bienvenido\n**********%s %s**********\n",nombre,apellido); /*Saluda al usuario con su nombre y su apellido*/
		DNI = correctoDNI();											/*Llamada a la funcion que comprueba la letra del DNI*/
		if (DNI<0){														/*Si el valor de la funcion es <0, se finaliza la ejecucion del programa*/
			system("pause");
			exit(-1);
		}
		while (menu>2 || menu<1){										/*Opciones del menu*/
			printf("\n====================\nOpciones disponibles\n====================\n 1)Consulta los valores del submarino\n 2)Salir\n"
					"Por favor, escoja la opcion que desee realizar: ");
			scanf("%d", &menu);
			scanf("%c", &basura);										/*Se recoge la basura para evitar fallos en ejecuciones posteriores*/
			if (menu==1){												/*Ejecucion si se selecciona la opcion 1*/
				CalcularValorMinimo(datos,&mindistancia, &minprofundidad, &minvelocidad);	/*Llamada a la funcion que calcula el valor minimo*/
				system("pause");
				system("cls");											/*Limpieza de pantalla para correcta visualizacion*/
			}
			if (menu>2 || menu<1){										/*Ejecucion si se selecciona una opcion erronea*/
				printf("El numero introducido no es correcto. Por favor, seleccione una opcion valida\n");
			}
		}
	}
	printf("Que tenga buen dia\n");										/*Mensaje de despedida al finalizar la ejecucion*/
	system("pause");
	return 0;
}
