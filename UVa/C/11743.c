#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sum(int n){
	int sum = 0;
	while(n > 0){
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}



int main(){

	int cases;
	int i, num, undou, dou, resul;

	scanf("%d", &cases);

	while(cases--){
		num = 0;
		undou = 0;
		dou = 0;
		resul = 0;

		for (i = 0; i < 4; ++i){
			scanf("%d", &num);

			undou += num % 10;
			num = num / 10;

			dou += sum(2 * (num % 10));
			num = num / 10;

			undou += num % 10;
			num = num / 10;

			dou += sum(2 * (num % 10));
			num = num / 10;
		}
		resul = undou + dou;

		if(resul == 0){
			printf("Valid\n");
		}
		else if(resul % 10 == 0){
			printf("Valid\n");
		}
		else{
			printf("Invalid\n");
		}
	}


	return 0;
}