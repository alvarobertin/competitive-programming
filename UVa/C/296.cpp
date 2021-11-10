#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

string next(string num){
	char buffer[6];
	//num = to_string(stoi(num) + 1);
	sprintf(buffer, "%d", stoi(num) + 1);
	string nums(buffer);
	return nums;
}
int main(){

	int cases, tries, correct[20], misplaced[20],countcorrec, countmis, flag, countposi, z, zero = 0;
	char guess[20][20];

	string ans, posi, temp, temp2;

	cin >> cases;

	while(cases--){

		zero = 0;
		ans = "10000";
		countposi = 0;
		cin >> tries;

		for (int i = 0; i < tries; ++i){
			scanf("%s %d/%d", guess[i], &correct[i], &misplaced[i]);
		}

		while(ans[0] != '2'){

			if(tries == 0){
				zero = 1;
				break;
			}

			for (int i = 0; i < tries; ++i){
				
				countcorrec = 0;
				countmis = 0;
				temp = guess[i];
				temp2 = ans;

				if(correct[i] >= 0){
					for (int j = 1, z = 0; j <= 4; ++j, ++z){
						if(temp[z] == temp2[j] && temp[j] != 'a'){
							countcorrec += 1;
							temp2[j] = 'a';
							temp[z] = 'a'; 
						}
					}
					if(countcorrec != correct[i])
						break;
				}

				if(misplaced[i] >= 0){
					for (int j = 0; j < 4; ++j){
						for (int k = 1; k <= 4; ++k){
							if(temp[j] == temp2[k] && temp[j] != 'a' ){
								temp[j] = 'a';
								temp2[k] = 'a';
								countmis += 1;
							}
						}
					}
					if(countmis != misplaced[i])
						break;
				}
				if(i + 1  == tries ){
					posi = ans;
					countposi += 1;
					break;
				}
			}
			if(countposi > 1)
				break;

			ans = next(ans);	
		}
		
		if(countposi > 1 || zero)
			cout << "indeterminate" << "\n";
		else if( countposi == 1)
			cout << posi.substr(1,4) << "\n";
		else
			cout << "impossible" << "\n";
	}	
	return 0;
}