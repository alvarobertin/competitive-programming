#include <bits/stdc++.h> 
using namespace std;


int Nod (int a) {
    int res = 0;
    for (int i = 1; i <= sqrt(a); i++){
        if(a % i == 0){
            if(a / i == i) res++;
            else res += 2;
        }
    }
    return res;
}


int main(){
	int N, A, B;
    vector<int>::iterator low,up;

    cin >> N;
	
    int ultimo = 1, nuevo;
    vector<int> vec;
    vec.push_back(ultimo);

    for (int i = 0; i < 66000; i++){
        //cout << ultimo << endl;
        nuevo = ultimo + Nod(ultimo);
        vec.push_back(nuevo);
        ultimo = nuevo;
    }
    
    int cases = 1;
    while(cases <= N){
        cin >> A >> B;
        
        low = lower_bound (vec.begin(), vec.end(), A);
        up = upper_bound (vec.begin(), vec.end(), B);

        cout << "Case " << cases << ": "<< (up - vec.begin()) - (low - vec.begin()) << endl;
        

        cases++;       
	}

	return 0;
}