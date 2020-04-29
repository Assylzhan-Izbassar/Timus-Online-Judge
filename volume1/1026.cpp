/*
Вопросы и ответы
Ваша программа должна выступить в роли диспетчера этой базы данных; 
другими словами, она должна уметь быстро обрабатывать запросы описанного вида.
Запрос «какой элемент является i-м по величине» записывается для краткости просто одним числом i. 
База данных отделяется от серии запросов строкой из трёх решёток "#".
Полное условие задачи: https://acm.timus.ru/problem.aspx?space=1&num=1026

NOTE: В этой задаче quickSort работает быстрее чем mergeSort.
В целом mergeSort уступает insertionSort для n ≤ 43.
Асимптотика mergeSort O(n*logn)
*/

#include <iostream>
#include <vector>

using namespace std;

char s[4];

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(vector<int>& arr, int l, int r){
    int pivot = arr[r];
    int i = l - 1;

    for(size_t j = l; j < r; ++j){
        if(arr[j] < pivot){
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return (i+1);
}
void quickSort(vector<int>& arr, int l, int r){
    if(l < r){
        int p = partition(arr, l, r);

        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);  
    }
}

void merge(vector<int> &arr, int l, int mid, int r){
    int i,j,k;

    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for(i=0; i < n1; ++i)
        L[i] = arr[l + i];
    for(j=0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
            ++k;
        }
        else{
            arr[k] = R[j];
            ++j;
            k++;
        }
    }

    while(i < n1){
        arr[k] = L[i];
        ++k;
        ++i;
    }
    while(j < n2){
        arr[k] = R[j];
        ++k;
        ++j;
    }
}

void mergeSort(vector<int> &arr, int l, int r){
    if(l < r){
        int mid = l + (r-l)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

int main(){

    int n,m,x;
    vector<int> data;

    scanf("%d", &n);

    for(size_t i=0; i < n; ++i){
        scanf("%d", &x);
        data.push_back(x);
    }

    mergeSort(data, 0, data.size()-1);

    scanf("%s", s);

    vector<int> query;
    scanf("%d", &m);

    for(size_t i=0; i < m; ++i){
        scanf("%d", &x);
        query.push_back(x);
    }
    
    for(size_t i=0; i < query.size(); ++i)
        printf("%d\n", data[query[i]-1]);    

    return 0;
}