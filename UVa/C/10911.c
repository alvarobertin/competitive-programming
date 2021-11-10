#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


double dist(double x1, double y1, double x2, double y2){

	double res;

	res = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

	res = sqrt(res);

	return res;
}



int main(){
	


	double x[16], y[16], temp, menor = 10000000000000000;
	int N, i;
	char s[16][21];

	scanf("%d", &N);

	while(N){

		for (i = 0; i < N * 2; ++i){
			
			scanf("%s %d %d", s[i], x[i], y[i]);

		}


		for (i = 0; i < N * 2; ++i){
			
			for (j = i + 1; j < N * 2; ++j){
				
				temp = dist(x[i], y[i], x[j], y[j]);
				
				menor = (temp < menor) ? temp : menor;

				

			}


		}



		scanf("%d", &N);
	}






	return 0;
}