/*
Таинство суммы
Ваша программа должна определять,можно ли из двух списков целых чисел 
выбрать по одному числу так, чтобы в сумме они составили 10000.
Задача: https://acm.timus.ru/problem.aspx?space=1&num=1021
*/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int key){
    while(l <= r){
        int mid = l + (r-l)/2;

        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}

int main(){

    int n, m, x;
    scanf("%d", &n);
    
    vector<int> l1,l2;

    for(size_t i=0; i < n; ++i){
        scanf("%d", &x);
        l1.push_back(x-10000);
    }

    scanf("%d", &m);

    for(size_t k = 0; k < m; ++k){
        scanf("%d", &x);
        l2.push_back(x*(-1));
    } 

    for(size_t i=0; i < l2.size(); ++i){
        if(binarySearch(l1, 0, l1.size() - 1, l2[i]) != -1){
            cout << "YES\n";
            return 0;
        } 
    }

    cout << "NO\n";

    return 0;
}