/*http://uva.onlinejudge.org/external/117/11727.pdf*/
#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	int cases, i = 1;
	scanf("%d",&cases);
	while(i <= cases){
		int one,two,three;
		scanf("%d %d %d",&one,&two,&three);
		if((one < two && one > three) || one > two && one < three)
			printf("Case %d: %d\n",i,one);
		else if((two < one && two > three) || two > one && two < three)
			printf("Case %d: %d\n",i,two);
		else
			printf("Case %d: %d\n",i,three);
		i++;
	}
	return 0;
}