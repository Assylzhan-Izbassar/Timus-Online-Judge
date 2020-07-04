#include <iostream>

using namespace std;

int main(){

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int max_a = INT_MIN, max_b = INT_MIN;

    for(int x=1; x <= m; ++x){
        for(int a=0; a < k; ++a){
            if((x-a) % k == 0){
                int b = (x-a) / k;
                if(a > max_a)
                    max_a = a;
                if(b > max_b)
                    max_b = b;
            }
        }
    }

    printf("%d\n", (max_a+max_b)*n);

    return 0;
}