#include <stdio.h>
#include <stdlib.h>
#include <math.h>


   ///Posibles tableros para jugar sudoku 9*9
	int matriz1[9][9] = {{1,4,7, 2,5,8, 3,6,9},{2,5,8, 3,6,9, 4,7,1},{3,6,9, 4,7,1, 5,8,2},
	                     {4,7,1, 5,8,2, 6,9,3},{5,8,2, 6,9,3, 7,1,4},{6,9,3, 7,1,4, 8,2,5},
					     {7,1,4, 8,2,5,  9,3,6},{8,2,5, 9,3,6, 1,4,7},{9,3,6, 1,4,7, 2,5,8}};

	int matriz2[9][9] = {{1,2,3, 4,5,6, 7,8,9},{4,5,6, 7,8,9, 1,2,3},{7,8,9, 1,2,3, 4,5,6},
	                     {2,3,4, 5,6,7, 8,9,1},{5,6,7, 8,9,1, 2,3,4},{8,9,1, 2,3,4, 5,6,7},
					     {3,4,5, 6,7,8, 9,1,2},{6,7,8, 9,1,2, 3,4,5},{9,1,2, 3,4,5, 6,7,8}};

	//Tablero de juego final, este tablero contendrá las respuestas del juego
	int tableroJuego[9][9];
	///Tablero que se mostrará al usuario con los acertijos (campos descubiertos)
	int tableroJuegoUsuario[9][9];
	///Casillas descubiertas
	int casillasDestapadas=81;

    ////FUNCIONES
     ///Llenado de tablero aleatorio
     void llenadoAleatorio(){
     		 srand(time(NULL));
	int numero = rand() % 9 + 1;
	int aux2=numero+1, aux3=numero+2;
	int i=0,aux=0,j=0;
	int casillas = 30;

	 for(j=1;j<=9;j++){
			for(i=0;i<9;i++){
				if(j==1){
				  aux=numero+i;
					}else if(j==2){
					  aux=numero+i+3;
						}else if(j==3){
						  aux=numero+i+6;
							}else if(j==4){
							  aux=aux2+i;
								}else if(j==5){
								  aux=aux2+i+3;
									}else if(j==6){
									  aux=aux2+i+6;
										}else if(j==7){
										  aux=aux3+i;
											}else if(j==8){
											  aux=aux3+i+3;
												}else{
												  aux=aux3+i+6;
													}
					  if(aux%9==0){
					   tableroJuego[i][j-1] = 9;
					  }else{
					    tableroJuego[i][j-1] =  aux % 9;
					  }

					 int    num = rand () % 10;
				if(num<4&&casillas>0){
					tableroJuegoUsuario[i][j-1]=tableroJuego[i][j-1];
					casillas--;
				}

			}
		}


	 }

    //Función para llenado de tablero Juego, así como para el llenado de tablero de Usuario
    void llenadoTableros(){
    	//Variables para recorrer las matrices
    int i=0,j=0;
         //Variable de bandera para solo destapar un máximo de 30 casillas del juego.
	int casillas = 30;
	///Generar un número aleatorio entre 1 y 2 para elegir entre los dos posibles tableros de juego
	int	numero;
	srand(time(NULL));
		numero = rand () % 3;

     ///Asignar el tablero del juego, como a destapar el tablero de juego que esta visible a los usuarios
     if(numero==0)
        for(i=0;i<9;i++)
        	for(j=0;j<9;j++){
        		///Destapar las cartas al usuario
        		  //Generar un numero aletorio entre 0 y 9, si este número es menor a 4, se destapa la casilla en el tablero
        		  //que se muestra al usuario, tambien se considera que máximo se pueden destapar 30 casillas.
        	    numero = rand () % 10;
				if(numero<4&&casillas>0){
					 //Se descubre en el  tablero que es mostrado al usuario
					tableroJuegoUsuario[i][j]=matriz1[i][j];
					///Se resta a la bandera, para no restar mas de 30
					casillas--;
				}
        	  tableroJuego[i][j]=matriz1[i][j];
			}
	  else if(numero==1){
	  		llenadoAleatorio();
	  	}else
        for(i=0;i<9;i++)
        	for(j=0;j<9;j++){
        		///Destapar las cartas al usuario
        	    numero = rand () % 10;
				if(numero<4&&casillas>0){
					tableroJuegoUsuario[i][j]=matriz2[i][j];
					casillas--;
				}
        	  tableroJuego[i][j]=matriz2[i][j];
			}

    //Se calculan las casillas que han sido destapadas, como tal sabemos que para ganar se deben de descubrir las 81 casillas del tablero
			casillasDestapadas-=(30-casillas);
// printf("Casillas destapadas: %d ",casillasDestapadas);
}

 ///Imprimir la matriz que representa el tablero del usuario
   void imprimirMatrizUsuario(){
   	int i=0, j=0;
	     for(i=0;i<9;i++){
	     	if(i==0){
	     		printf("   0 1 2 3 4 5 6 7 8 \n");
			 }
			for(j=0;j<9;j++){
				 if(j==0){
				   	printf(" %d ",i);
				 }
				 printf("%d ", tableroJuegoUsuario[i][j]);
			}
			printf("\n");
		}
	printf("\n");
   }

