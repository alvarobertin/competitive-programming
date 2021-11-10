#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){


	int cases, maxrow, maxcol, ROW, COL;

	vector<string> matrix;
	string temp;

	char letter, direccion;

	cin >> cases;

	while(cases--){


		matrix.clear();
		direccion = 'N';
		cin >> maxrow >> maxcol;
		scanf("\n");

		for (int i = 0; i < maxrow; ++i){
			getline(cin, temp);
			matrix.push_back(temp);
		}

		cin >> ROW >> COL;
		ROW--;
		COL--;
		scanf("%c", &letter);

		while(letter != 'Q'){
			

			if(letter == 'R'){

				if(direccion == 'N')
					direccion = 'E';
				else if(direccion == 'W')
					direccion = 'N';
				else if(direccion == 'E')
					direccion = 'S';
				else if(direccion == 'S')
					direccion = 'W';
			
			}else if(letter == 'L'){

				if(direccion == 'N')
					direccion = 'W';
				else if(direccion == 'W')
					direccion = 'S';
				else if(direccion == 'E')
					direccion = 'N';
				else if(direccion == 'S')
					direccion = 'E';

			}else if(letter == 'F'){

				if(direccion == 'N'){
					
					if(ROW > 0){
						if(matrix[ROW - 1][COL] != '*')
							ROW--;
					}

				}
				else if(direccion == 'W'){
					if(COL > 0){
						if(matrix[ROW][COL - 1] != '*')
							COL--;
					}

				}
				else if(direccion == 'E'){
				
					if(COL < maxcol){
						if(matrix[ROW][COL + 1] != '*')
							COL++;
					}
				}
				else if(direccion == 'S'){
					if(ROW < maxrow){
						
						if(matrix[ROW + 1][COL] != '*')
							ROW++;
					}
				}
			}

			scanf("%c", &letter);
		}

		cout << ROW + 1 << " " << COL + 1 << " " << direccion << endl;

		if(cases)
			cout << endl;
	}




	return 0;
}