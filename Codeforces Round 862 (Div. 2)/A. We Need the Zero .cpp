
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef vector<string> vs;
#define rep(i, v) for(int i=0;i<v.size();++i)
#define readV(v) for(int i=0;i<v.size();++i)cin>>v[i];
#define printV(v) for(int i=0;i<v.size();++i)cout<<v[i]<<" ";

//struct Trie {
//    Trie *child[26];
//    bool isLeaf;
//
//    Trie() {
//        memset(child, 0, sizeof(child));
//        isLeaf = false;
//    }
//
//    void insert(char *str) {
//        if (*str == '\0')
//            isLeaf = true;
//        else {
//            int cur = *str - 'a';
//            if (child[cur] == 0) {
//                child[cur] = new Trie();
//            }
//            child[cur]->insert(str + 1);
//        }
//    }
//
//    bool wordExist(char *str) {
//        if (*str == '\0')
//            return isLeaf;
//
//        int cur = *str - 'a';
//        if (child[cur] == 0) {
//            return false;
//        }
//        return child[cur]->wordExist(str + 1);
//    }
//
//    void prefixExist(char *str) {
//        if (*str == '\0')
//            isLeaf = true;
//        else {
//            int cur = *str - 'a';
//            if (child[cur] == 0) {
//                child[cur] = new Trie();
//            }
//            child[cur]->prefixExist(str + 1);
//        }
//    }
//};

vll prime_factors(ll n) {
    vll primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        primes.push_back(n);
    return primes;
}

set<ll> prime_factors_set(ll n) {
    set<ll> primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes.insert(i);
            n /= i;
        }
    }
    if (n > 1)
        primes.insert(n);
    return primes;
}

unordered_map<ll, ll> prime_factors_map(ll n, set<ll> &s) {
    unordered_map<ll, ll> primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes[i]++;
            s.insert(i);
            n /= i;
        }
    }
    if (n > 1) {
        s.insert(n);
        primes[n]++;
    }
    return primes;
}

ll binary_search_n(ll s, ll e, ll k) {
    ll middle = (s + e) / 2;
    if (k == middle)
        return 1;
    else if (k < middle)
        return 1 + binary_search_n(s, middle - 1, k);
    else
        return 1 + binary_search_n(middle + 1, e, k);
}

vll prefix_sum(vll v) {
    v.insert(v.begin(), 0);
    vll s(v.size());
    for (int i = 1; i < v.size(); ++i) {
        s[i] += v[i] + s[i - 1];
    }
    return s;
}

ll sum_range(int s, int e, vll &preSum) {
    return preSum[e] - preSum[s - 1];
}

ll binary_search_increasing(ll s, ll e, ll k, const vll &v) {
    if (e < s)
        return -1;

    ll middle = s + (e - s) / 2;
    if (k == v[middle])
        return middle;
    else if (k < v[middle])
        return binary_search_increasing(s, middle - 1, k, v);
    else
        return binary_search_increasing(middle + 1, e, k, v);
}

ll binary_search_decreasing(ll s, ll e, ll k, const vll &v) {
    if (e < s)
        return -1;

    ll middle = s + (e - s) / 2;
    if (k == v[middle])
        return middle;
    else if (k > v[middle])
        return binary_search_decreasing(s, middle - 1, k, v);
    else
        return binary_search_decreasing(middle + 1, e, k, v);
}

