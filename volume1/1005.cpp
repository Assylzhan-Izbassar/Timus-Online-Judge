/*
Write a program that will rearrange the stones into two piles such that weight difference between the piles is minimal.
NOTE: the recursive functions are useful for backtracking methods of solution.
*/
#include <iostream>
#include <vector>
#include <algorithm> // std::min

using namespace std;

int mini = 10000000;

vector<int> arr;

void diff(size_t i, int bag_1, int bag_2){
    if(i == arr.size()){
        mini = min(mini, abs(bag_1 - bag_2));
    }
    else{
        diff(i+1, bag_1 + arr[i], bag_2);
        diff(i+1, bag_1, bag_2 + arr[i]);
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int x;

    for(size_t i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        arr.push_back(x);
    }

    diff(0, 0, 0);

    printf("%d\n", mini);

    return 0;
}