#include <stdio.h>
#include <string.h>
int main(){
	int i = 1;
	char pal[5];
	while(strcmp(pal,"*")!=0){
		scanf("%s",pal);
		if(strcmp(pal,"Hajj")==0){
			printf("Case %d: Hajj-e-Akbar\n",i);
		}
		else if(strcmp(pal,"Umrah")==0){
			printf("Case %d: Hajj-e-Asghar\n",i);
		}
		i++;
	}
	return 0;
}
