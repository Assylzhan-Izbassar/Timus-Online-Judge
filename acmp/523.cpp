#include <iostream>
#include <vector>

using namespace std;

bool f(vector<int> &a, int k, long long V){
    int volume = 0;
    int tome = 0;

    for(size_t i=0; i < a.size(); ++i){
        if(volume > V)
            return false;
        if(volume + a[i] <= V){
            volume += a[i];
        }else{
            tome++;
            volume = a[i];
        }
    }
    return tome+1 <= k;
}

int main(){

    int n,k;
    cin >> n;

    vector<int> v(n);

    for(size_t i=0; i < n; ++i) cin >> v[i];

    cin >> k;

    long long l = 0;
    long long r = 32767;

    while(r > l + 1){
        long long V = l + (r - l)/2;
        
        if(f(v, k, V)){
            r = V;
        }else{
            l = V;
        }
    }

    cout << r << endl;

    return 0;
}