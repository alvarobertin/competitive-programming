#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*La complejidad de este algoritmo es O(n) , donde n es la cantidad de numeros que tiene la operacion.*/
int main(void){	
	int cases;
	scanf("%d\n",&cases);
	while(cases--){
		int l, i, sindex = 0, nums[20] = {0};
		long long int izq = 0, der = 0, mayor = 0, menor = 0;
		char op[200], sim[25] = {""};
		scanf("%s",op);
		l = strlen(op);
		for (i = 0; i < l; ++i){
			if(op[i] == '*' || op[i] == '+'){
				sim[sindex] = op[i];
				++sindex; 
			}
			else{
				nums[sindex] =  (nums[sindex]*10) + op[i] - '0';
			}
		}
		
		if (sindex == 0){
			izq = nums[0];	
		}
		for (i = 0; i <= sindex; ++i){
			if(sim[i] == '+' ){
				if(izq == 0){
					izq = nums[i] + nums[i+1];
				}else{
					izq += nums[i+1];
				}
				
			}
			else if(i+1 <= sindex){

				if (izq == 0){
					izq = nums[i];
				}
				if(sim[i+1] == '+'){
					der = 0;
					while(sim[i+1] == '+' && i <= sindex){
						if(der == 0){
							der = nums[i+1] + nums[i+2];
						}else{
							der += nums[i+2];
						}

						++i;						
					}
					
					izq = izq * der;
				}
				else{
					izq = izq * nums[i+1];
				}
			}
			mayor = izq;
		}

		/*###########################################################################################
		#############################################################################################3
		#############################################################################################*/
		izq = 0; der = 0; 
		if (sindex == 0){
			izq = nums[0];	
		}
		for (i = 0; i <= sindex; ++i){
			if(sim[i] == '*' ){
				if(izq == 0){
					izq = nums[i] * nums[i+1];
				}else{
					izq *= nums[i+1];
				}
				
			}
			else if(i+1 <= sindex){

				if (izq == 0){
					izq = nums[i];
				}
				if(sim[i+1] == '*'){
					der = 0;
					while(sim[i+1] == '*' && i <= sindex){
						if(der == 0){
							der = nums[i+1] * nums[i+2];
						}else{
							der *= nums[i+2];
						}

						++i;						
					}
					
					izq = izq + der;
				}
				else{
					izq = izq + nums[i+1];
				}
			}
			menor = izq;
		}

		printf("The maximum and minimum are %lli and %lli.\n", mayor, menor);
	}	
	return 0;
}
