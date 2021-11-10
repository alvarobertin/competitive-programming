#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*La complejidad del algoritmo es O(n^2), siendo n la cantidad de puntos en la grafica*/

int compare(const void *a, const void *b){
  if (*(double*)a > *(double*)b) return 1;
  else if (*(double*)a < *(double*)b) return -1;
  else return 0;  
}


int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		int co,i,k,j,z;
		scanf("%d",&co);
		double x[100],xc[100],y[100],p[100],temp,res[100] = {},count = 1.0;	
		for (i = 0; i < co*2; i+=2){
			scanf("%lf %lf %lf %lf %lf",&x[i],&y[i],&x[i+1],&y[i+1],&p[i+1]);
		}		

		memcpy(xc,x,sizeof(x));
		qsort(xc,co*2,sizeof(xc[0]),compare);
		j = 0;
		for (i = 0; i < co*2; ++i){
			temp = (xc[i] + xc[i+1])/2;
			count = 1.0;
			for (z = 0; z < co*2; z+=2){
				if(x[z] < x[z+1]){
					if(temp >= x[z] && temp <= x[z+1]){
						count *= p[z+1];		
					}	
				}else{
					if(temp <= x[z] && temp >= x[z+1]){
						count *= p[z+1];		
					}					
				}
			}
			res[j] = count;
			j++;
		}
		k = 0;
		printf("%d\n",co*2+1);
		printf("-inf %.3lf 1.000\n",xc[0]);
		for (i = 0; i < co*2-1; ++i){
			printf("%.3lf %.3lf %.3lf\n",xc[i],xc[i+1],res[i]);
			k+=2;
		}
		printf("%.3lf +inf 1.000\n",xc[co*2-1]);
		if (cases){
			printf("\n");
		}
	}
	
	return 0;
}