///Función para validar cada número que se quiere destapar
//Se ingresan tres parametros el número que se desea buscar asi como las coordenadas en X y Y
 void validarTurno(int numeroBuscar, int x, int y){
 	 //En esta condición validamos que el número sea igual en relación al tablero del juego, en donde se tienen los resultados
 	if(tableroJuego[y][x]==numeroBuscar){
 		 ///Si se cumple la condición de que sea igual al número que se busca verifica en la siguiente condición de que el
 		 ///número no haya sido descubierto anteriormente
 		 if(tableroJuegoUsuario[y][x]==0){
 		 	 printf("NUMERO DESCUBIERTO!!! \n");
 		   	 tableroJuegoUsuario[y][x]=numeroBuscar;
 		   	 imprimirMatrizUsuario();
 		      casillasDestapadas--;
 		      //printf("Casillas destapadas: %d ",casillasDestapadas);
		  }else{
		  	 ///El número es el correcto pero ya se descubrió anteriormente.
		  	printf("Esta casilla a sido destapada!!! \n");
		  }
	 }else{
	 	  ///El número que se busca no es correcto
	 	 printf("No es el número correcto sigue intentando!!! \n");
	 }
 }

 void logicaJuego(){
 	 //Logica de juego;
       char banderaJuego;

        //printf("Para  jugar introduzca un caracter diferente de 1: ");
        //scanf("%s", &banderaJuego);

         do{

        //Introducir las variables que se necesitan como el número a buscar, así como las coordenadas en donde se encuentra tal número
         	int numeroBuscar, x, y;
         	 ///El número que se desea buscar
         	 printf("Introduzca el numero que desea buscar en el rango de 1 a 9: ");
              scanf("%d", &numeroBuscar);
               //Validar que el número este dentro del rango
               if(numeroBuscar>9||numeroBuscar<1){
               	 while(numeroBuscar>9||numeroBuscar<1){
               	 	   printf("Introduzca un numero valido en el rango de 1 a 9: ");
              				scanf("%d", &numeroBuscar);
					}
			   }

            printf("Introduzca las coordenas (X,Y). \n Introduzca el valor de X: ");
        	  scanf("%d", &x);
        	  //Validar que la coordenada X este dentro del rango del tablero
        	    if(x>8||x<0){
               	 while(x>8||x<0){
               	 	   printf("Introduzca una coordenada valida para X en el rango de 0 a 8: ");
              				scanf("%d", &x);
					}
			   }
         	  printf(" Introduzca el valor de Y: ");
        	  scanf("%d", &y);
        	  //Validar que la coordenada Y este dentro del rango del tablero
        	  	    if(y>8||y<0){
               			 while(y>8||y<0){
               	 	   		printf("Introduzca una coordenada valida para Y en el rango de 0 a 8: ");
              				scanf("%d", &y);
							}
			  		 }
        	  //Al cumplirse todas las validaciones tanto del numero a buscar como de la coordenada (x, y), se manda a llamar a la función
        	  ///Validar turno
        	    validarTurno(numeroBuscar, x, y);

        	  ///Si las casillas destapadas tienen un valor de 0, quiere decir que ya no queda ninguna por destapar, lo que signififa que el usuario ha ganado
        	  //Es por eso que aquí la bandera de juego toma un valor de '1' para salir de la logica del juego
         	 if(casillasDestapadas==0){
         	 	printf("FELICIDADES SUDOKU 9*9 resuelto");
         	 	banderaJuego='1';
         	 	//En caso de que aun queden casillas por destapar se le estará preguntando al usuario si desea seguir jugando
			  }else{
			  	printf("Para seguir jugando introduzca un caracter diferente de 1: ");
        	    scanf("%s", &banderaJuego);
			  }

		 }while(banderaJuego!='1');
 }


int main(int argc, char *argv[]) {
	int i=0,j=0;

     ///Mandamos a llamar la función de llenar tableros
     llenadoTableros();
       printf("SUDOKU 9*9 \nTablero de Juego: \n");
       imprimirMatrizUsuario();
	///Comienza la logica del juego
     logicaJuego();
     ///Se muestran las casillas que han sido destapadas, lo cual es un resultado para el jugador.
     printf("Casillas por descubrir: %d", casillasDestapadas);

	return 0;
}



