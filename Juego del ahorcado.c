#include <stdio.h> // Libreria estandard.
#include <string.h> // Libreria de manejo de cadenas de caracteres.
#include <stdlib.h> 
#include <time.h> // Libreria de random.
#define MAX 50 // Arreglos.

//prototipos
void presentacion(void);
int dificultad(void);
int funcion_ale(void);
char* palabra_basicas(void);
char* palabra_dificil(void);
void guion(char palabra2[MAX],int longitud);
//palabra:String
//letra:Char
//main:void ->int
//el main tendremos dos palabras de tipo array en donde una es la palabra descubierta(palabraD) y la otra es lo mismo que la primera palabra,
//pero en vez de haber letras hay guiones(ppantalla).el main nos pedira una letra que la ingresaremos por teclado,si la letra
//esta en palabraD ,modificaremos ppantalla,si no lo esta nos resta una vida.Si la vida llega a cero el programa se termina y nos mostrara la
//palabra completa,en caso contrario de que ingrese todas las letras correctamente el usuario ganara y se le muestra por pantalla un mensaje 
//de felicitaciones.

int main(void){
	presentacion();
	char *r;
	int dif=dificultad(); //guardamos el resultado de dificultad() en una variable de tipo entero.
	if (dif == 1){ //si la variable dif es 1 entonces que guarde una palabra de la funcion palabra_basicas en el puntero r.
		r=palabra_basicas();
	}
	else{ //sino que guarde una palabra de la funcion palabra_dificil() en el puntero r.
		r=palabra_dificil();
	}
	char palabraD[MAX]="";
	strcat(palabraD,r);
	char ppantalla[MAX]=""; //ppantalla es la palabra a descubrir.
	int longitud1=strlen(palabraD);
	guion(ppantalla,longitud1);
	int i;
	char letra;//es la variable donde se va a guardar lo ingresado por teclado.
	int vida = 5; //la cantidad de vida que tenemos al empezar.
	printf(" %s",ppantalla); 
	while (vida > 0){
		int bandera = 0;//inicializacion de la bandera.
		printf("\ningrese una letra:"); //pedimos que ingrese una letra.
		scanf(" %c",&letra);
		for(i = 0; i < MAX ; i++){
			if(palabraD[i] == letra){
				ppantalla[i]=letra; //agregar la letra en ppantalla en el indice que corresponde.
				bandera = 1; // la bandera ahora es igual a 1.
				printf(" %s",ppantalla); //nos muestra por pantalla como esta actualmente ppantalla.
			}//FIN DEL IF 
		}//FIN DEL FOR
		if ((strcmp(palabraD,ppantalla)) == 0){ //comparamos si palabraD es igual a ppantalla.
			printf("\nFelicitaciones!!,la palabra esta completa");//si es igual muestro por pantalla la felicitacion.
			break; //ya que se completo la palabra hacemos un break para terminar con el ciclo while.
		}
		if (bandera == 1){  // si la bander es igual a 1 nos aclara en pantalla que la letra esta en la palabra.
			printf("\nla letra esta en la palabra");
		}
		else{//si no pasa ninguna de las otras condiciones que nos reste una vida.
			vida--; 
			printf("\nla letra no esta en la palabra");
			printf("\nustede tiene %d vidas",vida);
		}
	}//FIN DEL WHILE
	if (vida == 0){ //si la vida es igual a cero termina el programa el usuario pierde y nos muestra la palabra .
		printf("\nse le acabo las oportunidades de acertar,la palabra era %s",palabraD);
	}
	return 0;
}

//presentacio: Void -> Void
//lo primero que hace presentacion es imprimir en pantalla el nombre del proyecto,luego le pide al usuario que ingrese su nombre
//y luego le da la bienvenida,por ultimo muestra los modos de juegos que son dos el modo facil y el modo dificil.
void presentacion(void){
	char nombre[MAX];
	printf("\n\tJuego del ahorcado - Proyecto 02, Programacion II.\n");
	printf("\tPor favor, ingrese su nombre:\t");
	scanf("%[^\n]",nombre);
	printf("\tSaludos %s. Bienvenido al juego del ahorcado.\n",nombre);
	printf("\tElegir una de estas opciones:\t\n");
	printf("\t\t 1. Nivel Basico.");
	printf("\t\t 2. Nivel Avanzado.\n");
}

//dificultad: Void -> Int
//dificultad pide por teclado al usuario que ingrese 1 o 2 ,si es igual a 1 es la dificultad facil y imprime la ayuda correspondiente
//a esta dificultad y me devuelve 1,si es igual a 2 imprime por pantalla que se a elegido la dificultad dificil y devuelve 2.
int dificultad(void){
	int ingreso;
	printf("\tingreso:\t");
	scanf("%d",&ingreso);
	if (ingreso == 1){
		printf("\tHaz elegido la dificultad: Basica.\n");
		printf("\tte damos una ayuda:");
		printf("\n\t- Comienza usando vocales.");
		printf("\n\t- Recuerda todo el abecedario:");
		printf("\n\tA,B,C,D,E,F,G,H,I,J,K,L,M,N,Ñ,O,P,Q,R,S,T,U,V,W,X,Y,Z.\n");
		return 1;
	}
	if (ingreso == 2){
		printf("\tHaz elegido la dificultad: Avanzado.\n");
		return 2;
	}
	else{
		return 0;
	}
}
//funcion_ale: void -> Int
//funcion_ale lo que hace es generar un numero aleatorio del 1 al 6 .
int funcion_ale(void){
	int numeroAl;
	srand(time(NULL));
	numeroAl= 1 + rand() % ((6 + 1) - 1);
	return numeroAl;
}

//palabras_basicas: Void -> Char*
//lo que hace la funcion palabra_basica es devolvernos una palabra aleatoria que esto se consigue con un numero aleatorio
//dado de la funcion funcion_ale.
char* palabra_basicas(void){
	int numeroAle=funcion_ale();
	char *p;
	switch (numeroAle){
		case 1:
			p="perro";
			break;
		case 2:
			p="patricio";
			break;
		case 3:
			p="maiz";
			break;
		case 4:
			p="nuez";
			break;
		case 5:
			p="dory";
			break;
		default:
			p="revista";
			break;
		}
	return p;
}
//palabras_dificil: Void -> Char*
//lo que hace la funcion palabra_dificil es devolvernos una palabra aleatoria que esto se consigue con un numero aleatorio
//dado de la funcion funcion_ale.
char* palabra_dificil(void){
	int numeroAlea=funcion_ale();
	char *t;
	switch (numeroAlea){
		case 1:
			t="paralelepipedo";
			break;
		case 2:
			t="filantropo";
			break;
		case 3:
			t="misantropia";
			break;
		case 4:
			t="fisioterapeuta";
			break;
		case 5:
			t="Ventriculo";
			break;
		default:
			t="hipotalamo";
			break;
		}
	return t;
}
//guion: String -> Int -> void
//la funcion guion toma una string y una longitud expresado en un entero. 
// palabra1 es vacio(""),lo que hace la funcion es concatenar un guion en
//palabra1 y lo guarda esto en su argumento.Para poder concatenar los guiones haremos un for, mientras que un entero i sea
//diferente de la longitud se agregara un guion a palabra1.
//ejemplo:
//entrada:"",4  guarda en memoria a palabra1 como: "----"
void guion(char palabra1[MAX],int longitud){
	int i;
	for(i=0;i != longitud ;i++){
		strcat(palabra1,"-");
	}
}


