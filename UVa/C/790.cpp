#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

struct team{
		int t;
		map<char, int> probl_time;
		map<char, char> accepted;
		map<char, int> mint_probl;
		int nAccept;
		int time;
};
bool compare(team a, team b){

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
int main(){
	
	int h,m,n, cases;
	char d,p;
	string in;
	vector<string> lineas;
	set <int> pro, tempset;
	team teams[26], temp;

	scanf("%d\n\n", &cases);
	while(cases--){
	
		lineas.clear();
		for (int i = 0; i < 26; ++i){
			teams[i].time = 0;
			teams[i].nAccept = 0;
			teams[i].t = 0;
			teams[i].probl_time.clear();
			teams[i].accepted.clear();
			teams[i].mint_probl.clear();	
		}
		pro.clear();
		tempset.clear();
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
			teams[n].t = n;
			pro.insert(n);
			if(teams[n].accepted[p] != 'Y'){
				if(d == 'N'){
					teams[n].probl_time[p] += 20;
				}else{
					teams[n].probl_time[p] += h*60 + m;
					teams[n].accepted[p] = d;
				}				
			}
		}
		for (int i = 1; i <= 25; ++i){
				
				map<char, char>::iterator it;

				for ( it = teams[i].accepted.begin(); it != teams[i].accepted.end(); it++ ){
					if(it->second == 'Y' && it->first < 'Z'){
						teams[i].time += teams[i].probl_time[it->first];
						teams[i].nAccept += 1;
					} 
				}
				
		}

		sort(teams + 1, teams + 26, compare);
		cout << "RANK TEAM PRO/SOLVED TIME\n";

		int acum = 0;
		int rank = 1;
		int i = 1;
		tempset = pro;

		for (i = 1; i <= pro.size(); ++i){
			if(teams[i].time == teams[i + 1].time){
				if(teams[i].nAccept != 0){
					printf("%4d %4d %4d %10d\n", rank, teams[i].t, teams[i].nAccept, teams[i].time);
					tempset.erase(teams[i].t);
					acum += 1;
				}
				
			}
			else{
				
				if(teams[i].nAccept != 0){
						
					printf("%4d %4d %4d %10d\n", rank, teams[i].t, teams[i].nAccept, teams[i].time);
					tempset.erase(teams[i].t);
					rank += acum;
				}
				rank++;
				acum = 0;
			}
		}
		bool is_in, is_in1;
		rank += acum;
		for (int j = 1; j <= 25; ++j, ++i){
			
			is_in = tempset.find(j) != tempset.end();
			is_in1 = pro.find(j) != pro.end();
			if((is_in && j <= *pro.rbegin() )|| (!is_in1 && j <= *pro.rbegin())){
					printf("%4d %4d\n", rank, j);
			}
		}
		if(cases)
			cout << "\n";
	
	}

	return 0;
}
