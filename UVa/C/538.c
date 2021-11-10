#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ESTA INCOMPLETO */

int getI(char tra[][30], char *nom){
	int i;
	for (i = 0; i < 20; ++i){
		if(strcmp(tra[i], nom) == 0){
			return i;
		}
	}
}




int main(){

	int n, t, i, money[20], mon;

	char trav[20][30], nom1[20], nom2[20];


	scanf("%d %d", &n, &t);

	while(n && t){

		for (i = 0; i < 20; ++i){
			money[i] = 0;
		}

		
		for (i = 0; i < n; ++i){
			scanf("%s", trav[i]);
		}

		for (i = 0; i < t; ++i){
			
			scanf("%s %s %d", nom1, nom2, &mon);	

			money[getI(trav,nom1)] += -mon;

			money[getI(trav,nom2)] += mon;
		
		}

		for (int i = 0; i < n; ++i){
			printf("%s %d\n", trav[i], money[i]);
		}


		scanf("%d %d", &n, &t);
	}






	return 0;
}