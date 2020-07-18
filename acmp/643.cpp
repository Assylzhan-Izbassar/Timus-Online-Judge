#include <iostream>
#include <vector>

using namespace std;

int count_in_binary(int n){
    int count = 0;

    while(n > 0){
        if(n % 2 == 1)
            count++;
        n /= 2;
    }

    return count;
}

int main(){

    int n;
    scanf("%d", &n);

    printf("%d\n", n + count_in_binary(n));

    return 0;
}