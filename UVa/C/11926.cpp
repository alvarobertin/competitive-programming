#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct trio{
	int f;
	int s;
	int i;
};

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first != b.first)
		return a.first < b.first;
	if(a.second != b.second)
		return a.second < b.second;
	return false;
}

bool icompare(trio a, trio b){
	if(a.f != b.f)
		return a.f < b.f;
	return false;
}


int main(){

	int n, m, a, b, in, k;
	bool flag;
	vector< pair<int, int> > task;
	vector<trio> itask;
	pair<int, int> temp;
	trio itemp;
	cin >> n >> m;

	while(n || m){
		flag = false;
		
		task.clear();
		itask.clear();

		for (int i = 0; i < n; ++i){
			cin >> a >> b;
			temp.first = a;
			temp.second = b;
			task.push_back(temp);
		}

		for (int i = 0; i < m; ++i){
			cin >> a >> b >> in;
			itemp.f = a;
			itemp.s = b;
			itemp.i = in;
			itask.push_back(itemp);
		}

		sort(task.begin(), task.end(), compare);
		sort(itask.begin(), itask.end(), icompare);

		temp.first = -1;
		temp.second = -1;
		task.push_back(temp);

		itemp.f = -1;
		itemp.s = -1;
		itemp.i = -1;
		itask.push_back(itemp);



		for (int i = 0; i < n; ++i){
			
			if(task[i].second > task[i + 1].first && task[i + 1].first != -1){
				flag = true;
				break;
			}

			for (int j = 0; j < m; ++j){

				k = 0;

				while(itask[j].f + (k * itask[j].i) < 1000000){

					if(task[i].first > itask[j].f + (k * itask[j].i) && task[i].first < itask[j].s + (k * itask[j].i)){
						flag = true;
						break;
					}

					if(itask[j].f + (k * itask[j].i) > task[i].first && itask[j].f + (k * itask[j].i) < task[i].second){
						flag = true;
						break;
					}

					if(itask[j].f + (k * itask[j].i) == task[i].first){
						flag = true;
						break;
					}
					k++;
					
				}

				if(flag)
					break;

			}
			if(flag)
				break;
		}

		for (int i = 0; i < m; ++i){
			
			for (int x = i + 1; x; ++x){

				if(itask[x].f == -1)
					break;

				if(itask[i].s > itask[i + 1].f){
					flag = true;
					break;
				}
				/*modificable0  */
				int j = 0, k = 0;
				while(itask[i].s + (j * itask[i].i) < 1000000) {

					if(itask[x].s + (k * itask[i].i) >= 1000000)
						break;
					if(itask[i].s + (j * itask[i].i) >= 1000000)
						break;

					k = 0;
					while(itask[x].f + (k * itask[x].i) < 1000000){

						if(itask[x].s + (k * itask[i].i) >= 1000000)
							break;
						if(itask[i].s + (j * itask[i].i) >= 1000000)
							break;

						if(itask[i].f + (j * itask[i].i) > itask[x].f + (k * itask[x].i) && itask[i].f + (j * itask[i].i) < itask[x].s + (k * itask[x].i)){
							flag = true;
							break;
						}

						if(itask[x].f + (k * itask[x].i) > itask[i].f + (j * itask[i].i) && itask[x].f + (k * itask[x].i) < itask[i].s + (j * itask[i].i)){
							flag = true;
							break;
						}

						if(itask[i + 1].f + (k * itask[i + 1].i) == itask[i].f + (j * itask[i].i)){
							flag = true;
							break;
						}


						k++;
					}
					if(flag)
						break;

					j++;
				}
				
				if(flag)
					break;
			}
		}

		if(flag)
			cout << "CONFLICT" << endl;
		else
			cout << "NO CONFLICT" << endl;


		cin >> n >> m;
	}

	return 0;
}