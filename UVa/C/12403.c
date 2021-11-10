/*https://uva.onlinejudge.org/external/124/12403.pdf*/
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
	
	int cases, mon, total = 0;
	scanf("%d",&cases);
	char act[10];
	while(cases--){
		scanf("%s %d",act, &mon);
		if(strcmp(act,"donate")==0){
			total += mon;
		}
		else if(strcmp(act,"report")==0){
			printf("%d\n",total);
		}
	}
	return 0;
}