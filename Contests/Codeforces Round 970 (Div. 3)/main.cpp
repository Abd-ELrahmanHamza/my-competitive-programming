#include<iostream>
using namespace std;

int main() {
    char *s = "$#b";
    int frequency[26];
    for (int i = 0; i < 26; i++) {
        frequency[i] = 0;
    }
    for (int i = 0; i < 3; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            frequency[s[i] - 'A']++;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            frequency[s[i] - 'a']++;
        }
    }
    cout << "===============\n";
    for (int i = 0; i < 26; i++) {
        cout << char(i + 97) << " " << frequency[i] << endl;
    }
}
