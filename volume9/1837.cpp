#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

map<string, int> list;
map<string, int> :: iterator l_it;

vector<vector<int> > gr;
vector<bool> used;  

map<int,int> ans;
map<int, int> :: iterator it;

void bfs(int v){
    queue<int> q;

    for(int i=0; i < list.size(); ++i)
        used.push_back(0);

    used[v] = true;
    q.push(v);
    ans[v] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int to = 0; to < gr[u].size(); ++to){
            if(gr[u][to] == 1 && !used[to]){
                used[to] = true;
                q.push(to);
                ans[to] = ans[u] + 1;
            }
        }
    }
}

void test_case(){

    int n; 
    cin >> n;

    string s;
    vector<vector<string> > v;
    vector<vector<int> > iv;
    vector<string> a;
    vector<int> temp;

    for(int i=0; i < n; ++i){
        a.clear();
        for(int j=0; j < 3; ++j){
            cin >> s;
            a.push_back(s);
            list[s] = 0;
        }
        v.push_back(a);
    }
    
    int k = 0;
    for(l_it = list.begin(); l_it != list.end(); ++l_it){
        (*l_it).second = k;
        k++;
    }

    //create a indexed vector  
    for(int i=0; i < v.size(); ++i){
        temp.clear();
        for(int j=0; j < v[i].size(); ++j){
            temp.push_back((*list.find(v[i][j])).second);
        }
        iv.push_back(temp);
    }
    //init the graph
    for(int i=0; i < list.size(); ++i){
        temp.clear();
        for(int j=0; j < list.size(); ++j){
            temp.push_back(0);
        }
        gr.push_back(temp);
    }
    //fill the graph
    for(int i=0; i < iv.size(); ++i){
        for(int j=0; j < iv[i].size(); ++j){
            for(int k = 0; k < 3; ++k){
                if(k == j) continue;
                int x = iv[i][j];
                int y = iv[i][k];
                gr[x][y] = 1;
            }
        }
    }
    if(list.find("Isenbaev") != list.end()){
        bfs((*list.find("Isenbaev")).second);
        for(l_it = list.begin(); l_it != list.end(); ++l_it){
            if(ans.find((*l_it).second) != ans.end()){
                it = ans.find((*l_it).second);
                cout << (*l_it).first << " " << (*it).second << endl;
            }else{
                cout << (*l_it).first << " " << "undefined" << endl;
            }
        }
    }else{
        for(l_it = list.begin(); l_it != list.end(); ++l_it){
            cout << (*l_it).first << " " << "undefined" << endl;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    
    test_case();

    return 0;
}