#include <bits/stdc++.h>

using namespace std;

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

//transform(data.begin(), data.end(), data.begin(), asciitolower);

int main(){

	string word, newword;

	char z;


	map<string, int> words; 

	newword = "";

	while( scanf("%c", &z) != EOF ){

	
		if( (z <= 'Z' && z >= 'A') || (z <= 'z' && z >= 'a')){
			newword += z;
		}
		else{
			transform(newword.begin(), newword.end(), newword.begin(), asciitolower);
			if(newword != "" && newword != " ")
				words[newword] = 0;
			newword = "";
		}

	}

	for ( map<string, int>::iterator it = words.begin() ; it != words.end() ; it++) {
			
		cout << (*it).first << '\n';

	}



	return 0;
}