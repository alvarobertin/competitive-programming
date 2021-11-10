#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
	int B, N;

	scanf("%d %d",&B,&N);
	while(B && N){
		int R[21], Plata[21], Deuda[21], i, deudor, presta, valor,flag = 0;

		for (i = 1; i <= B; ++i){
			R[i] = 0;
			Plata[i] = 0;
			Deuda[i] = 0;
		}

		for (i = 1; i <= B; ++i){
			scanf("%d", &R[i]);	
		}
		for (i = 1; i <= N; ++i){
			scanf("%d %d %d", &deudor, &presta, &valor);
			Deuda[deudor] += valor;
			Plata[presta] += valor;
		}

		for (i = 1; i <= B; ++i){

			if(Plata[i] + R[i] < Deuda[i]){
				flag = 1;
				break;
			}
		}
		if(flag){
			printf("N\n");
		}
		else
			printf("S\n");
		
		scanf("%d %d",&B,&N);
	}



	return 0;
}