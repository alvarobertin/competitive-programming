#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct pro{
	set<string> equi;
	string n;
};


bool compare(pro a, pro b){
	int sa = a.equi.size();
	int sb = b.equi.size();

	if(sa != sb)
		return sa > sb;
	return a.n < b.n;
}

int main(){

	vector<pro> proyes;
	string name;
	vector<string> borrar;

	getline(cin, name);
	
	while(name[0] != '0'){
		proyes.clear();

		while(name[0] != '1' && name[0] != '0'){
			
			pro p;

			p.n = name;

			getline(cin,name);
			while(!(name[0] >= 65 && name[0] <= 90) && name[0] != '1' && name[0] != '0'){
				p.equi.insert(name);
				getline(cin, name);
			} 

			proyes.push_back(p);
		}

		for (int i = 0; i < proyes.size(); ++i){
			borrar.clear();
			for (set<string>::iterator k = proyes[i].equi.begin(); k != proyes[i].equi.end(); ++k){

					for (int j = i + 1; j < proyes.size(); ++j){

						if(!proyes[j].equi.empty() && !proyes[i].equi.empty()){

							if(proyes[j].equi.find(*k) != proyes[j].equi.end()){
								proyes[j].equi.erase(*k);
								borrar.push_back(*k);
							}
						
						}
					}

			}
			for (int x = 0; x < borrar.size(); ++x){
				if(!proyes[i].equi.empty()){
					proyes[i].equi.erase(borrar[x]);
				}
			}

			
		}

		sort(proyes.begin(), proyes.end(), compare);

		for (int i = 0; i < proyes.size(); ++i){
			cout << proyes[i].n << " " << proyes[i].equi.size() << endl;
		}

		getline(cin, name);
	}
	
	return 0;
}