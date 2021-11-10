#include <bits/stdc++.h>

using namespace std;

int main(){
    string str1, str2, str3;
    bool paso = false;
    vector <string> vec;
    cin >> str1 >> str2 >> str3;
    
    vec.push_back(str1);
    vec.push_back(str2);
    vec.push_back(str3);
    
    int contador = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] != "tapioka" && vec[i] != "bubble"){
            if(contador == 0)
                cout << vec[i];
            else
                cout << " " << vec[i];
            contador++;
            paso = true;
        }
    }
    if(paso)
        cout << endl;

    if(!paso)
        cout << "nothing" << endl;

    return 0;
}