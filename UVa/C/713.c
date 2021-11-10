#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long rever(unsigned long long n){
	unsigned long long resu = 0;
	while(n){
		resu = 10 * resu + (n % 10);
		n = n / 10;
	}
	return resu;
}




//INCOMPLETO NO FUNCIONA CON NUMEROS LARGOS


int main(){


	int cases;

	scanf("%d",&cases);

	while(cases--){
		unsigned long long int num1, num2;
		scanf("%llu %llu",&num1 ,&num2);

		printf("%llu\n",rever(rever(num1) + rever(num2)));


	}

	return 0;
}