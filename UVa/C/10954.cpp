#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main(){
	long long int temp, n1, n2, ans;
	int num;
	cin >> num;
	while(num){
		ans = 0;
		n1 = 0;
		n2 = 0;
		priority_queue<long long int> cola;

		for (int i = 0; i < num; ++i){
			cin >> temp;
			cola.push(temp * -1);
		}

		while(cola.size() > 1){
			n1 = cola.top();
			cola.pop();
			n2 = cola.top();
			cola.pop();
			ans += n1 + n2;
			cola.push(n1 + n2);
		}

		cout << ans * -1 << endl;

		cin >> num;
	}

	return 0;
}