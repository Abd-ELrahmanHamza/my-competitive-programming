#include <vector>
#include <string>
#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;


struct TrieString {
    vector<TrieString *> child;
    bool isLeaf;
    int prefixCnt, endsWithCount;

    TrieString() {
        child.resize(26, nullptr);
        isLeaf = false;
        endsWithCount = 0;
        prefixCnt = 0;
    }

    void insert(string &s, int index) {
        if (index == s.size()) {
            isLeaf = true;
            endsWithCount++;
        } else {
            int cur = s[index] - 'a';
            if (child[cur] == nullptr) {
                child[cur] = new TrieString();
            }
            child[cur]->insert(s, index + 1);
            child[cur]->prefixCnt++;
        }
    }

    bool wordExist(string &s, int index) {
        if (index == s.size())
            return isLeaf;
        int cur = s[index] - 'a';
        if (child[cur] == nullptr) {
            return false;
        }
        return child[cur]->wordExist(s, index + 1);
    }

    bool prefixExist(string &s, int index) {
        if (index == s.size())
            return true;
        else {
            int cur = s[index] - 'a';
            if (child[cur] == nullptr) {
                return false;
            }
            return child[cur]->prefixExist(s, index + 1);
        }
    }

    int prefixCount(string &s, int index) {
        if (index == s.size()) {
            return prefixCnt;
        } else {
            int cur = s[index] - 'a';
            if (child[cur] == nullptr) {
                return 0;
            }
            return child[cur]->prefixCount(s, index + 1);
        }
    }

    int wordCount(string &s, int index) {
        if (index == s.size()) {
            return endsWithCount;
        } else {
            int cur = s[index] - 'a';
            if (child[cur] == nullptr) {
                return 0;
            }
            return child[cur]->wordCount(s, index + 1);
        }
    }

    int longestPrefix(string &s, int index, int cnt) {
        if (index == s.size()) {
            if (prefixCnt != cnt)
                return index - 2;
            return index - 1;
        } else if (prefixCnt != cnt) {
            return index - 2;
        } else {
            int cur = s[index] - 'a';
            return child[cur]->longestPrefix(s, index + 1, cnt);
        }
    }
};

int main() {


    TrieString *myTrie = new TrieString();

    string s = "ab";
    myTrie->insert(s, 0);
    s = "a";
    myTrie->insert(s, 0);
//    s = "apple";
//    myTrie->insert(s, 0);

//    s = "apaple";
//    cout << myTrie->prefixCount(s, 0) << endl;
//    s = "apple";
//    cout << myTrie->wordCount(s, 0) << endl;
    s = "ab";
    myTrie->prefixCnt = 2;
    cout << myTrie->longestPrefix(s, 0, 2) << endl;

    return 0;
}