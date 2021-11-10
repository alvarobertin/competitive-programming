#include <bits/stdc++.h>

using namespace std;


int main(){

	int cases, res;
	string num;

	cin >> cases;


	while(cases--){


		cin >> num;

		res = 0;

		if( count(num.begin(), num.end(), '1') > 1){

			for (int i = 0; i < num.length() - 1; ++i){

				if(num[i] == '1' && num[i + 1] == '0'){
					num[i + 1] == '1';
					i++;
					res++;
				}
				else if(num[i] == '0' && num[i - 1] == '1' && num[i + 1] == '1'){
					num[i + 1] == '1';
					res++;
				}else if(num[i] == '1' && num[i + 1] == '1')
					break;	
			}
		}
		cout << res << '\n';

	}

	return 0;
}