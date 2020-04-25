/*
    Nim is a mathematical game of strategy in which two players take turns removing 
(or "nimming") objects from distinct heaps or piles.
    The soundness of the optimal strategy described above was demonstrated by C. Bouton.
    THEOREM In a normal Nim game, the player making the first move has a winning strategy 
if and only if the nim-sum of the sizes of the heaps is not zero. Otherwise, 
the second player has a winning strategy.
    You can read about that in: http://e-maxx.ru/algo/sprague_grundy
*/

//!!!Incomplete

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n,m;
    scanf("%d %d", &n, &m);

    vector<int> heap(m);
    vector<int> p;

    for(size_t i=0; i < m; ++i)
        scanf("%d", &heap[i]);

    sort(begin(heap), end(heap));

    while(n <= 0){
        for(size_t i=0; i < heap.size(); ++i){
            if(n - heap[i] > 0){
                p.push_back(heap[i]);
                n = n - heap[i];
            }
        }
    }

    int sum = heap[0];

    for(size_t i=0; i < p.size(); ++i){
        sum = sum ^ p[i];
    }

    if(sum == 0){
        printf("%d\n", 1);
    }
    else{
        printf("%d\n", 2);
    }

    return 0;
}