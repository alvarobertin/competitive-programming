#include <stdio.h>
#include <string.h>

int main(){
	int z;	
	while (scanf("%d",&z) != EOF){	
		int Igrid[30], Fgrid[30], i, k, n, sum = 0, temp;
		for (i = 0; i < z; ++i){
			scanf("%d", &Igrid[i]);
		}
		for (i = 0; i < z; ++i){
			scanf("%d", &Fgrid[i]);
		}		
		for (i = z-1; i >= 0; --i){
			for (k = i; k >= 0; --k){
				if(Igrid[i] == Fgrid[k]){
					for (n = k; n < i; ++n){
						temp = Fgrid[n];
						Fgrid[n] = Fgrid[n + 1];
						Fgrid[n + 1] = temp;
						sum += 1;
					}
					break;
				}
			}	
		}		
		printf("%d\n",sum );
	}
	return 0;
}