#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

	int count, l, len;

	bool flag;

	string pal, temp; 
	
	stack<string> open;

	getline(cin, pal);
	
	while(cin){
		l = 0;
		len = pal.length();

		count = 0;
		flag = true;

		while(!open.empty())
			open.pop();
		
		for (int i = 0; i < len; ++i){
			if(pal[i] == '(' || pal[i] == '[' || pal[i] == '<' || pal[i] == '{'){

				if(pal[i] == '(' && pal[i + 1] == '*'){
					open.push("(*");
					i++;
					count++;
				}
				else{
					temp = "";
					temp += pal[i];
					open.push(temp);
					count++;
				}
				if(i + 1 >= len)
					count++;
			}
			else if(pal[i] == ')' || pal[i] == ']' || pal[i] == '>' || pal[i] == '}' || pal[i] == '*'){
				
				count++;
				if(!open.empty()){
					if(pal[i] == '*' && pal[i + 1] == ')'){
						
						if(open.top() == "(*"){
							open.pop();
							i++;
						}else
							break;
						
					}else if(pal[i] != '*'){
						
						if(pal[i] == ')'){
							
							if(open.top() == "("){
								open.pop();
							}else
								break;
						
						}
						else if(pal[i] == '>'){
							if(open.top() == "<"){
								open.pop();
							}else
								break;
						}
						else if(pal[i] == ']'){
							if(open.top() == "["){
								open.pop();
							}else
								break;
						}
						else if(pal[i] == '}'){
							if(open.top() == "{"){
								open.pop();
							}else
								break;
						}

					}
				}else{
					if(!(pal[i] == '*' && pal[i - 1] != '(' && pal[i + 1] != ')')){
						flag = false;
						break;						
					}

				}
				if(i + 1 >= len)
					count++;
			}else{
				count++;
				if(i + 1 >= len)
					count++;
			}

		}

		if(open.empty() && flag){
			cout << "YES" << endl;
		}else{

			cout << "NO " << count << endl;
		}

		getline(cin, pal);
	}

	return 0;
}