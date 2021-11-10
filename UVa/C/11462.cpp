#include <iostream>
#include <cstdio>

using namespace std;

int main() {

  int arr[101];
  
  int N, age;

  bool first;

  cin >> N;

  while(N){
    first = true;
    for(int i = 0; i < 101; i++){
      arr[i] = 0;
    }

    for(int i = 0; i < N; i++){
      scanf("%d", &age);
      arr[age] += 1;
    }

    for(int i = 0; i < 101; i++){
      if(arr[i] > 0){
        for(int j = 0; j < arr[i]; j++){
          if(first){
             cout << i;
             first = false;
          }else{
            cout << " " << i;
          }
        }
      }
    }
    
    
    

    cin >> N;

    cout << endl;
  }

}
