#include <iostream>

#define endl "\n"

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int m;
		int a, c;
		cin >> m;
		cin >> a >> c;
		string name;
		cin >> name;

		if(name == "Alice" && c == a) cout << "CARL" << endl;

		else if(name == "Alice" && a > c) cout << "ALICE" << endl;

		else if(name == "Carl" && c == a) cout << "ALICE" << endl;

		else if(name == "Carl" && a < c) cout << "CARL" << endl;
	}
	return 0;
}
