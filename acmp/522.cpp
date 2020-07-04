#include <iostream>
#include <vector>
using namespace std;

vector<bool> linearSearch(int* arr, int n, int key){
    vector<bool> likewise(n, false);

    for(size_t i=0; i < n; ++i){
        if(arr[i] == key)
            likewise[i] = true;
    }
    return likewise;
}

int isSubset(int* a, int* b, int n, int m){ //let a is always less than b

    vector<bool> likewise = linearSearch(b, m, a[0]);

    bool isTrue = true;

    for(size_t i=0; i < m; ++i){
        bool check = true;
        if(likewise[i] == true){
            for(size_t j=0; j < n; ++j){
                if(a[j] != b[i+j])
                {
                    check = false;
                    break;
                }
            }
        }
        if(!check)
            isTrue = false;
        else
            isTrue = true;
    }

    return isTrue;
}
int main(){

    int n,m;
    scanf("%d %d", &n, &m);

    int a[n], b[m];

    for(size_t i=0; i < n; ++i)
        scanf("%d", &a[i]);
    for(size_t i=0; i < m; ++i)
        scanf("%d", &b[i]);

    if(n > m){
        cout << isSubset(b,a,m,n);
    }
    else{
        cout << isSubset(a,b,n,m);
    }
    cout << endl;

    return 0;
}