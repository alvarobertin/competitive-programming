#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h> 
using namespace std;

int main(){
	int G, P, S, Grands[100][100], limpun, cali[100], final[100], mayor, count, temp;
	
	vector<int> ganadores;
	scanf("%d %d", &G, &P);
	while(G){

		for (int i = 0; i < G; ++i){
			for (int j = 0; j < P; ++j){
				
				scanf("%d", &temp);
				Grands[i][temp - 1] = j + 1;
			}
		}

		cin >> S;

		for (int v = 0; v < S; ++v){

			for (int i = 0; i < 100; ++i){
				final[i] = 0;
			}
			
			cin >> limpun;
			for (int i = 0; i < limpun; ++i){
				cin >> cali[i];

				for (int j = 0; j < G; ++j){
					
					final[Grands[j][i]] += cali[i];
				
				}
			

			}
			mayor = 0;
			count = 0;
			for (int i = 0; i < P; ++i){
				if(mayor < final[Grands[0][i]]){
					mayor = final[Grands[0][i]];
					ganadores.clear();
					count = 1;
					ganadores.push_back(Grands[0][i]);
				}
				else if(mayor == final[Grands[0][i]]){
					ganadores.push_back(Grands[0][i]);
					count += 1;
				}


			}

			
			if(count > 1){

				sort(ganadores.begin(), ganadores.end());

				printf("%d", ganadores[0]);
				for (int i = 1; i < count; ++i){
					printf(" %d", ganadores[i]);
				}
				printf("\n");
			}
			else
				printf("%d\n", ganadores[0]);
		}

		scanf("%d %d", &G, &P);

	}

	return 0;
}