#include <iostream>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    
    bool desk[n][n];

    for(size_t i=0; i < n; ++i)
        for(size_t j=0; j < n; ++j)
            desk[i][j] = false;
    
    for(size_t i=0; i < n; ++i){
        for(size_t j=0; j < n; ++j){
            if(i == j)
                desk[i][j] = true;
        }
    }

    for(size_t i=0; i < n; ++i){
        desk[0][i] = true;
        desk[i][0] = true;
    }

    int count = 0;

    for(size_t i=0; i < n; ++i){
        for(size_t j=0; j < n; ++j){
            if(desk[i][j] == false)
                count++;
        }
    }

    printf("%d\n", count);

    return 0;
}