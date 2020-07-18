#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n,m;
    cin >> n >> m;

    int a[n][m];

    for(size_t i=0; i < n; ++i)
        for(size_t j=0; j < m; ++j)
            cin >> a[i][j];

    int dp[n][m];

    for(size_t i=0; i < n; ++i)
        for(size_t j=0; j < m; ++j)
            dp[i][j] = 0;
    
    dp[0][0] = 1;

    for(size_t i=0; i < n; ++i){
        for(size_t j=0; j < m; ++j){
            if(i == n-1 && j == m-1)
                break;
            if(i + a[i][j] < n && dp[i][j] != 0){
                dp[i + a[i][j]][j] += dp[i][j];
            }
            if(j + a[i][j] < m && dp[i][j] != 0){
                dp[i][j + a[i][j]] += dp[i][j];
            }
        }
    }
    cout << "\nAnswer: \n\n";
    for(size_t i=0; i < n; ++i){
        for(size_t j=0; j < m; ++j){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    //cout << dp[n-1][m-1] << endl;

    return 0;
}