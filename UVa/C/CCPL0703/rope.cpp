#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, s, n, a, b, acum;

    priority_queue<int> cola;

    cin >> N;

    while(N--){
        cin >> n;

        for (int i = 0; i < n; i++){
            cin >> s;
            cola.push(s * -1);
        }
        
        acum = 0;

        while(!cola.empty()){

            a = cola.top() * -1 ;
            cola.pop();
            if(cola.empty()){
                break;
            }
            b = cola.top() * -1;
            cola.pop();

            acum += a + b;
            cola.push((a + b) * -1);
                
        }

        cout << acum << endl;
        

    }


    return 0;
}