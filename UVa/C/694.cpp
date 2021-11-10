#include <iostream>
#include <cstdio>
using namespace std;

int main(){

	long long int A, L, cA;
	int cases, count;

	cin >> A >> L;

	cases = 0;
	while(A > -1){
		cA = A;
		cases++;
		count = 1;

		while(A != 1 && A <= L){
			if(A % 2 == 0)
				A /= 2;
			else
				A = 3 * A + 1;

			if(A == 1 || A > L)
				break;

			count++;
		}

		if(A == 1)
			count++;

		printf("Case %d: A = %lli, limit = %lli, number of terms = %d\n", cases, cA, L, count);

		cin >> A >> L;
			
	}

	return 0;
}