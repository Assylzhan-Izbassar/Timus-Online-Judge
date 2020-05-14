#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    vector<vector<int> > arr;

    vector<int> temp;
    int x;

    for(size_t i=0; i < n; ++i){
        temp.clear();
        for(size_t j=0; j < n; ++j){
            scanf("%d", &x);
            temp.push_back(x);
        }
        arr.push_back(temp);
    }   

    return 0;
}