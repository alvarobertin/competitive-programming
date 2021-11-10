#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

int main(){

	map<string, char> mors;

	mors["-.."] = 'D';
	mors["-.-."] = 'C';
	mors["-..."] = 'B';
	mors[".-"] = 'A';
	mors["-.-"] = 'K';
	mors[".---"] = 'J';
	mors[".."] = 'I';
	mors["...."] = 'H';
	mors["--."] = 'G';
	mors["..-."] = 'F';
	mors["."] = 'E';
	mors[".--"] = 'W';
	mors["...-"] = 'V';
	mors["..-"] = 'U';
	mors["-"] = 'T';
	mors["..."] = 'S';
	mors[".-."] = 'R';
	mors["--.-"] = 'Q';
	mors[".--."] = 'P';
	mors["---"] = 'O';
	mors["-."] = 'N';
	mors["--"] = 'M';
	mors[".-.."] = 'L';
	mors["----."] = '9';
	mors["---.."] = '8';
	mors["--..."] = '7';
	mors["-...."] = '6';
	mors["....."] = '5';
	mors["....-"] = '4';
	mors["...--"] = '3';
	mors["..---"] = '2';
	mors[".----"] = '1';
	mors["-----"] = '0';
	mors["--.."] = 'Z';
	mors["-.--"] = 'Y';
	mors["-..-"] = 'X';
	mors["-.-.--"] = '!';
	mors[".----."] = 39;
	mors["..--.."] = '?';
	mors["--..--"] = ',';
	mors[".-.-.-"] = '.';
	mors[".--.-."] = '@';
	mors[".-..-."] = '"';
	mors["..--.-"] = '_';
	mors["-....-"] = '-';
	mors[".-.-."] = '+';
	mors["-...-"] = '=';
	mors["-.-.-."] = ';';
	mors["---..."] = ':';
	mors[".-..."] = '&';
	mors["-.--.-"] = ')';
	mors["-.--."] = '(';
	mors["-..-."] = '/';

	int Cases, l = 1;
	char letr, temp[2005];
	string pal, resu, acum;

	scanf("%d\n", &Cases);

	while(Cases >= l){

		getline (cin, pal);
		if(pal[pal.length() - 1] != ' ')
			pal += " ";
		resu = "";
		acum = "";
		for (int i = 0; i < pal.length(); ++i){
			
			if(pal[i] != ' '){

				acum += pal[i];

			}
			else if(pal[i] == ' ' && pal[i + 1] == ' ' && acum != "" && acum != " "){

				resu += mors[acum];
				acum = "";
				resu += " ";
				i++;
				
			}
			else if(pal[i] == ' ' && acum != " " && acum != ""){
				resu += mors[acum];
				acum = "";
			}
		}
		printf("Message #%d\n", l++);
		cout << resu << "\n";
		if(l <= Cases)
			cout << "\n";

	}

	return 0;
}
/*
mors["-.."] = 'D';
	mors["-.-."] = 'C';
	mors["-..."] = 'B';
	mors[".-"] = 'A';
	mors['E'] = ".";
	mors['F'] = "..-.";
	mors['G'] = "--.";
	mors['H'] = "....";
	mors['I'] = "..";
	mors['J'] = ".---";
	mors['K'] = "-.-";
	mors['L'] = ".-..";
	mors['M'] = "--";
	mors['N'] = "-.";
	mors['O'] = "---";
	mors['P'] = ".--.";
	mors['Q'] = "--.-";
	mors['R'] = ".-.";
	mors['S'] = "...";
	mors['T'] = "-";
	mors['U'] = "..-";
	mors['V'] = "...-";
	mors['W'] = ".--";
	mors['X'] = "-..-";
	mors['Y'] = "-.--";
	mors['Z'] = "--..";
	mors['0'] = "-----";
	mors['1'] = ".----";
	mors['2'] = "..--";
	mors['3'] = "...-";
	mors['4'] = "....";
	mors['5'] = ".....";
	mors['6'] = "-....";
	mors['7'] = "--...";
	mors['8'] = "---..";
	mors['9'] = "----.";
	mors['.'] = ".-.-.-";
	mors[','] = "--..--";
	mors['?'] = "..--.. ";
	mors[39] = ".----.";
	mors['!'] = "-.-.--";
	mors['/'] = "-..-.";
	mors['('] = "-.–.";
	mors[')'] = "-.--.-";
	mors['&'] = ".-...";
	mors[':'] = "---...";
	mors[';'] = "-.-.-.";
	mors['='] = "-...-";
	mors['+'] = ".-.-.";
	mors['-'] = "-....-";
	mors['_'] = "..--.-";
	mors['"'] = ".-..-.";
	mors['@'] = ".--.-.";
*/