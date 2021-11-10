/*https://uva.onlinejudge.org/external/1/102.pdf*/
#include <stdio.h>
#include <string.h>

int main(){
	int z;	
	while (scanf("%d",&z) != EOF){	
		unsigned int in[9],a[3],b[3],c[3],menor = 4294967295, suma = 0;
		char res[4] = {""}, temp[4] = {""},comp[] = "BGCBGCBGC";
		int i,k,n;
		in[0] = z;
		for (i = 1; i < 9; ++i){
			scanf("%d",&in[i]);
		}
		a[0] = in[3] + in[6];
		a[1] = in[4] + in[7];
		a[2] = in[5] + in[8];
		b[0] = in[0] + in[6];
		b[1] = in[1] + in[7];
		b[2] = in[2] + in[8];
		c[0] = in[0] + in[3];
		c[1] = in[1] + in[4];
		c[2] = in[2] + in[5];
		for (i = 0; i <= 2; ++i){
			for (k = 0; k <= 2; ++k){
				if(i != k){
					for (n = 0; n <= 2; ++n){
						if(k != n && i != n){
							suma = a[i] + b[k] + c[n];
							if(suma < menor){
								res[0] = comp[i];
								res[1] = comp[k];
								res[2] = comp[n];
								menor = suma;
							}
							else if(suma == menor){
								temp[0] = comp[i];
								temp[1] = comp[k];
								temp[2] = comp[n];
								if(strcmp(res,temp) > 0){
									strcpy(res,temp);
								}
							}
						}
					}
				}
			}
		}

		printf("%s %lu\n",res,menor);
	}
	return 0;
}