bool isPrime(ll n) {
    if (n == 2)return true;
    if (n <= 2 || n % 2 == 0)return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<bool> primesInRange_sieve(int n) { // O( nlog(log(n)) )
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

ll number_of_divisors(ll n) {
    set<ll> dummySet;
    unordered_map<ll, ll> uMap = prime_factors_map(n, dummySet);
    ll result = 1;
    for (auto p: uMap) result *= (p.second + 1);
    return result;
}

bool isPowerOfTwo(ll n) {
    ll x = n - 1;
    return (n & (x)) == 0;
}

ll power(ll x, ll y, ll mod = 1) {
    ll ans = 1;
    for (ll i = 0; i < y; i++) {
        ans = ((ans % mod) * (x % mod)) % mod;
    }
    return ans;
}

bool compare(pair<ll, char> p1, pair<ll, char> p2) {
    if (p1.first > p2.first)
        return true;
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return false;
}


int Dijkstra(vector<vector<pair<ll, pair<ll, ll >> >> adjList, int
src,
             int dest = -1
)    // O(E logV)
{
    int n = adjList.size();
    vi dist(n, INT_MAX), prev(n, -1);
    dist[src] = 0;

    priority_queue<pair<ll, pair<ll, ll>>>
            q;
    q.
            push(make_pair(0, make_pair(-1, src))
    );

    while (!q.

            empty()

            ) {
        pair<ll, pair<ll, ll>> e = q.top();
        q.

                pop();

        int w = e.first, from = e.second.first, to = e.second.second;
        if (w > dist[to]) continue;    // some other state reached better

        prev[to] =
                from;

        rep(j, adjList[to]) {
            pair<ll, pair<ll, ll>> ne = adjList[to][j];
            int neww = ne.first, nefrom = ne.second.first, neto = ne.second.second;

            if (dist[neto] > dist[nefrom] + neww) {
                neww = dist[neto] = dist[nefrom] + neww;
                q.
                        push(ne);
            }
        }
    }

    return dist[dest] == INT_MAX ? -1 : dist[dest];
}


map<int, bool> visitedbipartite;

bool bipartite_BFS(int s, map<int, vector<int>> &adjList) {
    map<int, int> color;
    queue<int> q;

    q.push(s);
    color[s] = 1;
    int dep = 0, cur = s, sz = 1;

    for (; !q.empty(); ++dep, sz = q.size()) {
        while (sz--) {
            cur = q.front();
            visitedbipartite[cur] = true;
            q.pop();
            for (int i = 0; i < adjList[cur].size(); ++i) {
                if (!visitedbipartite[adjList[cur][i]]) {
                    q.push(adjList[cur][i]);
                    color[adjList[cur][i]] = (color[cur] == 1 ? 2 : 1);
                } else if (color[adjList[cur][i]] == color[cur]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool out_of_5(const vi &v, int index, ll curResult) {
    if (index == 5)return curResult == 23;
    return (
            out_of_5(v, index + 1, curResult + v[index]) ||
            out_of_5(v, index + 1, curResult - v[index]) ||
            out_of_5(v, index + 1, curResult * v[index])
    );
}

ll fastPower(ll base, ll power) {
    if (power == 0)return 1;
    ll res = fastPower(base, power / 2);
    res *= res;
    if (power % 2)return res * base;
    else return res;
}

ll fastPowerWithMod(ll base, ll power, ll p) {
    if (power == 0)return 1;
    ll res = fastPowerWithMod(base, power / 2, p);
    res = ((res % p) * (res % p)) % p;
    if (power % 2)return (res % p * base % p) % p;
    else return res;
}

unsigned int getFirstSetBitPos(int n) {
    return log2(n & -n) + 1;
}

int bitCount(unsigned int u) // O(1)
{
    unsigned int uCount;

    uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
    return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

ull factorial(ll n) {
    ull result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

ll nCr(ll n, ll r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

bool isTree_dfs(int node, const vvi &adj, vector<bool> &visited) {
    if (visited[node])return false;

    visited[node] = true;
    for (auto n: adj[node]) {
        if (!isTree_dfs(n, adj, visited))
            return false;
    }
    return true;
}

long long C(int n, int r) {
    if (r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int n, m, k;
vector<pair<int, int>> burned;
vector<vector<int>> forest;
vector<vector<bool>> visited;
vector<int> directionx = {0, 0, 1, -1};
vector<int> directiony = {1, -1, 0, 0};
queue<pair<int, int>> q;


bool valid(int i, int j) {
    return i < n && i >= 0 && j < m && j >= 0;
}


void BFS() {
    while (!q.empty()) {

        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
//        cout << "Cur node = " << x << " " << y << endl;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int adjx = x + directionx[i];
            int adjy = y + directiony[i];

            if (valid(adjx, adjy) && !visited[adjx][adjy]) {
                q.push({adjx, adjy});
//                cout << adjx << " " << adjy << endl;
                visited[adjx][adjy] = true;
                forest[adjx][adjy] = min(forest[adjx][adjy], forest[x][y] + 1);
            }
        }
    }
}

//int n, m;
//vector<vector<int>> adj;
//vector<bool> visited;
//
//void dfs(int node, int parent, int &cnt, bool &cycle) {
//    cnt++;
//    visited[node] = true;
//    for (int i = 0; i < adj[node].size(); ++i) {
//        int child = adj[node][i];
//        if (parent != child && visited[child])
//            cycle = true;
//        else if (child != parent)
//            dfs(child, node, cnt, cycle);
//    }
//}
//
//int solve() {
//    int remove = 0;
//    for (int i = 0; i < n; ++i) {
//        if (!visited[i]) {
//            bool cycle = false;
//            int cnt = 0;
//            dfs(i, -1, cnt, cycle);
//            if (cycle) {
////                cout << "Cycle\n";
//                remove += cnt % 2;
//            }
//        }
//    }
//    remove += (n - remove) % 2;
//    return remove;
//}


string minWindow(string s, string t) {
    int l = 0, r = 0;
    int start = -1;
    unordered_map<char, int> um;
    set<char> ss;
    int needed = t.size();
    for (char c: t) {
        um[c]++;
        ss.insert(c);
    }
    int res = INT_MAX;
    while (r < s.size()) {
        if (--um[s[r]] >= 0)needed--;
        while (needed == 0) {
            if (res > r - l + 1) {
                res = r - l + 1;
                start = l;
            }
            um[s[l]]++;
            if (um[s[l]] > 0) {
                needed++;
            }
            l++;
        }

        cout << l << " " << r << endl;
        r++;
    }
    return start != -1 ? s.substr(start, res) : "";
}

//class Trie {
//private:
//
//
//    void helpInsert(const string word, int index) {
//        if (index == word.size()) {
//            isLeaf = true;
//            return;
//        }
//        char curChar = word[index] - 'a';
//        if (!children[curChar]) {
//            children[curChar] = new Trie();
//        }
//        children[curChar]->helpInsert(word, index + 1);
//    }
//
//    void helpInsertIterative(const string word) {
//        Trie **curChild = &children[word[0] - 'a'];
//        for (int i = 0; i < word.size() - 1; ++i) {
//            if (!*curChild) {
//                *curChild = new Trie();
//            }
//            char curChar = word[i + 1] - 'a';
//            curChild = &((*curChild)->children[curChar]);
//        }
//        if (!*curChild) {
//            *curChild = new Trie();
//        }
//        (*curChild)->isLeaf = true;
//    }
//
//    bool helpSearchIterative(const string word) {
//        Trie *curChild = children[word[0] - 'a'];
//        for (int i = 0; i < word.size() - 1; ++i) {
//            if (!curChild) {
//                return false;
//            }
//            char curChar = word[i + 1] - 'a';
//            curChild = curChild->children[curChar];
//
//        }
//        if (!curChild) {
//            return false;
//        }
//        return curChild->isLeaf;
//    }
//
//    bool helpPrefixIterative(const string word) {
//        Trie *curChild = children[word[0] - 'a'];
//        for (int i = 0; i < word.size() - 1; ++i) {
//            if (!curChild) {
//                return false;
//            }
//            char curChar = word[i + 1] - 'a';
//            curChild = curChild->children[curChar];
//        }
//        if (!curChild) {
//            return false;
//        }
//        return true;
//    }
//
//
//    bool helpSearch(const string word, int index) {
//        if (index == word.size()) {
//            return isLeaf;
//        }
//        char curChar = word[index] - 'a';
//        if (!children[curChar]) {
//            return false;
//        }
//        return children[curChar]->helpSearch(word, index + 1);
//    }
//
//    bool helpPrefix(const string word, int index) {
//        if (index == word.size()) {
//            return true;
//        }
//        char curChar = word[index] - 'a';
//        if (!children[curChar]) {
//            return false;
//        }
//        return children[curChar]->helpPrefix(word, index + 1);
//    }
//
//public:
//    vector<Trie *> children;
//    bool isLeaf;
//
//    Trie() {
//        isLeaf = false;
//        children = vector<Trie *>(26, nullptr);
//    }
//
//    void insert(string word) {
//        helpInsertIterative(word);
//    }
//
//    bool search(string word) {
//        return helpSearchIterative(word);
//    }
//
//    bool startsWith(string prefix) {
//        return helpPrefixIterative(prefix);
//    }
//};


bool isValid(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}
//
//void dfsFindWords(vector<vector<char>> &board, vector<string> &words, int i, int j, Trie *trie, set<string> &res,
//                  string word) {
//    int dy[] = {1, -1, 0, 0};
//    int dx[] = {0, 0, -1, 1};
//    word += board[i][j];
//
//    if (!trie) {
//        return;
//    }
//    if (trie->isLeaf) {
//        res.insert(word);
//    }
//    char back = board[i][j];
//    board[i][j] = '.';
//    for (int k = 0; k < 4; ++k) {
//        if (isValid(i + dx[k], j + dy[k], board.size(), board[0].size()) && board[i + dx[k]][j + dy[k]] != '.') {
//            dfsFindWords(board, words, i + dx[k], j + dy[k], trie->child[board[i + dx[k]][j + dy[k]] - 'a'], res, word);
//        }
//    }
//    board[i][j] = back;
//}
//
//vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
//    Trie trie;
//    for (string word: words) {
//        trie.insert(word);
//    }
//    vector<string> res;
//    set<string> s;
//    for (int i = 0; i < board.size(); ++i) {
//        for (int j = 0; j < board[0].size(); ++j) {
//            if (trie.child[board[i][j] - 'a'] != 0)
//                dfsFindWords(board, words, i, j, trie.child[board[i][j] - 'a'], s, "");
//        }
//    }
//    for (string word: s)cout << "here " << word << endl;
//
//    return vector<string>(s.begin(), s.end());
//}

string longestPalindrome(string s) {
    string ans;
    for (int i = 0; i < s.size(); ++i) {
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l--] == s[r++]);
//        if (l < 0 || r >= s.size())
        l++, r--;
        cout << i << " : " << l << " " << r << endl;
        if (r - l + 1 > ans.size()) {
            ans = s.substr(max(l, 0), min(r, (int) s.size() - 1) - l + 1);
        }
        l = i, r = i + 1;
        while (l >= 0 && r < s.size() && s[l--] == s[r++]);
//        if (l < 0 || r >= s.size())l++, r--;
        l++, r--;

        if (r - l + 1 > ans.size()) {
            ans = s.substr(max(l, 0), min(r, (int) s.size() - 1) - l + 1);
        }
    }
    return ans;
}

int longestConsecutive(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int l = 0, r = 1;
    int ans = 1;
    while (r < nums.size()) {
        while (nums[r] > nums[r - 1])r++;
        ans = max(ans, r - l);
        l = r;
    }
    return ans;
}


void solve(vector<vector<int>> &image, int sr, int sc, int color) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int oldColor = image[sr][sc];
    image[sr][sc] = color;
    for (int i = 0; i < 4; ++i) {
        if (isValid(sr + dx[i], sc + dy[i], image.size(), image[0].size()) &&
            image[sr + dx[i]][sc + dy[i]] == oldColor) {
            solve(image, sr + dx[i], sc + dy[i], color);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    solve(image, sr, sc, color);
    return image;
}

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    priority_queue<pair<int, int>, vector<pair<int, int >>, greater<pair<int, int>>> q;
    for (int i = 0; i < intervals.size(); ++i) {
        q.push({intervals[i][1], intervals[i][1]});
    }
    int cnt = 0;
    int curEnd = INT_MIN;
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (p.first < curEnd) {
            cnt++;
            curEnd = p.second;
        }
    }
    return cnt;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int l, int r, int &index) {
    if (l > r)return nullptr;
    TreeNode *newNode = new TreeNode(preorder[index]);
    index++;
    int rootIndex = std::distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[index]));
    newNode->left = solve(preorder, inorder, l, rootIndex - 1, index);
    newNode->right = solve(preorder, inorder, rootIndex + 1, r, index);
    return newNode;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int index = 0;
    TreeNode *res = solve(preorder, inorder, 0, inorder.size() - 1, index);
    return res;
}

bool compareInterval(vector<int> i1, vector<int> i2) {
    return (i1[0] < i2[0]);
}

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<int> start = {-1, -1}, end = {-1, -1};
    vector<vector<int>> res;
    for (int i = 0; i < intervals.size(); ++i) {
        if ((intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]) ||
            (intervals[i][0] >= newInterval[0] && intervals[i][1] <= newInterval[1]) ||
            (intervals[i][0] >= newInterval[0] && intervals[i][1] >= newInterval[1])
                ) {
            if (start[0] == -1) {
                start = intervals[i];
            }
            end = intervals[i];
            intervals[i] = {-1, -1};
        } else {
            res.push_back(intervals[i]);
        }
    }
    vector<int> added;
    if (start[0] != -1) {
        added = {min(start[0], newInterval[0]), max(end[1], newInterval[1])};
    }
    res.push_back(added);
    sort(res.begin(), res.end(), compareInterval);
    return res;
}

//int characterReplacement(string s, int k) {
//    int l = -1, r = -1;
//    unordered_map<char, int> um;
//    int unique = 0, ans = 0;
//    while (r < s.size()) {
//
//        while (unique <= k + 1) {
//            ans = max(r - l + 1, ans);
//            r++;
//            um[s[r]]++;
//            if (um[s[r]] == 1) {
//                unique++;
//            }
//        }
//        while (unique > k + 1) {
//            l++;
//            um[s[l]]--;
//            if (um[s[l]] == 0) {
//                unique--;
//            }
//        }
//    }
//    return ans;
//}

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int median;
    int size;
public:
    MedianFinder() {
        size = 0;
    }

    void addNum(int num) {
        if (size == 0) {
            cout << "zero size " << num << endl;
            median = num;
        } else if (size & 1/* odd */) {
            cout << "odd size " << num << endl;
            if (num >= median) {
                right.push(num);
                left.push(median);
            } else {
                left.push(num);
                right.push(median);
            }
        } else {
            cout << "even size " << num << endl;
            if (num >= right.top()) {
                right.push(num);
                this->median = right.top();
                right.pop();
            } else {
                left.push(num);
                this->median = left.top();
                left.pop();
            }
        }
        cout << left.size() << " " << right.size() << endl;
        if (left.size() > 0)
            cout << left.top() << " " << right.top() << endl;
        size++;
    }

    double findMedian() {
        if (size & 1) {
            return median;
        } else {
            return ((double) left.top() + (double) right.top()) / 2.0;
        }
    }
};


int characterReplacement(string s, int k) {
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        int l = 0, r = 0, cnt = 0;
        cout << (char) ('A' + i) << endl;
        while (r < s.size()) {
            while (r < s.size() && cnt <= k) {
                if (s[r] != 'A' + i) {
                    cnt++;
                }
                if (cnt > k)break;
                r++;
            }
            cout << r << " " << cnt << endl;
            ans = max(r - l, ans);
            while (cnt > k) {
                if (s[l] != 'A' + i) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
    }
    return ans;
}

vector<vector<int>> res;

void solve(vector<int> &candidates, int target, int index, int curSum, vector<int> curList) {
    if (index >= candidates.size())return;
    if (curSum > target)return;
    if (curSum == target) {
        res.push_back(curList);
    }
    solve(candidates, target, index + 1, curSum, curList);
    curList.push_back(candidates[index]);
    solve(candidates, target, index + 1, curSum + candidates[index], curList);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    solve(candidates, target, 0, 0, vector<int>());
    return res;
}


class priorityQueue {
    vector<int> heap;

    int left(int node) {
        return 2 * node + 1 >= heap.size() ? -1 : 2 * node + 1;
    }

    int right(int node) {
        return 2 * node + 2 >= heap.size() ? -1 : 2 * node + 2;
    }

    int parent(int node) {
        return (node - 1) / 2 < 0 ? -1 : (node - 1) / 2;
    }

    void reHeapUp(int pos) {
        int parentNode = parent(pos);
        if (pos == 0 || heap[pos] > heap[parentNode])return;
        swap(heap[pos], heap[parentNode]);
        reHeapUp(parentNode);
    }

    void reHeapDown(int pos) {
        int toReplace = left(pos);
        if (toReplace == -1)return;

        int rightNode = left(pos);
        if (rightNode != -1 && heap[rightNode] < heap[toReplace])
            toReplace = rightNode;
        swap(heap[pos], heap[toReplace]);
        reHeapUp(toReplace);
    }

public:
    void push(int num) {
        heap.push_back(num);
        reHeapUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty())return;
        swap(heap[0], heap.back());
        heap.pop_back();
        reHeapDown(0);
    }

    bool empty() {
        return heap.empty();
    }

    int top() {
        return heap.front();
    }
};

double calcRadius(int x, int y) {
    return x * x + y * y;
}

bool helpComparePair(const pair<double, int> &p1, const pair<double, int> &p2) {
    if (p1.first < p2.first)return true;
    if (p1.first > p2.first)return false;
    return p1.second > p2.second;
}

double mCities(int n, int m, vector<vector<int>> &cities) {
    vector<pair<double, int>> radiusPopulation(cities.size());
    for (int i = 0; i < cities.size(); ++i) {
        radiusPopulation[i] = {calcRadius(cities[i][0], cities[i][1]), cities[i][2]};
        //{radius,pop}
    }
    sort(radiusPopulation.begin(), radiusPopulation.end());
    long long sumPopulation = 0;
    for (int i = 0; i < radiusPopulation.size(); ++i) {
        sumPopulation += radiusPopulation[i].second;
        if (sumPopulation >= m)return sqrt(radiusPopulation[i].first);
    }
    return -1;
}

void suffixArray() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {{s[i], s[i + (1 << k) % n]}, i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " " << s.substr(i, n - p[i]) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            res ^= a;
        }
        if (n & 1) {
            cout << res << endl;
        } else {
            if (res != 0)cout << -1 << endl;
            else cout << res << endl;
        }
    }
    return 0;
}