#include <string.h>
#include <stdio.h>


int main(){

	int L;

	scanf("%d", &L);

	while(L){
		int i, menor = L-1, flag = 0, count = 0, prim = 1;
		char car[2000000] = " ", ant = '\0';


			scanf("%s",car);


		for (i = 0; i < L; ++i){
			if(flag){
				count += 1;	
			}
			if(car[i] == 'D'|| car[i] == 'R' ){
				//printf("count: %d\n",count);
				//printf("menor: %d\n",menor );
				flag = 1;
				if((car[i] == 'D' && ant == 'R') || (car[i] == 'R' && ant == 'D')){
					if(count < menor){
						menor = count; 
						count = 0;
						//printf(" if count: %d  menor: %d\n", count, menor );
					}
					flag = 1;
				}	
				else{
					count = 0;
				}
				if (car[i] == 'D'){
					ant = 'D';
				}
				else if (car[i] == 'R'){
					ant = 'R';
				}
			}
			else if(car[i] == 'Z'){
				menor = 0;
				break;
			}


				 
		}


		printf("%d\n",menor);

		scanf("%d",&L);
	}

	return 0;
}