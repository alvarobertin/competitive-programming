#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;
/*

1
5 3
100 100 80 3 2
80 80 80 0 5
60 20 70 5 3
40 40 40 5 0
100 20 20 1 9

*/

int main(){

	int cases, S, T;
	float notas[31][11], avg[31], menor, sum, mean, sd ,resul, flag = 1;
	int Abs[31], Bonus[31];
	char grades[31];

	cin >> cases;

	while(cases--){
		mean = 0;
		sd = 0;

		cin >> S >> T;
		
		for (int i = 0; i < S; ++i){
			
			for (int j = 0; j < T; ++j){
				cin >> notas[i][j]; 
			}
			
			cin >> Bonus[i] >> Abs[i];

		}
	
		for (int i = 0; i < S; ++i){
			sum = 0;
			menor = 120;
			for (int j = 0; j < T; ++j){
					
				if(notas[i][j] < menor){
					menor = notas[i][j];
				}
				sum += notas[i][j];
			}

			if(T <= 2)
				avg[i] = sum / (float) T;
			else
				avg[i] = (sum - menor) / ((float) T - 1.0);
			mean += avg[i];
		}
		/*
		for (int i = 0; i < S; ++i){
			cout << avg[i] << endl;
		}
		*/
		mean = mean / (float)S;
		sum = 0;
		for (int i = 0; i < S; ++i){
			sum += (avg[i] - mean) * (avg[i] - mean);
			if(Bonus[i] >= 2)
				avg[i] += 3.0 * floor(Bonus[i] / 2.0);
		}
		sd = sqrt(sum/ (float)S);
		sd = round(sd * 10000.000000) / 10000.000000;
		sum = 0;
		for (int i = 0; i < S; ++i){
			//cout << mean + sd << " " << avg[i] << " " <<mean << endl;
			if(avg[i] >= (mean + sd)){
				grades[i] = 'A';
			}
			else if((mean + sd) > avg[i] && avg[i] >= mean){
				grades[i] = 'B';
			}
			else if(mean > avg[i] && avg[i] >= (mean - sd)){
				grades[i] = 'C';
			}
			else if((mean - sd) > avg[i]){
				grades[i] = 'D';
			}
			else{
				grades[i] = 'F';
			}

			if(Abs[i] == 0){
				if(grades[i] != 'A')
					grades[i] -= 1;
			}
			else if(Abs[i] >= 4){

				for (int j = 0; j < floor(Abs[i] / 4); ++j){
					
					if(grades[i] == 'D'){
						grades[i] = 'F';
						break;
					}
					else if(grades[i] != 'F'){
						grades[i] += 1;
					}

				}
			}			

			if(grades[i] == 'A')
				sum += 4;
			else if(grades[i] == 'B')
				sum += 3;
			else if(grades[i] == 'C')
				sum += 2;
			else if(grades[i] == 'D')
				sum += 1;
		}

		resul = sum / S;


		if(flag){
			printf("MAKING THE GRADE OUTPUT\n");	
			flag = 0;
		}
		//printf("sum %.2f S %d \n",sum, S );
		printf("%.1lf\n",resul );
	}
	printf("END OF OUTPUT\n");




	return 0;
}