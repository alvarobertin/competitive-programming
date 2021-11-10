#include <bits/stdc++.h>


using namespace std;

int binUp(vector<int> A, int x){

	int ans = -1, lo, hi, mid;

	if( x <= A[A.size() - 1] ){
		lo = -1;
		hi = A.size() - 1;

		while(lo + 1 < hi){
			mid = (lo + hi)/2;
			if(A[mid] >= x)
				hi = mid;
			else
				lo = mid;
		}
		ans = hi;
	}

	return ans;
}

int main(){

	map<char, vector<int> > base, copy;
	bool flag, f2;
	int n, res, min, max, i, count;
	
	string S, Q;

	cin >> S;

	for (int i = 0; i < S.length(); ++i){
		base[S[i]].push_back(i);	
	}
	cin >> n;
	while(n--){
		copy = base;

		flag = true;
		f2 = false;
		res = 0;
		min = 0;
		max = 0;
		i = 0;
		count = 0; 

		cin >> Q;

		for (i = 0; i < Q.length(); ++i){

			res = binUp(copy[ Q[i] ], max);


			if(i == 0){
				min = copy[ Q[i] ][res];
			}
			
			max = copy[ Q[i] ][res];
			

			if(res == -1 ){
				flag = false;
				break;
			}
			copy[Q[i]][res] = -1;	
		}


		if(flag)
			cout << "Matched " << min << " "<< max << '\n'; 
		else
			cout << "Not matched" << '\n';

	}

	return 0;
}