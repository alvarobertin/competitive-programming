#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


	int cases, D, N, i, posR, Acu, mayor, index = 1, flag = 1;

	char Rocks[50000], temp;

	scanf("%d", &cases);

	while(cases--){

		Acu = 0;
		posR = 0;
		mayor = 0;
		flag = 1;

		scanf("%d %d\n", &N, &D);

		for (i = 1; i <= D; ++i){
			Rocks[i] = '.';
		}

		for (i = 0; i < N; ++i){
			
			scanf(" %c-%d", &temp, &posR);
			Rocks[posR] = temp;

		}

		for (i = 1; i <= D; ++i){
			Acu += 1;
			
			if(Rocks[i] == 'B'){
				
				if(Acu > mayor){
					
					mayor = Acu;
				}
				flag = 1;
				Acu = 0;
			}
			else if(Rocks[i] == 'S' && flag){
				Rocks[i] = '.';
				flag = 0;
				if(Acu > mayor){
					mayor = Acu;
				}
				Acu = 0;				
			}
			else if(Rocks[i] == 'S'){
				flag = 1;
			}
			
			
		}
		
		if (Acu > mayor){
			
			mayor = Acu;	
		}

		Acu = 0; 
		flag = 1;

		for (i = D; i > 0; --i){
			
			if(Rocks[i] == 'B'){
				
				if(Acu > mayor){
					
					mayor = Acu;
				}
				Acu = 0;
			}
			else if(Rocks[i] == 'S'){
				Rocks[i] = '.';
				flag = 0;
				if(Acu > mayor){
					mayor = Acu;
				}
				Acu = 0;				
			}
			
			Acu += 1;

		}
 		if(Acu > mayor){
 			mayor = Acu;
 		}


		printf("Case %d: %d\n", index++,mayor);


	}







	return 0;
}