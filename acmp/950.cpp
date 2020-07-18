#include <iostream>
#include <vector>

using namespace std;

int main(){

    string s;
    cin >> s;

    string ans = "";

    int count = 0;

    for(size_t i=0; i < s.size(); ++i){
        if(s[i] == '0'){
            count++;
        }
        else{
            ans += 'a' + count;
            count = 0;
        }
    }

    cout << ans << endl;

    return 0;
}