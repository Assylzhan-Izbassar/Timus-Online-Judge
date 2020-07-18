#include <iostream>
#include <vector>

using namespace std;

int k = -1;

vector<bool> used(101, false);
vector<vector<int> > g;

void dfs(int v){
    k = k + 1;
    used[v] = true;

    for(int i=0; i < g.size(); ++i){
        if(g[v][i] == 1 && !used[i]){
            dfs(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    int n,s;
    cin >> n >> s;

    vector<int> v;
    int x;
    for(size_t i=0; i < n; ++i){
        v.clear();
        for(size_t j=0; j < n; ++j){
            cin >> x;
            v.push_back(x);
        }
        g.push_back(v);
    }

    dfs(s-1);

    cout << k << endl;

    return 0;
}