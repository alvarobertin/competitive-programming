#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;


int main(){

	string r;

	int id, period, max, time = 1;

	map<int, vector<int>> mapa;

	priority_queue<int> imp;

	cin >> r;

	while(r != "#"){
		cin >> id >> period;

		if(mapa.find(period) == mapa.end()){
			vector<int> temp;
			temp.push_back(id);
			mapa[period] = temp;
		}else{
			mapa[period].push_back(id);
		}

		cin >> r;
	}

	cin >> max;

	while(max > 0){

		for (map<int, vector<int>>::iterator it = mapa.begin(); it != mapa.end() ; ++it){
			
			if( time % (*it).first == 0){

				for (int i = 0; i < (*it).second.size(); ++i){
					imp.push((*it).second[i] * -1);
				}

			}

		}

		while(!imp.empty() && max > 0){
			cout << imp.top() * -1 << endl;
			imp.pop();
			max--;
		}

		++time;
	}

	return 0;
}