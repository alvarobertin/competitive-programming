#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;


int main(){

	int cases, posj, time, jobs, j;

	bool flag;

	queue<int> traba;
	priority_queue<int> first;


	cin >> cases;


	while(cases--){

		while(!traba.empty())
			traba.pop();
		while(!first.empty())
			first.pop();

		flag = false;
		time = 0;
		cin >> jobs >> posj;

		for (int i = 0; i < jobs; ++i){

			cin >> j;
			if(i == posj)
				traba.push(j * -1);
			else
				traba.push(j);

			first.push(j);
			
		}

		while(!flag){

			if(abs(traba.front()) == first.top()){
				time++;
				if(traba.front() < 0)
					flag = true;


				traba.pop();
				first.pop();
			}else{
				traba.push(traba.front());
				traba.pop();
			}

		}

		cout << time << endl;

	}

	return 0;
}