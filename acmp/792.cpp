#include <iostream>
#include <vector>

using namespace std;

int sum_in_base(int n, int p){
    int sum = 0;

    while(n > 0){
        sum += (n % p);
        n /= p;
    }

    return sum;
}

int main(){

    int n1,p1,n2,p2;
    scanf("%d %d %d %d", &n1, &p1, &n2, &p2);

    if(sum_in_base(n1, p1) == sum_in_base(n2,p2))
        printf("%d\n", sum_in_base(n1,p1));
    else
        printf("%d\n", 0);
    
    return 0;
}