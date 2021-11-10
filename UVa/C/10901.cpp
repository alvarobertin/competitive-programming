#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string change(string ubi){
	if(ubi == "left")
		return "right";
	else
		return "left";
}


int main(){


	int cases, max, moves, demora, t, tiempo, counter;
	string ubi, d;

	bool flag;

	queue< pair<int, int> > der;
	queue< pair<int, int> > izq;

	vector<int> res(10000);

	pair<int, int> car;

	cin >> cases;

	while(cases--){

		while(!der.empty())
			der.pop();
		while(!izq.empty())
			izq.pop();

		flag = false;

		ubi = "left";

		cin >> max >> demora >> moves;

		for (int i = 0; i < moves; ++i){
			cin >> t >> d;
			car.first = t;
			car.second = i;
			
			if(d == "right"){
				der.push(car);
			}
			else if(d == "left"){
				izq.push(car);
			}

		}
				
		tiempo = 0;
		flag = false;
		while(!(izq.empty() && der.empty())){

			counter = 0;

			if(!izq.empty() && !der.empty()){

				if(izq.front().first <= tiempo && ubi == "left"){
					flag = true;

				}else if(der.front().first <= tiempo && ubi == "right"){
					flag = true;

				}else if(izq.front().first <= tiempo){
					ubi = change(ubi);
					tiempo += demora;

				}else if(der.front().first <=  tiempo){
					ubi = change(ubi);
					tiempo += demora;
				}else{
					tiempo++;
				}

			}else if(!izq.empty()){

				if(ubi != "left"){
					ubi = change(ubi);
					tiempo += demora;
				}
				else if(izq.front().first <= tiempo && ubi == "left"){
					flag = true;

				}else{
					tiempo++;
				}

			}else if(!der.empty()){

				if(ubi != "right"){
					ubi = change(ubi);
					tiempo += demora;
				}
				else if(der.front().first <= tiempo && ubi == "left"){
					flag = true;

				}else{
					tiempo++;
				}
			}


			if(flag){
				if(ubi == "left"){
					for (int i = 0; i < max; ++i){
						if(!izq.empty()){
							if(izq.front().first <= tiempo){
								res[izq.front().second] = tiempo + demora;
								izq.pop();
							}else
								break;							
						}

					}
				}else{
					for (int i = 0; i < max; ++i){
						if(!der.empty()){
							if(der.front().first <= tiempo){
								res[der.front().second] = tiempo + demora;
								der.pop();
							}else
								break;
						}
					}
				}

				flag = false;
				ubi = change(ubi);
				tiempo += demora;
			}
			
		}


		for (int i = 0; i < moves; ++i){
			cout << res[i] << endl;
		}

		if(cases)
			cout << endl;

	}


	return 0;
}



/*

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string change(string ubi){
	if(ubi == "left")
		return "right";
	
	return "left";
}


int main(){

	int cases, max, moves, demora, t, tiempo, counter;
	string ubi, d;

	bool flag;

	queue<pair<int, string> > barcos;

	pair<int, string> car;

	cin >> cases;

	while(cases--){
		flag = false;

		ubi = "left";

		cin >> max >> demora >> moves;

		for (int i = 0; i < moves; ++i){
			cin >> t >> d;
			car.first = t;
			car.second = d;
			barcos.push(car);
		}

		tiempo = 0;
		while(!barcos.empty()){

			counter = 0;
			flag = false;


			if(barcos.front().second != ubi && barcos.front().first > tiempo){
				tiempo += (barcos.front().first - tiempo);
				tiempo += demora;
				ubi = change(ubi);
				
			}
			else if(barcos.front().second == ubi && barcos.front().first > tiempo){
				tiempo += (barcos.front().first - tiempo);
				
			}
			else if(barcos.front().second != ubi && barcos.front().first <= tiempo){
				tiempo += demora;
				ubi = change(ubi);
				

			}

			for (int i = 0; i < max; ++i){
				if(!barcos.empty()){
					if(barcos.front().second == ubi && barcos.front().first <= tiempo){
						
						barcos.pop();
						flag = true;
					}
					else
						break;
					
					counter++;
					
				}

			}

			if(flag){
				tiempo += demora;
				ubi = change(ubi);
				for (int i = 0; i < counter; ++i){
					cout << tiempo << endl;
				}
			}

		}
		if(cases)
			cout << endl;

	}


	return 0;
}



*/