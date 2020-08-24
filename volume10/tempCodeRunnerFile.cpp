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
int n, k;
vector<vi> gr;
vector<vi> dist;
vi cities;
vb used;
const int INF = 1e9;

void floyd_warshell(){
    dist = vector<vi> (n, vi(n, INF));
    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) continue;
            dist[i][j] = gr[i][j];
        }
    }

    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                if(i != j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void test_case(){
    cin >> n >> k;
    cities = vi(k);
    used = vb(n, false);
    gr = vector<vi> (n, vi(n));

    rep(i, 0, k) cin >> cities[i], used[cities[i]-1] = true;

    rep(i, 0, n){
        rep(j, 0, n){
            cin >> gr[i][j];
        }
    }
    floyd_warshell();

    // rep(i,0, n){
    //     rep(j,0,n){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int bill = 0;

    rep(i, 0, n){
        if(!used[i]){
            int mini = dist[cities[0]-1][i];
            rep(j, 1, k){
                mini = min(mini, dist[cities[j]-1][i]);
            }
            bill += mini;
        }
    }

    cout << bill << endl;
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