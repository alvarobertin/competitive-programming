/*https://uva.onlinejudge.org/external/132/13216.pdf*/
#include <stdio.h>
#include <math.h>
#include <string.h>
/*La complejidad del algoritmo es O(1)*/
int main(void){
	char num[1002];
	int cases,l,result = 0,i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",num);
		l = strlen(num);
		if(num[0] == '1' && l == 1){
			result = 66;
		}
		else if(num[0] == '0' && l == 1){
			result = 1;
		}
		else{
			i = num[l-1];
			switch(i){
				case '0':
					result = 76;
					break;
				case '1':
					result = 16;
					break;
				case '2':
					result = 56;
					break;
				case '3':
					result = 96;
					break;
				case '4':
					result = 36;
					break;
				case '5':
					result = 76;
					break;

				case '6':
					result = 16;
					break;
				case '7':
					result = 56;
					break;
				case '8':
					result = 96;
					break;
				case '9':
					result = 36;
					break;					
			}
		}	
			printf("%d\n",result);
	}
	return 0;
}
	