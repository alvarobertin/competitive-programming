#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	

	char s[1000001], t[1000001];

	int l, i, j, k;

	while(scanf("%s %s", s, t) != EOF){

		j = 0;
		k = 0;

		l = strlen(t);

		for (i = j; i < l; ++i){
			if(s[k] == t[i]){
				k++;
				j = i;

			}
		}

		//printf("%d %d \n", k, strlen(s) );
		if(k == strlen(s)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}