#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    long long dp[n];

    dp[0] = 3;

    for(size_t i=1; i < n; ++i)
        dp[i] = dp[i-1] * 2;

    cout << dp[n-1] << endl;

    return 0;
}