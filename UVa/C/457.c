#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int cases = 0;
	int dna[10], dishes[42], ndishes[42], i = 0, k = 0, index = 0, flag = 1, primero = 1;
	scanf("%d", &cases);

	while(cases-- > 0){

		index = 0;
		flag = 1;
		
		for (i = 0; i <= 41; ++i){
			dishes[i] = 0;
			ndishes[i] = 0;
		}
		//fflush(stdin);
		dishes[20] = 1;

		for (i = 0; i < 10; ++i){
			dna[i] = 0;
		}		

		for (i = 0; i < 10; ++i){
			scanf("%d", dna + i);
		}

		/*
				La flag está para que en cada ciclo se vaya rotando el plato de referencia, ya que el que era el nuevo despues será
				el de referencia. Al igual por eso es necesario a la hora de imprimir, para que imprima el correcto. 
		*/

		for (i = 0; i < 50; ++i){
			if(flag){
				for (k = 1; k <= 40; ++k){
					index = dishes[k] + dishes[k - 1] + dishes[k + 1];
					ndishes[k] = dna[index];
				}
				flag = 0;
			}
			else{
				for (k = 1; k <= 40; ++k){
					index = ndishes[k] + ndishes[k - 1] + ndishes[k + 1];
					dishes[k] = dna[index];
				}
				flag = 1;					
			}
			if(flag){
				for (k = 1; k <= 40; ++k){
					if(ndishes[k] == 0)
						printf(" ");
					else if(ndishes[k] == 1){
						printf(".");
					}
					else if(ndishes[k] == 2){
						printf("x");
					}
					else if(ndishes[k] == 3){
						printf("W");
					}
				}
			}
			else{
				for (k = 1; k <= 40; ++k){
					if(dishes[k] == 0)
						printf(" ");
					else if(dishes[k] == 1){
						printf(".");
					}
					else if(dishes[k] == 2){
						printf("x");
					}
					else if(dishes[k] == 3){
						printf("W");
					}
				}					
			}
			printf("\n");		
		}
		if(cases > 0){
			printf("\n");
		}
	}

	return 0;
}