#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

	int L;

	scanf("%d", &L);

	while(L){
		int i, menor = L - 1, t1 = 999999999, t2 = 999999999;
		char car[2000000] = " ";
		scanf("%s",car);

		for (i = 0; i < L; ++i){

			if(car[i] == 'D'){
				t1 = i;
			}
			else if(car[i] == 'R'){
				t2 = i;
			}

			if(car[i] == 'Z'){
				menor = 0;
				break;
			}
			if(fabs(t1 - t2) < menor && t1 != 999999999 && t2 != 999999999){
				//printf("pos D:%d pos R: %d\n",t1,t2 );
				menor = fabs(t1 - t2);
			}

			
 			
		}


		printf("%d\n",menor);

		scanf("%d",&L);
	}
	return 0;

}