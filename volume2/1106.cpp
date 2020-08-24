#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(c) (int)((c).size())
#define all(c) c.begin(),c.end()
#define rep(i,a,n) for (int i = a; i < n; i++)
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;


void print(vector<int> &a){
    for(int i=0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int n;
vector<vi> gr;
vb used;
vi t1;
queue<int> q;
vi dist;

void bfs(int x){

    dist = vi(n);

    used[x] = true;
    q.push(x);
    dist[x] = 1;

    while (q.size()){
        int a = q.front();
        q.pop();
        for(auto u : gr[a]){
            if(!used[u]){
                used[u] = true;
                dist[u] = dist[a] + 1;
                q.push(u);
            }
        }
    }
    
}

void test_case(){
    cin >> n;

    gr = vector<vi>(n);

    int x;

    rep(i,0,n){
        while(cin >> x){
            if(x == 0)
                break;
            gr[i].pb(--x);
        }
    }
    used = vb(n);

    rep(i, 0, n){
        if(!used[i]){
            bfs(i);
            rep(i, 0, n){
                if(dist[i] % 2 != 0){
                    t1.pb(i+1);
                }
            }
        }
    }

    cout << t1.size() << endl;
    rep(i, 0, t1.size()){
        cout << t1[i] << " ";
    }
    cout << endl;
}

int main(){

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    test_case();

    return 0;
}