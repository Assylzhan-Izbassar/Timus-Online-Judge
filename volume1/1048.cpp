//NOTE: scanf and printf are accelerated the time running.
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;  
    scanf("%d", &n);

    vector<int> a,b;

    int x,y;

    for(size_t i=0; i < n; ++i){
        scanf("%d %d", &x, &y);
        a.push_back(x);
        b.push_back(y);
    }

    int sum = 0;
    int carry = 0;

    vector<int> ans(n);

    for(int i = a.size() - 1; i >= 0; --i){
        sum = a[i] + b[i] + carry;

        carry = sum / 10;
        sum = sum % 10;

        ans[i] = sum;
    }

    if(carry != 0){
        cout << carry;
    }

    for(size_t i = 0; i < ans.size(); ++i){
        printf("%d", ans[i]);
    }
    cout << endl;

    return 0;
}