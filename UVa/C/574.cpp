#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

string nextGreater(string num){

    int l = num.size(); 
 	int i;
    for (i = l - 1; i>=0; i--){ 
        if (num.at(i) == '0'){ 
            num.at(i) = '1'; 
            break; 
        } 
        else
            num.at(i) = '0'; 
    } 
    if (i < 0) 
        num = "1" + num; 
    return num; 
} 

int getSum(string Bin, vector<int> numbers, int num){
	int acum = 0;
	for (int i = 1; i < Bin.length(); ++i){
		if(Bin[i] == '1'){

			acum += numbers[i];
		}
	}
	return acum;
}

string getString(string Bin, vector<int> numbers){
	string ans = "";
	char buffer[6];
	for (int i = 1; i < Bin.length(); ++i){
		if(Bin[i] == '1'){
			sprintf(buffer, "%d", numbers[i]);
			string nums(buffer);
			if(ans.length() >= 1){
				ans += '+';
				ans += nums;
			}else{
				ans += nums;
			}
		}
	}
	return ans;	
}	

int main(){

	int num = 0;
	cin >> num;

	while(num){

		int opt = 0, n;
		vector<int> numbers;
		vector<string> answers;
		string Binary, comp;

		cin >> opt;

		Binary = "";
		comp = "";
		numbers.push_back(0);
		
		for (int i = 0; i < opt; ++i){
			cin >> n;
			numbers.push_back(n);
			
		}		
		Binary = "1";

		for (int i = 1; i < numbers.size(); ++i)
			Binary += '0';
		
		while (Binary.length() <= numbers.size()){
			
			if(getSum(Binary, numbers, num) == num){
				comp = getString(Binary, numbers);
				if(answers.end() == find(answers.begin(), answers.end(), comp)){
					answers.push_back(comp);

				}
			}

			Binary = nextGreater(Binary);
		}

		printf("Sums of %d:\n", num);
		
		if(answers.size() == 0){
			printf("NONE\n");
		}
		else{
			
			for (int i = answers.size() - 1; i >= 0; --i){
				cout << answers[i] << endl;
			}
		}

		cin >> num;
	}
	return 0;
}