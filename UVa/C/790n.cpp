#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

struct team{
		int t;
		int problemsT[30];
		int nAccept;
		int time;
};

bool compare(team a, team b){
	/*Ordena los equipos respecto al numero de aceptados, tiempo y numero de equipo.*/
	if(a.t == 0){
		return 0;
	}

	if(a.nAccept != b.nAccept){
		return a.nAccept > b.nAccept;
	}

	if(a.time != b.time){
		return a.time < b.time;
	}
	if(a.t != b.t){
		return a.t < b.t;
	}

	return false;
}

bool order(string a, string b){
	/*Ordena las lineas del input respecto al tiempo.*/
	int n, h1, m1, h2, m2, atotal, btotal;
	char p,d1,d2;
	sscanf(a.c_str(), "%d %c %d:%d %c", &n, &p, &h1, &m1, &d1);

	sscanf(b.c_str(), "%d %c %d:%d %c", &n, &p, &h2, &m2, &d2);
	atotal = h1*60 + m1;
	btotal = h2*60 + m2;

	if(atotal != btotal){
		return atotal < btotal;
	}

	if(d1 == 'Y' && d2 == 'N'){
		return false;
	}
	if(d1 == 'N' && d2 == 'Y'){
		return true;
	}
	return false;
}

int findmax(team maxt[]){
	/*Encuentra el mayor equipo.*/
	int mx = -1; 
    for (int i = 0; i < 26; i++) { 
        int temp = maxt[i].t; 
        mx = max(mx, temp); 
    } 
    return mx; 
}
int main(){
	
	int h,m,n, cases, equipos[30];
	char d,p;
	string in;
	vector<string> lineas;

	team teams[30], temp;

	scanf("%d\n\n", &cases);
	while(cases--){
		lineas.clear();
		for (int i = 0; i < 26; ++i){
			teams[i] = {};
			equipos[i] = 0;
		}
		while(getline(cin, in)){
			if(in == ""){
				break;
			}
			lineas.push_back(in);
		}

		sort(lineas.begin(),lineas.end(), order);

		vector<string>::iterator it;

		for ( it = lineas.begin(); it != lineas.end(); it++ ){
		
			sscanf((*it).c_str(), "%d %c %d:%d %c", &n, &p, &h, &m, &d);

		    int letra = p - 65;

		   	teams[n].t = n;
		    if (teams[n].problemsT[letra] >= 0){
		    	if(d == 'Y' && p >= 'A' && p <= 'G'){
		    		teams[n].problemsT[letra] += h*60 + m;
		    		teams[n].nAccept += 1;
		    		teams[n].time += teams[n].problemsT[letra];
		    		teams[n].problemsT[letra] *= -1;
		    		if(teams[n].problemsT[letra] == 0){
		    			teams[n].problemsT[letra] = -1;
		    		}
		    	}
		    	else{
		    		teams[n].problemsT[letra] += 20;
		    	}
		    }
		}


		sort(teams + 1, teams + 26, compare);
		cout << "RANK TEAM PRO/SOLVED TIME\n";

		int acum = 0;
		int rank = 1;
		int i = 1;

		int max = findmax(teams);
		//cout << max << endl;
		for (i = 1; i <= 25; ++i){
			if(teams[i].nAccept != 0){
				if(teams[i].time == teams[i + 1].time){
						printf("%4d %4d %4d %10d\n", rank, teams[i].t, teams[i].nAccept, teams[i].time);	
						acum += 1;
				}
				else{
					printf("%4d %4d %4d %10d\n", rank, teams[i].t, teams[i].nAccept, teams[i].time);	
					rank += acum;
					rank++;
					acum = 0;
				}
				equipos[teams[i].t] = 1;
			}

		}		
		rank += acum;
		for (int j = 1; j <= 26; ++j){
			if(equipos[j] != 1 && j <= max){
					printf("%4d %4d\n", rank, j);
			}
		}
		if(cases)
			cout << "\n";
	
	}

	return 0;
}
