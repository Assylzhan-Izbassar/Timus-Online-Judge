#include <iostream>
#include <vector>

using namespace std;

int main(){

    float n;
    scanf("%f", &n);

    size_t count = 0;
    float sum = 0;

    size_t i = 2;

    while(sum <= n){
        sum += 1/i;
        count++;
        i++;
    }

    printf("%lu\n", count);

    return 0;
}