#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*En el mejor de los casos la complejidad del algoritmo será: O(1). En el peor de los casos será: O(180)*/


int main(void){
	int num;
	scanf("%d",&num);
	while(num > 0){
		int pos, i1 = 0, i2 = 0, i3 = 0,sum = 0, permu = 0, res = 0, d6 = 0, d3 = 0, d1 = 0, combi = 0;		
		if(num <= 180){	
			for (i1 = 0; i1 <= 60; ++i1){
				if (!(i1 > 20 && i1 % 2 != 0 && i1 % 3 != 0 && i1 != 50) && !(i1 > 40 && i1%3 != 0 && i1 != 50)){
					for (i2 = 0; i2 <= 60; ++i2){
						if (!(i2 > 20 && i2 % 2 != 0 && i2 % 3 != 0 && i2 != 50) && !(i2 > 40 && i2%3 != 0 && i2 != 50)){ 
							for (i3 = 0; i3 <= 60; ++i3){
								if (!(i3 > 20 && i3 % 2 != 0 && i3 % 3 != 0 && i3 != 50)&& !(i3 > 40 && i3%3 != 0 && i3 != 50)){ 
									sum = i1 + i2 + i3;
									if (sum == num){
										if(!(i1 == i2 && i2 == i3 && i3 == i1)){
											if(i1 != i2 && i2 != i3 && i3 != i1){
												d6 += 1;
											}
											else{
												d3 += 1;
											}
										}
										else{
											d1 +=1;
										}
										permu++;
									}
								}
							}
						}				
					}
				}				
			}
		}
		if (permu > 0){
			combi = (d6/6) + (d3/3) + d1;
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",num,combi);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",num,permu);
		}
		else{
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",num);
		}


		printf("**********************************************************************\n");
		scanf("%d",&num);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
