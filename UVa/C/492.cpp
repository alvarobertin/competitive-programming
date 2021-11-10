#include <iostream>
#include <cstdio>
#include <list>
#include <string>

using namespace std;

bool isVowel(char l){
	if(l == 'A' || l == 'a')
		return true;
	if(l == 'E' || l == 'e')
		return true;
	if(l == 'I' || l == 'i')
		return true;
	if(l == 'O' || l == 'o')
		return true;
	if(l == 'U' || l == 'u')
		return true;
	return false;
}

bool isConsonant(char l){

	if(!isVowel(l)){
		if(l >= 65 && l <= 90)
			return true;
		if(l >= 97 && l <= 122)
			return true;
		return false;
	}
	return false;
}

int main() {

	string in;
	char letra;
	
	while(getline(cin, in)){
		if(in == ""){
			break;
		}
		in += " ";
		list<char> linea(in.begin(), in.end());
		list<char>::iterator it = linea.begin();

		while (it != linea.end()){
			
			if(isVowel(*it)){

				while((isVowel(*it) || isConsonant(*it)) && it != linea.end()) it++;
				if(it != linea.end()){
					linea.insert(it, 'a');
					linea.insert(it, 'y');	
				}
			
			}
			else if(isConsonant(*it)){
				letra = *it;
				
				linea.erase(it++);
				
				while((isVowel(*it) || isConsonant(*it)) && it != linea.end()) it++;
				
				if(it != linea.end()){
					linea.insert(it, letra);
					linea.insert(it, 'a');
					linea.insert(it, 'y');					
				}				

			}
			it++;
		}
		linea.erase(--it);
		for (list<char>::iterator it = linea.begin(); it != linea.end(); it++){
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}