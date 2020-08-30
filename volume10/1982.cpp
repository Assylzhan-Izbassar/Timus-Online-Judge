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
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tp;

void print(vector<int> &a){
    for(int i=0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int n, k;
vector<pair<ll, pll> > edges;
vector<tp> mst;
vi tree_id;
vb cities;
vb exist;
ll cost = 0;

void kruskal(){

    tree_id = vi(n);

    sort(all(edges));

    rep(i, 0, n)
        tree_id[i] = i;
    
    // for(auto e : edges){
    //     int a,b,w;
    //     a = e.se.fi; b = e.se.se; w = e.fi;

    //     cout << a + 1 << " " << b + 1 << " " << w << endl;
    // }
    // return;

    for(auto e : edges){
        int a,b,w;
        a = e.se.fi; b = e.se.se; w = e.fi;

        if(tree_id[a] != tree_id[b] && ((cities[a] && !cities[b]) || 
                (cities[b] && !cities[a]))){
            mst.pb({a,b,w});
            cost += w;
            cities[b] = cities[a] = true;
            int old_id = tree_id[b];
            int new_id = tree_id[a];
            rep(j, 0, n){
                if(tree_id[j] == old_id){
                    tree_id[j] = new_id;
                }
            }
        }
    }
}

const int INF = 1e9;
vector<vi> g;

void prim(){
    vector<bool> used (n);
    vector<int> min_e (n, INF), sel_e (n, -1);
    min_e[0] = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;

        if (min_e[v] == INF) {
            exit(0);
        }
    
        used[v] = true;
        if (sel_e[v] != -1){
            if((cities[v] && !cities[sel_e[v]]) || 
            (!cities[v] && cities[sel_e[v]])){
                cost += min_e[v];
                cities[v] = cities[sel_e[v]] = true;
            }
        }
    
        for (int to=0; to<n; ++to)
            if (g[v][to] < min_e[to] && g[v][to] > 0) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
}
void test_case(){
    cin >> n >> k;
    cities = vb(n, false);

    g = vector<vi> (n, vi(n));

    int x; 
    rep(i, 0, k){
        cin >> x;
        cities[x-1] = true;
    }

    // int w;
    rep(i, 0, n){
        rep(j, 0, n){
            // cin >> w;
            // if(i==j) continue;
            // edges.pb({w, {i,j}});
            cin >> g[i][j];
        }
    }
    // kruskal();

    // rep(i, 0, n){
    //     cout << cities[i] << " ";
    // }
    // cout << endl;

    // for(auto e : mst){
    //     int a, b, w;
    //     tie(a,b,w) = e;
    //     cout << a + 1 << " " << b + 1 << " " << w << endl;
    // }
    prim();
    cout << cost << endl;
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