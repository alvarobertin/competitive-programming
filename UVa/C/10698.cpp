#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


struct team{

	int points;
	int Goals;
	int Bajas;
	int DF;
	string name;
	int pos;
	int numPart;
	
};


bool compare(team a, team b){
	string auxn, auxn2;
	auxn = a.name;
	auxn2 = b.name;

	transform(auxn.begin(), auxn.end(), auxn.begin(), ::tolower); 
	transform(auxn2.begin(), auxn2.end(), auxn2.begin(), ::tolower); 
	if(a.points != b.points)
		return a.points > b.points;

	if(a.DF != b.DF)
		return a.DF > b.DF;

	if(a.Goals != b.Goals)
		return a.Goals > b.Goals;
	else
		return auxn < auxn2;

}


int main(){


	int T, G, g1, g2, p1, p2, rank;

	string nombre, home, away;

	vector<team> vecTeams(30);

	cin >> T >> G;

	while(T){
		p1 = 0;
		p2 = 0;
			vecTeams[0].points = -1;
		for (int i = 1; i < 30; ++i){
		
			vecTeams[i].points = 0;
			vecTeams[i].Goals = 0;
			vecTeams[i].DF = 0;
			vecTeams[i].name = "";
			vecTeams[i].pos = 0;
			vecTeams[i].numPart = 0;
			vecTeams[i].Bajas = 0;
		}

		for (int i = 1; i <= T; ++i){
			
			cin >> nombre;
			vecTeams[i].name = nombre;

		}

		for (int i = 0; i < G; ++i){
			
			cin >> home;
			scanf(" %d - %d\n", &g1, &g2);
			cin >> away;


			if(g1 > g2){
				p1 = 3;
				p2 = 0;
			}else if(g2 > g1){
				p2 = 3;
				p1 = 0;
			}else{
				p1 = 1;
				p2 = 1;
			}

			for (int j = 1 ; j <= T; ++j){
				if(vecTeams[j].name == home){

					vecTeams[j].points += p1;
					vecTeams[j].Goals += g1;
					vecTeams[j].DF += (g1 - g2);
					vecTeams[j].numPart += 1;
					vecTeams[j].Bajas += g2;


				}else if(vecTeams[j].name == away){

					vecTeams[j].points += p2;
					vecTeams[j].Goals += g2;
					vecTeams[j].DF += (g2 - g1);
					vecTeams[j].numPart += 1;
					vecTeams[j].Bajas += g1;
				}
			}

		}


		sort(vecTeams.begin() + 1, vecTeams.begin() + T + 1, compare);

		double per, uno, dos;

		rank = 1;

		string perr = "N/A";

		for (int i = 1; i <= T; ++i){

			uno = (float) vecTeams[i].points;
			dos = (float) vecTeams[i].numPart*3;
			per =  (uno/dos)*100.00;


			if(vecTeams[i].points == vecTeams[i - 1].points && vecTeams[i].DF == vecTeams[i - 1].DF && vecTeams[i].Goals == vecTeams[i - 1].Goals){
				if(!uno && !dos)
					printf("%19s %3d %3d %3d %3d %3d %6s\n", vecTeams[i].name.c_str(), vecTeams[i].points, vecTeams[i].numPart, vecTeams[i].Goals, vecTeams[i].Bajas, vecTeams[i].DF, perr.c_str());		
				else
					printf("%19s %3d %3d %3d %3d %3d %6.2lf\n", vecTeams[i].name.c_str(), vecTeams[i].points, vecTeams[i].numPart, vecTeams[i].Goals, vecTeams[i].Bajas, vecTeams[i].DF, per);		
				rank++;
			}else{
				if(!uno && !dos)
					printf("%2d.%16s %3d %3d %3d %3d %3d %6s\n", rank, vecTeams[i].name.c_str(), vecTeams[i].points, vecTeams[i].numPart, vecTeams[i].Goals, vecTeams[i].Bajas, vecTeams[i].DF, perr.c_str());

				else
					printf("%2d.%16s %3d %3d %3d %3d %3d %6.2lf\n", rank, vecTeams[i].name.c_str(), vecTeams[i].points, vecTeams[i].numPart, vecTeams[i].Goals, vecTeams[i].Bajas, vecTeams[i].DF, per);

				rank++;

			}
		}
		cin >> T >> G;
		if(T)
			cout << "\n";
	}




	return 0;
}