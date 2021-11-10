#include <bits/stdc++.h>

using namespace std;

long long int pre(long long int Wats, long long int acum){

	if(Wats >= 1 && Wats <= 100){
		//2
		acum += Wats * 2;
		Wats -= Wats;
		return acum;

	}else if(Wats >= 101 && Wats <= 10000){
		//3

		acum += (Wats - 100) * 3;
		Wats -= (Wats - 100);
		return pre(Wats, acum);
	
	}else if(Wats >= 10001 && Wats <= 1000000){
		//5
		acum += (Wats - 10000) * 5;
		Wats -= (Wats - 10000);
		return pre(Wats, acum);


	}else if(Wats > 1000000){
		//7

		acum += (Wats - 1000000) * 7;
		Wats -= (Wats - 1000000);
		return pre(Wats, acum);

	}
	return acum;

}


int main(){


	long long int izq = 0, der = 9999999999, mid = 0, value, WatsA, A, B;

	cin >> A >> B;

	while(A || B){

		
		izq = 0; der = 9999999999; mid = 0; value = 0; WatsA = 0;

		value = pre(mid, 0);
		
		while(izq < der){

			mid = (izq + der) / 2;
			
			value = pre(mid, 0);

			if(value > A)
				der = mid;
			else if(value < A)
				izq = mid;

			if(value == A){
				break;
			}

		}
		WatsA = mid;

		izq = 0; der = mid; mid = 0; 
		while(izq < der){

			mid = (izq + der) / 2;

			value = abs(pre(mid, 0) - pre(WatsA - mid, 0));

			if( value > B)
				der = mid;
			else if( value < B)
				izq = mid;

			if(value == B)
				break;

		}





		cout << pre( min( mid, abs(WatsA - mid) ), 0) << endl;



		cin >> A >> B;
	}
	return 0;
}