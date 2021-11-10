#include <iostream>
#include <list>
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

	list<string> dict, words;

	cin >> pal;

	while(pal != "XXXXXX"){
		dict.push_back(pal);
		cin >> pal;
	}

	cin >> pal;

	while(pal != "XXXXXX"){
		words.clear();
		for (list<string>::iterator it = dict.begin(); it != dict.end(); it++){
			if ( is_permutation((*it).begin(), (*it).end(), pal.begin()) && (*it).length() == pal.length() )
				words.push_back(*it);
		}

		words.sort(compare);

		if(!words.empty()){
			for (list<string>::iterator it = words.begin(); it != words.end(); it++)
				cout << *it << endl;
		}else
			cout << "NOT A VALID WORD" << endl;
		
		cout << "******" << endl;
		
		cin >> pal;
	}
	return 0;
}
