#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(){

	char letter, hex_string[3];
	vector<int> lcds;
	int cases, it;

	cin >> cases;
	scanf("\n");
	for (int w = 1; w <= cases ; ++w){
		lcds.clear();

		for (int i = 0; i < 150; ++i)
			lcds.push_back(0);


		it = 0;

		scanf("%c", &letter);

		while(letter != '\n'){

			if(letter == '>'){
				if(it == 99)
					it = 0;
				else
					it++;
			}else if(letter == '<'){
				if(it == 0)
					it = 99;
				else
					it--;
			}else if(letter == '+'){

				if(lcds[it] == 255)
					lcds[it] = 0;
				else
					lcds[it]++;

			}else if(letter == '-'){
				if(lcds[it] == 0)
					lcds[it] = 255;
				else
					lcds[it]--;
			}
			scanf("%c", &letter);
		}

		printf("Case %d: ", w);

		it = 0;

		sprintf(hex_string, "%02X", lcds[it]);
		
		cout << hex_string;
		
		for (it = 1; it < 100; ++it){
			sprintf(hex_string, "%02X", lcds[it]);
			cout << " " << hex_string;
		}
		cout << endl;

	}

	return 0;
}