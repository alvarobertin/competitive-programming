#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include<bits/stdc++.h>

using namespace std;

void s(int *a, int *b){ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 
void sn(string *a, string *b){ 
	string temp = *a; 
	*a = *b; 
	*b = temp; 
} 

int main(){


	int npla, aux, cases = 1;
	vector<int> puntos(101,0);
	vector<string> names;
	string auxn, auxn2;
	char letra;

	while(scanf("%d", &npla) != EOF){
		vector<int> puntos(101,0), modi(101,0);
		vector<string> names;
		string auxn, auxn2;
		for (int i = 0; i < npla; ++i){
			letra = ' ';
			auxn.clear();
			while(letra != ';'){
				scanf("%c", &letra);
				if(letra != ';')
					auxn.push_back(letra);
			}
			names.push_back(auxn);

			for (int j = 0; j < 5; ++j){
				scanf("%d", &aux);
				modi[j] = aux;
				if(j == 4 && aux){
					modi[j] += 1;
				}
			}
			scanf(";");
			for (int j = 5; j < 10; ++j){
				scanf("%d", &aux);
				modi[j] = aux;
				if(j == 9 && aux){
					modi[j] += 1;
				}
			}
			scanf(";");
			for (int j = 10; j < 15; ++j){
				scanf("%d", &aux);
				modi[j] = aux;
				if(j == 14 && aux){
					modi[j] += 1;
				}
			}
			scanf(";");

			for (int j = 15; j < 20; ++j){
				scanf("%d", &aux);
				modi[j] = aux;
				if(j == 19 && aux){
					modi[j] += 1;
				}
			}
			scanf(";");


			for (int j = 20; j < 25; ++j){
				scanf("%d", &aux);
				modi[j] = aux;
				if(j == 24 && aux){
					modi[j] += 1;
				}
			}

			puntos[i] = accumulate(modi.begin(), modi.end(), 0);	
		}

	   /*Bubble sort*/
		for (int i = 0; i < npla-1; i++){         
			for (int j = 0; j < npla-i-1; j++){  
				if (puntos[j] < puntos[j+1]){ 
				 
					s(&puntos[j], &puntos[j+1]);
					sn(&names[j], &names[j+1]);
				}
				else if(puntos[j] == puntos[j+1]){
					auxn = names[j];
					auxn2 = names[j + 1];
					transform(auxn.begin(), auxn.end(), auxn.begin(), ::tolower); 
					transform(auxn2.begin(), auxn2.end(), auxn2.begin(), ::tolower); 	            	
					if(auxn > auxn2){
					  s(&puntos[j], &puntos[j+1]);
					  sn(&names[j], &names[j+1]);	            		
					}
				}
			} 
		}

		printf("Case %d:", cases++);
		for (int i = 0; i < npla; ++i){
			cout << names[i] << " " << puntos[i];
		}
		printf("\n");
	}


	return 0;
}