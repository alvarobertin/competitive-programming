#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

int main(){

	int Cases, l = 1, N, a, b, M;
	string temp, op;
	char tem;
	vector<string> matrix;

	scanf("%d\n", &Cases);

	while(Cases >= l){

		cin >> N;
		matrix.clear();

		for (int i = 0; i < N; ++i){
			cin >> temp;
			matrix.push_back(temp);
		}

		cin >> M;

		while(M--){

			cin >> op;
			temp = "";
			tem = ' ';
			if(op == "row"){
				cin >> a >> b;
				temp = matrix[a - 1];
				matrix[a - 1] = matrix[b - 1];
				matrix[b - 1] = temp;
			}
			else if(op == "col"){
				cin >> a >> b;
				for (int i = 0; i < N; ++i){
					tem = matrix[i][a - 1];
					matrix[i][a - 1] = matrix[i][b - 1];
					matrix[i][b - 1] = tem;
				}
			}
			else if(op == "inc"){

				for (int i = 0; i < N; ++i){
					for (int j = 0; j < N; ++j){
						a = matrix[i][j] - '0';
						if((a + 1) == 10){
							matrix[i][j] = '0';
						}
						else{
							matrix[i][j] += 1;
						}
					}
				}

			}
			else if (op == "dec"){

				for (int i = 0; i < N; ++i){
					for (int j = 0; j < N; ++j){
						a = matrix[i][j] - '0';
						if((a - 1) == -1){
							matrix[i][j] = '9';
						}
						else{
							matrix[i][j] -= 1;
						}
					}
				}				
			
			}
			else if(op == "transpose"){
				for (int i = 0; i < N - 1; ++i){
					for (int j = i; j < N; ++j){
						tem = matrix[i][j];
						matrix[i][j] = matrix[j][i];
						matrix[j][i] = tem;
					}
				}
			}

		}

		cout << "Case #" << l << "\n";
		for (int i = 0; i < N; ++i){
			cout << matrix[i] << "\n";
		}
	
		cout << "\n";
		

		++l;
	}

	return 0;
}
