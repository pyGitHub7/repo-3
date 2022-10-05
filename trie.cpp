# include<bits/stdc++.h>
using namespace std;
class Trie {
    public:
    Trie *root = NULL;
    bool end;
    Trie *next[26];
    Trie() {
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        end = false;
    }
    void insert(string word) {
        if(root == NULL) {
            root = new Trie();
        }
        Trie *t = root;
        for(int i = 0; i < word.length(); i++) {
            int k = word[i] - 'a';
            if(t->next[k] == NULL) {
                t->next[k] = new Trie();
            }
            t = t->next[k];
        }
        t->end = true;
    }
    bool check(string word) {
        if(root == NULL) {
            root = new Trie();
        }
        Trie *t = root;
        for(int i = 0; i < word.length(); i++) {
            int k = word[i] - 'a';
            if(t->next[k] == NULL) {
                return false;
            }
            t = t->next[k];
        }
        return t->end;
    }
    bool startsWith(string word) {
        if(root == NULL) {
            return false;
        }
        Trie *t = root;
        for(int i = 0; i < word.size(); i++) {
            int k = word[i] - 'a';
            if(t->next[k] == NULL) {
                return false;
            }
            t = t->next[k];
        }
        return true;
    }
};
int main() {
    Trie t;
    t.insert("abcd");
    t.insert("abcde");
    t.insert("bc");
    t.insert("xyz");
    cout<<t.check("abcd")<<" "<<t.check("abcde")<<" "<<t.check("bc")<<" "<<t.check("a")<<endl;
}