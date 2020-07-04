#include <iostream>

using namespace std;

void merge(int* arr, int l, int mid, int r){

    int i,j,k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1];
    int R[n2];

    for(i=0; i < n1; ++i){
        L[i] = arr[l+i];
    }
    for(j=0; j < n2; ++j){
        R[j] = arr[mid + 1 + j];
    }

    i=0;
    j=0;
    k=l;

    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int l, int r){
    if(l < r){
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];

    for(size_t i=0; i < n; ++i)
        scanf("%d", &arr[i]);

    mergeSort(arr,0,n-1);

    int sum = 0;

    for(int i=n-1; i >= 0; --i){
        if(arr[i] > 0 && m > 0){
            sum += arr[i];
            m--;
        }
        else
            break;
    }

    printf("%d", sum);

    return 0;
}