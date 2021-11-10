#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumdigits(int n){
	int sum = 0;
	while(n > 0){
		sum += n % 10;
		n = n/10;
	}
	return sum;
}

int main(){
	char nom[50];	
	int len = 0, i = 0, value = 0, sum = 0, pal1 = 0, pal2 = 0;
	double resul = 0;
	
	while(fgets(nom, 50, stdin) != NULL){

		sum = 0;
		pal1 = 0;
		pal2 = 0;
		value = 0;

			
		len = strlen(nom);

		for (i = 0; i < len; ++i){
			//CODIGO ASCCI VA DESDE 65 A 90. Y 97 a 122.
			if( (nom[i] >= 65 && nom[i] <= 90) || (nom[i] >= 97 && nom[i] <= 122) ){
				
				if(nom[i] >= 65 && nom[i] <= 90)
					value = nom[i] - 64;
				else
					value = nom[i] - 96;

				
				while(value > 9){
					value = sumdigits(value);
				}
				sum += value;
			}
		}

		while(sum > 9){
			sum = sumdigits(sum);	
		}
		pal1 = sum;

		fgets(nom, 50, stdin);

		sum = 0;
		len = strlen(nom);
		
		for (i = 0; i < len; ++i){
			if( (nom[i] >= 65 && nom[i] <= 90) || (nom[i] >= 97 && nom[i] <= 122) ){
				
				if(nom[i] >= 65 && nom[i] <= 90)
					value = nom[i] - 64;
				else
					value = nom[i] - 96;
				
				while(value > 9){
					value = sumdigits(value);
				}
				sum += value;
			}
		}

		while(sum > 9){
			sum = sumdigits(sum);	
		}

		pal2 = sum;

		if(pal2 > pal1)
			resul = (double)pal1 / (double)pal2;
		else
			resul = (double)pal2 / (double)pal1;

		printf("%.2lf %%\n", resul*100);
	}

	return 0;
}