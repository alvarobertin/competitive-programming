#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main(){

	string carta ,temp;

	int siz;

	vector<stack<string>> cartas;

	stack<string> cart;

	cin >> carta;
	cart.push(carta);
	cartas.push_back(cart);
	cart.pop();

	while(carta != "#"){

		for (int i = 0; i < 51; ++i){
			cin >> carta;
			cart.push(carta);
			cartas.push_back(cart);
			cart.pop();
		}


		for ( int i = 0; i < cartas.size(); ++i){
			if(i >= 3){
				if(cartas[i].top()[0] == cartas[i - 3].top()[0] || cartas[i].top()[1] == cartas[i - 3].top()[1]){

					temp = cartas[i].top();
					cartas[i].pop();

					cartas[i - 3].push(temp);


					if(cartas[i].empty()){
						cartas.erase(cartas.begin() + i);
					}

					i = i - 4;

				}
				else if(cartas[i].top()[0] == cartas[i - 1].top()[0] || cartas[i].top()[1] == cartas[i - 1].top()[1]){
					
					temp = cartas[i].top();
					cartas[i].pop();

					cartas[i - 1].push(temp);


					if(cartas[i].empty()){
						cartas.erase(cartas.begin() + i);
					}

					i = i - 2;

				}
			}else if(i >= 1){

				if(cartas[i].top()[0] == cartas[i - 1].top()[0] || cartas[i].top()[1] == cartas[i - 1].top()[1]){
					
					temp = cartas[i].top();
					cartas[i].pop();

					cartas[i - 1].push(temp);


					if(cartas[i].empty()){
						cartas.erase(cartas.begin() + i);
					}

					i = i - 2;

				}
			}
		}
		siz = cartas.size();

		if(siz > 1)
			cout << siz << " piles remaining:";
		else
			cout << siz << " pile remaining:";
		


		for (int i = 0; i < siz; ++i){
			cout << " " << cartas[i].size();
		}
		cout << endl;


		cartas.clear();

		cin >> carta;
		cart.push(carta);
		cartas.push_back(cart);
		cart.pop();		
	} 


	return 0;
}