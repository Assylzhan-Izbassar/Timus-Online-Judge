#include <iostream>

using namespace std;

int main(){

    int x,y,z,w;
    scanf("%d %d %d %d", &x, &y, &z, &w);

    int count = 0;

    for(size_t i = 0; i <= 1000; ++i){
        for(size_t j = 0; j <= 1000; ++j){
            if(z != 1){
                if(w >= i*x+j*y && ((w - i*x - j*y) % z == 0))
                    count++;
            }
            if(z == 1){
                if(w >= i*x+j*y)
                    count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}