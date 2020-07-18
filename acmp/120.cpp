#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    int arr[n][m];

    for(size_t i=0; i < n; ++i)
        for(size_t j=0; j < m; ++j)
            cin >> arr[i][j];
    
    int dp[n+1][m+1];

    for(size_t i=0; i <= n; ++i)
        for(size_t j=0; j <= m; ++j)
            dp[i][j] = INT_MAX;
    
    dp[0][1] = 0;
    for(int i=1; i <= n; ++i){
        for(int j=1; j <= m; ++j){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + arr[i-1][j-1];
        }
    }
    
    cout << dp[n][m] << endl;

    return 0;
}