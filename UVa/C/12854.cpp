#include <bits/stdc++.h>

using namespace std;

int conv(string str){
    int res = 0, pot = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        int temp = str[i] - '0';
        res += temp * pow(2, pot);
        pot++;
    }
    return res;
}

int main(){

	int lim = 31;

	string A, B, c;


	while(cin >> c){

		A = "";
		B = "";

		A += c;

		for (int i = 0; i < 4; i++){
			cin >> c;
			A += c;
		}
		
		for (int i = 0; i < 5; i++){
			cin >> c;
			B += c;
		}
		
		int a, b;

		a = conv(A);
		b = conv(B);

		if( (a ^ b) == 31)
			cout << "Y" << '\n';
		else
			cout << "N" << '\n';


	}


	return 0;
}
