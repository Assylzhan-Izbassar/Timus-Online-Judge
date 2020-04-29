/*Content of the task in https://acm.timus.ru/problem.aspx?space=1&num=1082.
The purpose of this problem is to know the complexity of the quick sort algorithm, that is sorted 
array it's complexity is O((n^2+3*n-4)/2);
*/

#include <iostream>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    for(size_t i=1; i <= n; ++i){
        printf("%lu ", i);
    }
    cout << endl;

    return 0;
}