#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){

	int cases, M, Q, l, mayor, resu, moviMax, ltem, z;
	
	vector<string> movis;
	string temp;
	cin >> M >> Q;

	for (int i = 0; i < M; ++i){
		cin >> temp;
		movis.push_back(temp);
	}
	for (int i = 0; i < Q; ++i){
		mayor = 0;
		cin >> temp;
		ltem = temp.length();
		for (int j = 0; j < M; ++j){
			l = movis[j].length();
			if(l >= ltem){
				for (int x = 0; x < l; ++x){
					resu = 0;
					if(x > (l - ltem))
						break;
					for (int y = 0, z = x; y < ltem && z < l; ++y, ++z){
						if(movis[j][z] == temp[y]){
							resu += 1;
						}
					}
					//printf("j %d x %d resu %d mayor %d\n", j,x,resu,mayor);
					if (resu > mayor){
						mayor = resu;
						moviMax = j;
					}
					else if(resu == mayor){
						mayor = resu;
						moviMax = (j < moviMax) ? j : moviMax;
					}
				}
			}	
		}
		printf("%d\n", moviMax + 1);

	}

	return 0;
}