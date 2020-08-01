#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

void print(vector<int> &a){
    for(int i=0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

void fillString(string &s, int n){
    while(n > 0){
        s += ('0' + (n % 10));
        n /= 10; 
    }
    if(s.size() < 6){
        while(s.size() != 6){
            s.push_back('0');
        }
    }
    for(int i=0; i < s.size()/2; ++i){
        swap(s[i], s[s.size()-i-1]);
    }
}

bool check(string s){
    int s1 = 0;
    int s2 = 0;

    for(int i=0; i < s.size()/2; ++i){
        s1 += (s[i] - '0');
        s2 += (s[s.size() - 1 - i] - '0');
    }
    return s1 == s2;
}


void test_case(){

    int n;
    cin >> n;

    string a="", b="", c="";

    fillString(a,n);
    fillString(b,n+1);
    fillString(c,n-1);

    if(check(a) || check(b) || check(c)){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}

int main(){

    ios::sync_with_stdio(false);

    test_case();

    return 0;
}