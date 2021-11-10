#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

	int cases;
	string order, person;

	stack<string> dreamers; 

	cin >> cases;

	while(cases--){

		cin >> order;

		if(order == "Kick"){

			if(!dreamers.empty())
				dreamers.pop();
		}
		else if(order == "Test"){
			
			if(!dreamers.empty())
				cout << dreamers.top() << endl;
			else
				cout << "Not in a dream" << endl;
		}
		else if(order == "Sleep"){
			cin >> person;
			dreamers.push(person);
		}

	}

	return 0;
}
