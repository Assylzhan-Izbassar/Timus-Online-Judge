/*
Ваша задача — найти минимальное положительное целое число Q такое, что произведение цифр числа Q в точности равняется N.
Ссылка задачи: https://acm.timus.ru/problem.aspx?space=1&num=1014
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    if(n == 0){
        printf("%d\n", 10);
        exit(0);
    }
    if(n == 1){
        printf("%d\n", 1);
        exit(0);
    }

    vector<int> ans;

    for(int k=9; k >= 2; --k){
        while(n % k == 0 && n > 1){
            ans.push_back(k);
            n /= k;
        }
    }
    if(n != 1){
        printf("%d", -1);
        exit(0);
    }

    vector<int> :: reverse_iterator it;

    for(it = ans.rbegin(); it != ans.rend(); ++it)
        printf("%d", (*it));
    
    cout << endl;

    return 0;
}