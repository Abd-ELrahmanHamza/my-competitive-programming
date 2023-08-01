#include <vector>
#include <string>
#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;


struct TrieString {
    vector<TrieString *> child;
    bool isLeaf;

    TrieString() {
        child.resize(10, NULL);
        isLeaf = false;
    }

    void insert(string &s, int index) {
        if (index == s.size())
            isLeaf = true;
        else {
            int cur = s[index] - '0';
            if (child[cur] == NULL) {
                child[cur] = new TrieString();
            }
            child[cur]->insert(s, index + 1);
        }
    }

    bool wordExist(string &s, int index) {
        if (index == s.size())
            return isLeaf;

        int cur = s[index] - '0';
        if (child[cur] == NULL) {
            return false;
        }
        return child[cur]->wordExist(s, index + 1);
    }

    bool prefixExist(string &s, int index) {
        int cur = s[index] - '0';
        if (index == s.size() || (child[cur] != NULL && child[cur]->isLeaf))
            return true;
        else {
            if (child[cur] == NULL) {
                return false;
            }
            return child[cur]->prefixExist(s, index + 1);
        }
    }
};

int main() {
    int T, N;
    string aux;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);

        TrieString *myTrie = new TrieString();


        bool valid = false;

        for (int i = 0; i < N; ++i) {
            char tmp[10];
            scanf("%10s", tmp);
            aux = tmp;
            if (!valid) {
                valid = myTrie->prefixExist(aux, 0);
                myTrie->insert(aux, 0);
            }
        }
        printf("%s\n", valid ? "NO" : "YES");
    }

    return 0;
}