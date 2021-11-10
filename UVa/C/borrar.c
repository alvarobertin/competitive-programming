#include <stdio.h>




int* punto1a(int n){

	int* vec;

	vec = (int *) malloc(sizeof(int) * n);

	return vec;

}

int **crearMatriz(unsigned int m, unsigned int n){
	/* entra: m y n son las dimensiones
	sale: devuelve una matriz de tamanyo m x n
	*/
	int ** mat;
	
	mat = (int **) malloc(m * sizeof(int *));
	if(!mat){
	   printf("ERROR: no hay suficiente memoria");
	   exit(0);
	}
	
	for(int i = 0; i < m; i++){		   
		mat[i] = (int *) relloc( mat[i], 2  * n  * sizeof(int ));
		if(!mat[i]){
	   		printf("ERROR: no hay suficiente memoria");
	   		exit(0);
		}
	}

	return mat;
}

int main(){

	int* arr;

	arr = punto1a(20);

	return 0;
}