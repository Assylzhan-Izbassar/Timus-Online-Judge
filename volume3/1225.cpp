#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> dp(n);

    for(size_t i=0; i < n; ++i)
        dp[i] = 0;

    dp[0] = dp[1] = 2;

    for(size_t i=2; i < n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n-1] << endl;
    
    return 0;
}