#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    
    string s;
    getline(cin, s);

    int cost = 0;

    for(size_t i=0; i < s.size(); ++i){
        int ii = s[i] - 'a' + 1;
        if(ii == -64 || ii == -50){
            cost += 1;
        }else if(ii == -52){
            cost += 2;
        }else if(ii == -63){
            cost += 3;
        }else{
            if(ii % 3 == 0){
                cost += 3;
            }else{
                cost += (ii % 3);
            }
        }
    }

    cout << cost << endl;

    return 0;
}