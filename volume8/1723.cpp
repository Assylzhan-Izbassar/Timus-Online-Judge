#include <iostream>
#include <map>

using namespace std;

struct vertex{
    map<char, vertex*> next;
    bool leaf;
    string prefix;

    vertex(string _prefix){
        prefix = _prefix;
        leaf = false;
    }
};

class Trie{
    private:
        vertex* root;
        void printNodeInfo(vertex* node){
            map<char, vertex*> :: iterator it;
            for(it = node->next.begin(); it != node->next.end(); ++it){
                cout << it->second->prefix << " " << it->second->leaf << endl;
            }
        }
    
    public:
        Trie(){
            root = new vertex("");
        }
        void addString(string s){
            vertex* current = root;

            for(size_t i=0; i < s.size(); ++i){
                if(current->next.find(s[i]) == current->next.end()){
                    current->next[s[i]] = new vertex(current->prefix + s[i]);
                }
                current = current->next[s[i]];
            }
            current->leaf = true;
        }
        void print(vertex* current){
            map<char, vertex*> :: iterator it;
            printNodeInfo(current);
            it = current->next.begin();
            while(it != current->next.end()){
                print(it->second);
                it++;
            }
        }
        vertex* getRoot(){
            return root;
        }
};

int main(){ 

    Trie t;
    string s;
    getline(cin, s);

    t.addString(s);
    t.print(t.getRoot());

    return 0;
}