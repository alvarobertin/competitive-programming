#include <iostream>
#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

int main(){

	int people, commands, n , count, cases = 1;

	char option;

	list<int> cola;

	cin >> people >> commands;

	while(people){

		count = 1;

		cola.clear();

		for (int i = 1; i <= min(1000, people); ++i)
			cola.push_back(i);

		printf("Case %d:\n", cases++);
		
		for (int i = 0; i < commands; ++i){
			cin >> option;

			if(option == 'N'){

				cola.push_back(cola.front());
				cout << cola.front() << endl;
				cola.pop_front();
			}
			else if(option == 'E'){
				cin >> n;
				cola.remove(n);
				cola.push_front(n);
			}
		}
		
		cin >> people >> commands;
	}

	return 0;
}