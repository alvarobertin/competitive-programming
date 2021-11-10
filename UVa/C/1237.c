/*  https://onlinejudge.org/external/12/1237.pdf  */ 
#include <stdio.h>
#include <string.h>

int main(void){	
	int cases;
	scanf("%d\n",&cases);
	while(cases--){
		int b[10000], a[10000], D, Q, p, i = 0, t = 0,ind;
		char* c[10000][20];
		scanf("%d\n",&D);
		while(i < D){
			scanf("%s %d %d",c[i],&b[i],&a[i]);
			i++;
		}
		scanf("%d\n",&Q);
		while(Q--){
			t = 0;
			scanf("%d\n",&p);
			for(i = 0; i < D; i++){
				if(p >= b[i] && p <= a[i]){
					ind = i;
					t++;
					if(t > 1){
						break;
					}
				}
			}
			if(t > 1 || t == 0){
				printf("UNDETERMINED\n");
			}
			else{
				printf("%s\n",c[ind]);
			}

		}
		if(cases){
			printf("\n");
		}
	}	
	return 0;
}

/*
En el mejor de los casos la complejidad será O(1), ya que encuentra de una lo que busca.

En el peor de los casos la complejidad será O(n), n siendo la longitud de la base de datos.
*/
