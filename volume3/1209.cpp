#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    vector<double> a(n);
    for(size_t i=0; i < n; ++i){
        cin >> a[i];
    }

    for(size_t i=0; i < n; ++i){
        double p = 8 * a[i] - 7;
        long long q = sqrt(p);
        if(q*q == p){
            cout << 1 << " ";
        }else{
            cout << 0 << " ";
        }
    }

    return 0;
}