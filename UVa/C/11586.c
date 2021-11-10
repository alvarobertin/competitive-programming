#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

	int cases, l, i, flag = 0, F, M;
	char track[200], temp;

	scanf("%d\n", &cases);


	while(cases--){

		flag = 0;
		F = 0;
		M = 0;
		fgets(track, 200, stdin);

		l = strlen(track);
		if(l > 3){
			for (i = 0; i < l; ++i){
				if(track[i] == 'F'){
					F += 1;

				}
				else if(track[i] == 'M'){
					M += 1;
				}
			}
		}
		else{
			F = 0;
			M = 1;
		}
		if(F != M)
			printf("NO LOOP\n");
		else
			printf("LOOP\n");



	}



	return 0;
}










/*
				if(temp == 'F' && track[i] == 'M'){
					flag = 0;
					temp = track[i + 1];
					++i;
				}
				else if(temp == 'M' && track[i] == 'F'){
					flag = 0;
					temp = track[i + 1];
					++i;
				} 
				else{
					flag = 1;
					break;
				}

*/