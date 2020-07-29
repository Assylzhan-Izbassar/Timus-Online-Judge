#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n,d;
    cin >> n >> d;

    vector<int> m(n);

    for(int i=0; i < n; ++i) cin >> m[i];

    sort(m.begin(), m.end());

    int l = 0;
    int result = 0;
 
    for(int r=n-1; r >= l; --r){
        if(m[r] + m[l] <= d){
            result++;
            l++;
        }else{
            result++;
        }
    }
    cout << result << endl;

    return 0;
}