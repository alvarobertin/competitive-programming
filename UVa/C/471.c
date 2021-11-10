#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 9876543210



int check(long long int n){
	int arr[10],i;
	for (i = 0; i < 10; ++i){
		arr[i] = 0;
	}
	while(n > 0){
		arr[n % 10] += 1;
		if(arr[n % 10] > 1){
			return 0;
		}
		n = n/10;
	}
	return 1;
}
int main(){
	int cases = 0;
	long long int num = 0, mul = 1, resul = 0;
	scanf("%d", &cases);

	while(cases--){

		num = 0;
		mul = 1;
		resul = 0;

		scanf("%lld",&num);

		while(resul < MAX){

			resul = mul * num;

			if(check(resul) && check(mul)){
				printf("%lld / %lld = %lld\n",resul ,mul ,num);
			}
			mul++;
		}
		if(cases > 0){
			printf("\n");
		}
	}

	return 0;
}