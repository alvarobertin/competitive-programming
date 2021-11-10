#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void change(char grd[][11], int n, int i, int j){
	int u, d, r, l, k;
	
	u = (i - 1 >= 0 && grd[i - 1][j] != '.') ? grd[i - 1][j] : 0;
	d = (i + 1 < n && grd[i + 1][j] != '.') ? grd[i + 1][j] : 0;
	r = (j + 1 < n && grd[i][j + 1] != '.') ? grd[i][j + 1] : 0;
	l = (j - 1 >= 0 && grd[i][j - 1] != '.') ? grd[i][j - 1] : 0;
	//printf("u %d, d %d, r %d , l %d\n",u,d,r,l );
	for (k = 65; k <= 90; ++k){
		if(k != u && k != d && k != r && k != l){
			
			grd[i][j] = k;
			//printf("%c\n",grd[i][j]);
			break;
		}
	}
}


int main(){

	int x, cases, n, i, j;

	char grid[10][11];

	scanf("%d", &cases);

	for (x = 1; x <= cases; ++x){
		
		scanf("%d", &n);

		for (i = 0; i < n; ++i){
			scanf("%s", grid[i]);
		}

		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j){
				if(grid[i][j] == '.'){
					
					change(grid, n, i, j);
				}
			}
		}


		printf("Case %d:\n", x);

	
		for (i = 0; i < n; ++i){
			printf("%s\n", grid[i]);
		}



	}
	return 0;
}