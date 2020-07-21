#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int i = 0;
    int j = n-1;

    vector<vector<int> > v(n, vector<int>(n,0));

    int k = 1;

    for(int d = 0; d <= n + n - 1; ++d){
        int c = d < n ? n - d : 0;
        int r = d >= n ? d - n : 0;

        while(r < n && c < n){
            v[c][r] = k;
            c++;
            r++;
            k++;
        }
    }

    for(int i=0; i < n; ++i){
        for(int j=i; j < n; ++j){
            if(i != j){
                int t = v[i][j];
                v[i][j] = v[j][i];
                v[j][i] = t;
            }
        }
    }

    for(int i =0; i < v.size(); ++i){
        for(int j = 0; j < v[i].size(); ++j){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}