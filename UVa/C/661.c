#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){


	int n, m, c, Amp[21], Op[50], o, acu, mayor, flag, Sequ = 1, i;

	scanf("%d %d %d\n", &n, &m, &c);

	while(c){

		for (i = 0; i < 50; ++i){
			Op[i] = -1;
		}

		acu = 0;
		mayor = 0;
		flag = 0;

		for (i = 1; i <= n; ++i){
			scanf("%d", Amp + i);
		}
		for(i = 0; i < m; ++i){
			scanf("%d", &o);
			
			Op[o] *= -1; 

			if(Op[o] == 1){
				acu += Amp[o];

				if(acu > c){
					flag = 1;
				}

				if(acu > mayor)
					mayor = acu;
			
			}else if(Op[o] == -1){
				acu -= Amp[o];
			}

		}

		printf("Sequence %d\n", Sequ);
		
		if(flag){
			printf("Fuse was blown.\n");
		}
		else{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", mayor);
		}

		if(n){
			printf("\n");
		}

		scanf("%d %d %d\n", &n, &m, &c);
		Sequ++;

	}

	return 0;
}