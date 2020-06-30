#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    vector<int> arr(n);

    for(size_t i=0; i < n; ++i)
        scanf("%d", &arr[i]);

    int maxi = arr[0];

    for(size_t i=0; i < n; ++i){
        if(arr[i] > maxi)
            maxi = arr[i];
    }
    
    vector<int> degree;
    int zero = 0;

    while(degree.size() <= maxi + 1){
        degree.push_back(1);

        zero++;
    }

    for(size_t i=0; i < degree.size(); ++i)
        cout << degree[i];

    cout << endl;
    

    return 0;
}