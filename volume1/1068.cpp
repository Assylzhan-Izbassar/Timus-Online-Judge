#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;

    if (n > 0){
        for (size_t i = 1; i <= n; ++i){
            sum += i;
        }
    }
    else{
        for(int i=n; i <= 1; ++i){
            sum = sum + i;
        }
    }

    cout << sum << endl;

    return 0;
}