#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void numbers(vector<int> &arr, size_t n)
{
    arr[0] = 0;
    arr[1] = 1;

    for (size_t i = 2; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i / 2];
        }
        else
        {
            int k = (i - 1) / 2;
            arr[i] = arr[k] + arr[k + 1];
        }
    }
}

bool comparator(size_t a, size_t b)
{
    if (a > b)
        return true;
    return false;
}

int main()
{
    int m;
    vector<size_t> v;
    vector<size_t> copy;

    while (true){
        cin >> m;

        if (m != 0)
            v.push_back(m);
        else
            break;
    }

    for (size_t i = 0; i < v.size(); ++i)
        copy.push_back(v[i]);

    sort(v.begin(), v.end(), comparator);

    vector<int> arr(v[0] + 1);
    numbers(arr, v[0]);

    vector<int> maxi(v[0] + 1);
    int j = 0;
    maxi[j] = 0;

    for (size_t i = 0; i <= v[0]; ++i){
        if (arr[i] > maxi[j]){
            maxi[i] = arr[i];
            j = i;
        }
        else{
            maxi[i] = maxi[j];
        }
    }

    for (size_t i = 0; i < copy.size(); ++i){
        cout << maxi[copy[i]] << endl;
    }

    return 0;
}