//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    string s;
//    vector<int> open, close;
//    cin >> s;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == '(')
//            open.push_back(i);
//        else
//            close.push_back(i);
//    }
//    std::reverse(close.begin(), close.end());
//    vector<int> result;
//    for (int i = 0; i < min(close.size(), open.size()); i++) {
//        if (close[i] > open[i]) {
//            result.push_back(close[i]);
//            result.push_back(open[i]);
//        } else {
//            break;
//        }
//    }
//    if (result.size() == 0)
//        cout << 0;
//    else {
//        cout << 1 << endl;
//        cout << result.size() << endl;
//        sort(result.begin(), result.end());
//        for (int x: result)cout << x + 1 << " ";
//    }
//    return 0;
//}
