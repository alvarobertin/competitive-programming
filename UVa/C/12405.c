/*https://uva.onlinejudge.org/external/124/12405.pdf*/
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void)
{
	int cases,n = 1;
	scanf("%d",&cases);

	while(n <= cases){
		int f,i,s = 0;
		char g[101];
		scanf("%d",&f);
		scanf("%s",g);
		for (i = 0; i < f; i += 1){
			if(g[i] == '.' && g[i+1] == '.' && g[i+2] == '.'){
				s += 1;
				i += 2;
			}
			else if (g[i] == '.' && g[i+1] == '#' && g[i+2] == '.'){
				s += 1;
				i += 2;
			}
			else if(g[i] == '.' && g[i+1] == '.'){
				s += 1;
				i += 1;
			}
			else if(g[i] == '.'){
				s += 1;
			}
		}
		
		printf("Case %d: %d\n",n,s);
		n++;
	}
	return 0;
}