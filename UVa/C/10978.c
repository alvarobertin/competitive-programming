/*https://uva.onlinejudge.org/external/109/10978.pdf*/
#include <stdio.h>
#include <math.h>
#include <string.h>
/*La complejidad es O(n) */
int main(void){
	int cases = 1;
	while( cases != 0){
		char cards[1500], word[1500], result[99][99];
		char temp[1500];
		int pos,i,z,index = -1;		
		scanf("%d",&cases);
		for (i = 0; i < cases; ++i){
      		strcpy(result[i], "W");
		}
		for (i = 0; i < cases; ++i){
			scanf("%s %s",cards, word);
			pos = strlen(word);
			z = 0;
			while(z < pos){
				if(index >= cases){
					index = 0;
				}
				++index; 
				while(strcmp(result[index],"W") != 0){
					++index; 
					if(index >= cases){
						index = 0;
					}
				}
				++z;
			}		
      		strcpy(result[index], cards);
		}
		for (i = 0; i < cases; ++i){
			if(i < cases - 1)
				printf("%s ",result[i]);
			else
				printf("%s",result[i]);
		}
		if(cases != 0)	
			printf("\n");
	}
	return 0;
}
