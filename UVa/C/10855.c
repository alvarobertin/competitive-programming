#include <stdio.h>
#include <stdlib.h>
#include <string.h>

		/*
		for (int i = 0; i <= N; ++i){
			for (int j = 0; j <= N; ++j){
				printf(" %c",mat[i][j] );
			}
			printf("\n");
		}
		*/

void rotate(char mat[][101], int n){
	int cuadrados = n/2, i = 0, k = 0;
	char temp;
	n--;
	while(k < cuadrados){
		for (i = k; i < n; ++i){
			temp = mat[0 + k][i];
			mat[0 + k][i] = mat[n - i][0 + k];
			mat[n - i][0 + k] = mat[n][n - i];
			mat[n][n - i] = mat[i][n];
			mat[i][n] = temp;   
		}
		++k;
		--n;
	}
}

int main(){
	int n, N;

	scanf("%d %d", &N, &n);

	while(N && n){
		int i, k, x, y, flag, r = 0, r0 = 0, r90 = 0, r180 = 0, r270 = 0;
		char Big[101][101], Sma[101][101];

		for (i = 0; i < N; ++i){
			scanf("%s",Big[i]);	
		}
		for (i = 0; i < n; ++i){
			scanf("%s",Sma[i]);	
		}
		for (r = 0; r <= 270; r += 90){
			for (i = 0; i <= N-n; ++i){
				for (k = 0; k <= N-n; ++k){
					if(Big[i][k] == Sma[0][0]){
						flag = 1;
						for (x = 0; x < n; ++x){
							for (y = 0; y < n; ++y){
								if(Big[i + x][k + y] != Sma[x][y]){
									flag = 0;
									break;
								}
							}
							if(!flag)
								break;
						}
						if(flag){
							if(r == 0)
								r0 += 1;
							else if(r == 90)
								r90 += 1;
							else if(r == 180)
								r180 += 1;
							else if(r == 270)
								r270 += 1;
						}
					}
				}
			}
			rotate(Sma,n);
		}
		printf("%d %d %d %d\n", r0, r90, r180, r270);
		scanf("%d %d", &N, &n);
	}

	return 0;
}