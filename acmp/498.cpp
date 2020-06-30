#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> arr;
    int n,k; 
    scanf("%d %d", &n, &k);

    for(size_t i=1; i <= n; ++i)
        arr.push_back(i);

    int count = 0;
    bool isPermute = true;

    do{
        isPermute = true;
        for(size_t i=0; i < arr.size()-1; ++i){
            if(abs(arr[i]-arr[i+1]) > k){
                isPermute = false;
                break;
            }
        }
        if(isPermute)
            count++;

    }while(next_permutation(arr.begin(), arr.end()));

    printf("%d\n", count);
    
    return 0;
}