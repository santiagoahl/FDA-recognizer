#include <stdio.h>
#include <string.h>
int lon_max_string = 1000;
void 
alfanumerico(int n_estados,int n_estados_acep,int estado_acep[10000])
{
	int n_simbolos = 36;
	int matriz_de_estados[n_estados][n_simbolos];
	char sigma[] = "abcdefghijklmnopqrstuvwxzy0123456789 ";
	int i, j;
  	printf("Alfabeto alfanumerico: Letras minusculas, numeros y espacio \n");
  	int estado_asignado;
  	printf("A continuacion ingrese numeros enteros <=%d para indicar el cambio de estado", n_estados);
  	for(i = 0; i<n_estados; i++){
  		printf("\n Ingrese asignacion de cambio de estado para el estado q%d \n",i);
  		for(j = 0; j<n_simbolos; j++){
  			printf("\n Ingrese q_%d(%c)= ",i,sigma[j]);
  			scanf(" %d", &estado_asignado);
  			matriz_de_estados[i][j] = estado_asignado;
		  }
	  }
	printf("\n \n");
	for(i = 0; i<n_estados; i++){
		printf("\n");
  		for(j = 0; j<n_simbolos; j++){
  			printf("%d | ",matriz_de_estados[i][j]);
		  }
	}
	printf("\n \n Evaluacion de strings: \n");
	char string[lon_max_string];
	printf("Ingrese una cadena de texto: ");
	scanf(" %c", &string);
	int len = strlen(string);
	int estado_actual = 0;
	int k;
	int aceptacion = 0;
	for(k=0; k<len; k++){
		char simbolo_leido = string[k];
		for(j=0; j<n_simbolos; j++){
			for(i=0; i<n_estados;i++){
				if(sigma[i] == simbolo_leido){
					estado_actual = matriz_de_estados[i][j];
				}
			}
		}
	} 
	for(k=0; k<n_estados_acep; k++){
		if(estado_actual == estado_acep[k]){
			aceptacion = 1;
			printf("La cadena ha sido aceptada");
			break;
		}
		if(k==n_estados_acep-1){
			printf("La cadena NO ha sido aceptada");
		}
	}
}

void
personalizado(int n_estados,int n_estados_acep, int estado_acep[1000], int n_simbolos)
{
	int matriz_de_estados[n_estados][n_simbolos];
	char sigma [n_simbolos];
	int i, j;
	for(i = 0; i<n_estados; i++){
		printf(" \n Ingrese el simbolo #%d: ",i+1);
		scanf(" %c", sigma[i]);
	}
  	printf("Alfabeto alfanumerico: Letras minusculas, numeros y espacio \n");
  	int estado_asignado;
  	printf("A continuacion ingrese numeros enteros <=%d para indicar el cambio de estado", n_estados);
  	for(i = 0; i<n_estados; i++){
  		printf("\n Ingrese asignacion de cambio de estado para el estado q%d \n",i);
  		for(j = 0; j<n_simbolos; j++){
  			printf("\n Ingrese q_%d(%c)= ",i,sigma[j]);
  			scanf(" %d", &estado_asignado);
  			matriz_de_estados[i][j] = estado_asignado;
		  }
	  }
	printf("\n \n");
	for(i = 0; i<n_estados; i++){
		printf("\n");
  		for(j = 0; j<n_simbolos; j++){
  			printf("%d | ",matriz_de_estados[i][j]);
		  }
	}
	printf("\n \n Evaluacion de strings: \n");
	char string[lon_max_string];
	printf("Ingrese una cadena de texto: ");
	scanf(" %c", &string);
	int len = strlen(string);
	int estado_actual = 0;
	int k;
	int aceptacion = 0;
	for(k=0; k<len; k++){
		char simbolo_leido = string[k];
		for(j=0; j<n_simbolos; j++){
			for(i=0; i<n_estados;i++){
				if(sigma[i] == simbolo_leido){
					estado_actual = matriz_de_estados[i][j];
				}
			}
		}
	} 
	for(k=0; k<n_estados_acep; k++){
		if(estado_actual == estado_acep[k]){
			aceptacion = 1;
			printf("La cadena ha sido aceptada");
			break;
		}
		if(k==n_estados_acep-1){
			printf("La cadena NO ha sido aceptada");
		}
	}
}  

int main()
{
    printf("\n FINITE DETERMINISTIC AUTOMATA \n\n --------------- \n\n");
    printf("Ingresa el numero de estados: ");
    int n_estados;
    scanf("%d", &n_estados);
    printf("Ingresa el numero de estados de aceptacion: ");
    int n_estados_acep;
    scanf("%d", &n_estados_acep);
    printf("Ingresa los estados de aceptacion (numeros enteros): ");
    int p, t, estado_acep[n_estados_acep];
    for(p=0;p<n_estados_acep;p++){
    	printf("\n Estado de aceptacion #%d: ",p+1);
    	scanf(" %d:", &estado_acep[p]);
	}
    printf("Ingresa tu alfabeto Sigma \n");
    printf("Quieres usar el alfabeto usual (Alfanumerico)? \n Y/n: ");
    char chose, yes_1 = 'Y', yes_2='y', no_1 = 'N', no_2='n';
    scanf(" %c", &chose);
    if(chose==yes_2 || chose==yes_1) {
           alfanumerico(n_estados, n_estados_acep, estado_acep);
    }
    else if(chose==no_2 || chose==no_1){
    	int n_simbolos;
    	printf("\n Ingrese cantidad de simbolos de su alfabeto: ");
    	scanf(" %d",&n_simbolos);
    	personalizado(n_estados, n_estados_acep, estado_acep, n_simbolos);
	}
	else{
		printf("Respuesta no valida");
	}
	
  return 0;
}
    
