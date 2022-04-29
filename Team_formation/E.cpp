//
//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//typedef unsigned long long ull;
//typedef long double ld;
//
//typedef vector<int> vi;
//typedef vector<long long> vll;
//typedef vector<double> vd;
//typedef vector<vi> vvi;
//typedef vector<string> vs;
//
//string LCM(vector<vector<int>> &mem, string s1, string s2) {
//
//    for (int n = 0; n < s1.size(); n++) {
//        for (int m = 0; m < s2.size(); m++) {
//            int insertion = mem[n + 1][m];
//            int deletion = mem[n][m + 1];
//            int match = mem[n][m] + 1;
//            if (s1[n] == s2[m])
//                mem[n + 1][m + 1] = match;
//            else
//                mem[n + 1][m + 1] = max(insertion, deletion);
//        }
//    }
//    int i = s1.size(), j = s2.size(), index = mem.back().back();
//    string LCMSTR;
//    while (i > 0 && j > 0) {
//        if (s1[i - 1] == s2[j - 1]) {
//            LCMSTR += s1[i - 1];
//            i--;
//            j--;
//        } else if (mem[i - 1][j] > mem[i][j - 1])
//            i--;
//        else
//            j--;
//    }
//    std::reverse(LCMSTR.begin(), LCMSTR.end());
//    return LCMSTR;
//}
//
//string Shortest_supersubsequence(vector<vector<int>> &mem, string s1, string s2) {
//    string LCMstr = LCM(mem, s1, s2);
//    string SSSstr = "";
//    int i = 0, j = 0;
//    for (auto c: LCMstr) {
//        while (i < s1.size() && s1[i] != c) {
//            SSSstr += s1[i];
//            i++;
//        }
//        while (j < s2.size() && s2[j] != c) {
//            SSSstr += s2[j];
//            j++;
//        }
//        SSSstr += c;
//        i++;
//        j++;
//    }
//    SSSstr += s1.substr(i) + s2.substr(j);
//    return SSSstr;
//}
//
//
//int main() {
//    string str1, str2;
//    cin >> str1 >> str2;
//    vector<vector<int>> mem(str1.size() + 1, vector<int>(str2.size() + 1));
//    string result = Shortest_supersubsequence(mem, str1, str2);
//    cout << result;
//    return 0;
//}