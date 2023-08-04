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

    void getAllProperPref(string comS, const string s, int index, vector<string> &strs) {
        if (index < s.size()) {
            int cur = s[index] - 'a';
            if (child[cur] != nullptr) {
                child[cur]->getAllProperPref(comS, s, index + 1, strs);
            }
        } else {
            if (isLeaf && index > s.size()) {
                strs.push_back(comS);
            }
            for (int i = 0; i < 26; ++i) {
                if (child[i] != nullptr) {
                    child[i]->getAllProperPref(comS + char('a' + i), s, index + 1, strs);
                }
            }
        }
    }
};

int main() {
    TrieString *myTrie = new TrieString();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        myTrie->insert(s, 0);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        vector<string> strs;
        string comS = s;
        myTrie->getAllProperPref(comS, s, 0, strs);
        cout << "Case #" << i + 1 << ":\n";
        for (string s: strs) {
            cout << s << "\n";
        }
        if (strs.empty()) {
            cout << "No match.\n";
        }
    }
    return 0;
}