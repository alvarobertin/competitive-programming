#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

	vector<int> arr;
	
	int  N, S, temp, sum, menor = 0, count;

	bool flag;

	while(cin >> N >> S){
		menor = 1316134911;
		count = 0;
		sum = 0;
		flag = false;
		arr.clear();
	
		for(int i = 0; i < N; i++){	
			cin >> temp;
			arr.push_back(temp);
		}

		for (int i = 0; i < N; ++i){
			sum = 0;
			count = 0;
			flag = false;
			if(arr[i] < S){

				for (int j = i; j < N; ++j){
					count++;
					sum += arr[j];
					if(sum >= S){
						flag = true;
						break;
					}
				}
			}else if(arr[i] >= S){
				menor = 1;
				count = 1;
				break;
			}

			if(flag){
				if(count < menor){
					menor = count;
				}
				flag = false;
			}
		}
		if(menor != 1316134911)
			cout << menor << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}