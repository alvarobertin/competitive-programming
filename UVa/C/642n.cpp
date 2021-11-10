#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
	if(a != b)
		return a < b;
	return false;
}

int main(){
	string pal;

	map<string, int> dict;

	vector<string> words;

	cin >> pal;

	while(pal != "XXXXXX"){
		dict[pal] = 0;
		cin >> pal;
	}

	cin >> pal;

	while(pal != "XXXXXX"){
		words.clear();
		for (map<string, int>::iterator it = dict.begin(); it != dict.end(); it++){
			if ( is_permutation(it->first.begin(), it->first.end(), pal.begin()) && it->first.length() == pal.length() )
				words.push_back(it->first);
		}

		sort(words.begin(), words.end(), compare);

		if(!words.empty()){
			for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
				cout << *it << endl;
		}else
			cout << "NOT A VALID WORD" << endl;
		
		cout << "******" << endl;
		
		cin >> pal;
	}
	return 0;
}
