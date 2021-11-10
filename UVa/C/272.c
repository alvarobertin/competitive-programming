#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){

	char pal[300], resul[300];
	int l, i, j, k, flag = 1;

	while(fgets(pal,300,stdin) != NULL){

	
		for (i = 0; i < 300; ++i){
			resul[i] = ' ';
		}

		l = strlen(pal);

		for (i = 0, k = 0; i <= l; ++i, ++k){

			if(pal[i] == 34){

				if(flag){
					resul[k] = 96;
					resul[k + 1] = 96; 
					++k;
					flag = 0;
				}
				else{
					resul[k] = 39;
					resul[k + 1] = 39;
					++k;
					flag = 1;
				}
			}
			else{
				resul[k] = pal[i];
			}
			
		}
		printf("%s", resul);
	}
	return 0;
}