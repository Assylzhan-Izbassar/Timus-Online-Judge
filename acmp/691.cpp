//  Номера автобусов
//https://acmp.ru/index.asp?main=task&id_task=691

#include <iostream>
#include <vector>

using namespace std;

string mustExist = "ABCEHKMOPTXY";

bool isValidTrackNumber(string s){
    if(s.size() > 6)
        return false;
    if(mustExist.find(s[0]) == string::npos)
        return false;
    for(size_t i=1; i <= 3; ++i)
        if(s[i] < '0' || s[i] > '9')
            return false;
    for(size_t i=4; i < s.size(); ++i)
        if(mustExist.find(s[i]) == string::npos)
            return false;
    return true;
}

int main(){

    int n;
    scanf("%d", &n);
    string s;

    vector<string> v;

    for(size_t i=0; i < n; ++i)
        cin >> s,
        v.push_back(s);
    
    for(size_t i=0; i < v.size(); ++i){
        if(isValidTrackNumber(v[i]))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}