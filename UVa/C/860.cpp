#include <bits/stdc++.h>

using namespace std;

bool noCharacter (char a){

    if(a == ',' || a == '.' || a == ':' || a == ';' || a == '!' || a == '?' || a == 34 || a == '(' || a == ')' || a == '\n'){
            return false;
    }
    return true;
}
string tomayus(string pal){

    for(int i = 0; i < pal.size(); i++){
        if(pal[i] >= 65  && pal[i] <= 90){
            pal[i] = pal[i] + 32;
        }
    }

    return pal;
}


int main(){

    string pal, newpal;
    double entropy;

    cin >> pal;

    while (pal != "****END_OF_INPUT****"){

        map<string, int> Palabras;
        int lambda = 0;
        vector<string> pals;

        while (pal != "****END_OF_TEXT****"){
            newpal = "";
            for(int i = 0; i < pal.size(); i++){
                if( noCharacter(pal[i]) && pal[i] != '\n' && pal[i] != 0){
                    newpal += pal[i];
                }else{
                    pals.push_back(newpal);
                    newpal = "";
                }
            }

            if(newpal.size() > 0 && pal != "\n" && pal[0] != 0) pals.push_back(newpal);
            
            for(int i = 0; i < pals.size(); i++){
                if(pals[i][0] != 0){
                    Palabras[ tomayus(pals[i]) ]++;
                }
            }

            cin >> pal;
            pals.clear();
        }

        
        for(map<string,int>::iterator it = Palabras.begin(); it != Palabras.end(); it++){
            lambda += it->second;
        }        
        entropy = 0;
        double sigma = 0;
        for(map<string,int>::iterator it = Palabras.begin(); it != Palabras.end(); it++){
            sigma += (it->second) * (log10(lambda) - log10(it->second));
        }
        
        entropy = sigma/lambda;
        double re = (entropy / log10(lambda)) * 100;

        printf("%d %.1f %.0f\n", lambda, entropy, re);


        cin >> pal;
    }
    
    return 0;
}