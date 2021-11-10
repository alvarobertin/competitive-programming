#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX1 97865
#define MAX2 1234

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
int check2(int n, int s){
	int arr[10],i;
	for (i = 0; i < 10; ++i){
		arr[i] = 0;
	}
	while(n > 0 && s > 0){
		arr[n % 10] += 1;
		arr[s % 10] += 1;
		if(arr[n % 10] > 1 || arr[s % 10] > 1){
			return 0;
		}
		n = n/10;
		s = s/10;
	}
	return 1;
}

int main(){
	int num = 0;
	long long int up = MAX1, down = MAX2, flag = 0, fdown = 0, fup = 0, f = 0;
	scanf("%d", &num);

	while(num){

		up = MAX1;
		down = MAX2;
		flag = 1;
		fdown = 0;
		fup = 0;

		while(down <= MAX1){

			up = down * num;
			if(up > 98765){
        		break;
      		}
      		if(up > 10000){
			    fup = check(up);
			    fdown = check(down);

			    f = check(up*100000 + down);
				if(f && fup && fdown){
					flag = 0;
					printf("%lld / %05lld = %d\n", up, down, num);
				}
			}
		
			down++;
		}

		if(flag)
			printf("There are no solutions for %d.\n",num);

		scanf("%d", &num);
		
		if(num){
			printf("\n");
		}
	}

	return 0;
}