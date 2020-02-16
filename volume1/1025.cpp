#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    size_t k;
    cin >> k;

    vector<size_t> arr(k);

    for (size_t i = 0; i < k; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    k = k / 2 + 1;

    size_t needed = 0;

    for (size_t i = 0; i < k; ++i)
    {
        needed += (arr[i] / 2 + 1);
    }

    cout << needed << endl;

    return 0;
}