#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(char *p, int a, int G, int n){
	int i = 0;
	char temp;
	while(i < n/2){
		temp = p[a];
		p[a] = p[G-i];
		p[G-i] = temp;
		i++;
		a++;
	}
	
}
int main(){

	int G;
	
	scanf("%d", &G);
	while(G){
		
		int i,l,n;
		char pal[101] = {};

		scanf("%s", &pal);
		l = strlen(pal);
		n = l/G;
		for (i = 0; i < l; i+=n){
			
			sort(pal, i, i+n-1, n);	
		}

		printf("%s\n", pal);
		
		scanf("%d", &G);
	
	}
	return 0;
}