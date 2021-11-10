#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	char num[1000000];
	int ant = 0, n = 1, cont = 0, index = 1;

	scanf("%s", num);

	while(strcmp(num,"END") != 0){
		
		n = strlen(num);

		if(num[0] == '0'){
			cont = 2;
		}
		else if(n == 1 && num[0] == '1'){
			cont = 1;
		}
		else if(n == 1){
			cont = 2;
		}
		else if(n >= 2 && n < 10){
			cont = 3;
		}
		else{
			cont = 4;
		}

		printf("%d\n",cont);

		scanf("%s", num);
	
	}

	return 0;
}

