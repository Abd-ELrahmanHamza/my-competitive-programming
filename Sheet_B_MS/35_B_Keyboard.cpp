#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define rep(i, v) for(int i=0;i<v.size();++i)
#define readV(v) for(int i=0;i<v.size();++i)cin>>v[i];
#define printV(v) for(int i=0;i<v.size();++i)cout<<v[i]<<" ";
#define M_PI 3.14159265358979323846

struct Trie {
    Trie *child[26];
    bool isLeaf;

    Trie() {
        memset(child, 0, sizeof(child));
        isLeaf = false;
    }

    void insert(char *str) {
        if (*str == '\0')
            isLeaf = true;
        else {
            int cur = *str - 'a';
            if (child[cur] == 0) {
                child[cur] = new Trie();
            }
            child[cur]->insert(str + 1);
        }
    }

    bool wordExist(char *str) {
        if (*str == '\0')
            return isLeaf;

        int cur = *str - 'a';
        if (child[cur] == 0) {
            return false;
        }
        return child[cur]->wordExist(str + 1);
    }

    void prefixExist(char *str) {
        if (*str == '\0')
            isLeaf = true;
        else {
            int cur = *str - 'a';
            if (child[cur] == 0) {
                child[cur] = new Trie();
            }
            child[cur]->prefixExist(str + 1);
        }
    }
};

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


int Dijkstra(vector<vector<pair<ll, pair<ll, ll>>>> adjList, int src, int dest = -1)    // O(E logV)
{
    int n = adjList.size();
    vi dist(n, INT_MAX), prev(n, -1);
    dist[src] = 0;

    priority_queue<pair<ll, pair<ll, ll>>> q;
    q.push(make_pair(0, make_pair(-1, src)));

    while (!q.empty()) {
        pair<ll, pair<ll, ll>> e = q.top();
        q.pop();
        int w = e.first, from = e.second.first, to = e.second.second;
        if (w > dist[to]) continue;    // some other state reached better

        prev[to] = from;

        rep(j, adjList[to]) {
            pair<ll, pair<ll, ll>> ne = adjList[to][j];
            int neww = ne.first, nefrom = ne.second.first, neto = ne.second.second;

            if (dist[neto] > dist[nefrom] + neww) {
                neww = dist[neto] = dist[nefrom] + neww;
                q.push(ne);
            }
        }
    }

    return dist[dest] == INT_MAX ? -1 : dist[dest];
}

//ll n, m;
//vector<vector<char>> graph;
//vector<int> dx = {0, 0, 1, -1, 1, -1, 1, -1};
//vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};;
//vector<vector<bool>> visited;
//
//bool isValid(int i, int j) {
//    return i < n && i >= 0 && j < m && j >= 0;
//}
//
//void UVAWar(int i, int j) {
//    if (visited[i][j])return;
//    visited[i][j] = true;
//    for (int x: dx) {
//        for (int y: dy) {
//            if (!(x == 0 && y == 0) && isValid(i + x, j + y) && graph[i + x][j + y] == '1') {
//                UVAWar(i + x, j + y);
//            }
//        }
//    }
//}
//
//int connectedComponents() {
//    int cnt = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (!visited[i][j] && graph[i][j] == '1') {
//                UVAWar(i, j);
//                cnt++;
//            }
//        }
//    }
//    return cnt;
//}

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

ll countDigits(ll n) {
    ll numDigits = floor(log10(n)) + 1;
    ll totalNum = 0;
    for (int i = 1; i < numDigits; ++i) {
        totalNum += (int) (pow(10, i) - pow(10, i - 1)) * i;
    }
    totalNum += (n - (int) pow(10, numDigits - 1) + 1) * numDigits;
    return totalNum;
}

int compDouble(double a, double b) {
    if (fabs(a - b) <= 1e-10)return 0;
    return a < b ? -1 : 1;
}

bool comparePair(const pair<int, pair<int, string>> &p1, const pair<int, pair<int, string>> &p2) {
    if (p1.first > p2.first)return true;
    else if (p1.first < p2.first)return false;
    return p1.second.first < p2.second.first;
}

ull C(ull n, ull k) {
    ull r = 1;
    ull d;
    if (k > n) return 0;
    for (d = 1; d <= k; d++) {
        r *= n--;
        r /= d;
    }
    return r;
}


vi BFS(int s, vector<vector<int>> adj) {
    vi len(adj.size(), -1);
    queue<int> q;
    q.push(s), len[s] = 0;
    int dep = 0, cur = s, sz = 1;
    for (; !q.empty(); ++dep, sz = q.size()) {
        while (sz--) {
            cur = q.front();
            q.pop();
            for (int i = 0; i < adj[cur].size(); ++i) {
                if (len[adj[cur][i]] == -1) {
                    q.push(adj[cur][i]);
                    len[adj[cur][i]] = len[cur] + 1;
                }
            }
        }
    }
    return len;
}

// Initialize direction vectors
vi dH = {-1, 0, 0};
vi dRow = {0, 0, 1};
vi dCol = {0, 1, 0};

// Function to check if mat[row][col]
// is unvisited and lies within the
// boundary of the given matrix
bool isValid(vector<vector<vector<bool>>> vis, int h, int row, int col) {
    // If cell is out of bounds
    if (row < 0 || col < 0 || h < 0 || h >= vis.size() || row >= vis[0].size() || col >= vis[0][0].size())
        return false;

    // If the cell is already visited
    if (vis[h][row][col])
        return false;

    // Otherwise, it can be visited
    return true;
}

struct triple {
    int row;
    int col;
    int h;
};

// Function to perform DFS
// Traversal on the matrix grid[]
int DFSGrid(int row, int col, int h,
            vector<vector<vector<int>>> grid,
            vector<vector<vector<bool>>> vis) {
    int res = 0;
    // Initialize a stack of pairs and
    // push the starting cell into it
    stack<triple> st;
    st.push({row, col, h});

    // Iterate until the
    // stack is not empty
    while (!st.empty()) {
        // Pop the top pair
        triple curr = st.top();
//        cout << "h = " << curr.h << " row" << curr.row << " col" << curr.col << endl;
        st.pop();
        int row = curr.row;
        int col = curr.col;
        int h = curr.h;

        // Check if the current popped
        // cell is a valid cell or not
        if (!isValid(vis, h, row, col))
            continue;

        // Mark the current
        // cell as visited
        vis[h][row][col] = true;

        // Print the element at
        // the current top cell
        if (grid[h][row][col])
            cout << " h " << h << " row " << row << " col " << col << " " << grid[h][row][col] << "\n";
        res += grid[h][row][col];
        // Push all the adjacent cells
        for (int i = 0; i < 3; i++) {
            int adjx = row + dRow[i];
            int adjy = col + dCol[i];
            int adjz = h + dH[i];
            st.push({adjx, adjy, adjz});
        }
    }
    return res;
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

//int n, m, k;
//vector<pair<int, int>> burned;
//vector<vector<int>> forest;
//vector<vector<bool>> visited;
//vector<int> directionx = {0, 0, 1, -1};
//vector<int> directiony = {1, -1, 0, 0};
//queue<pair<int, int> > q;
//
//
//bool valid(int i, int j) {
//    return i < n && i >= 0 && j < m && j >= 0;
//}

//
//void BFS() {
//    while (!q.empty()) {
//
//        pair<int, int> cell = q.front();
//        int x = cell.first;
//        int y = cell.second;
////        cout << "Cur node = " << x << " " << y << endl;
//        q.pop();
//
//        for (int i = 0; i < 4; i++) {
//
//            int adjx = x + directionx[i];
//            int adjy = y + directiony[i];
//
//            if (valid(adjx, adjy) && !visited[adjx][adjy]) {
//                q.push({adjx, adjy});
////                cout << adjx << " " << adjy << endl;
//                visited[adjx][adjy] = true;
//                forest[adjx][adjy] = min(forest[adjx][adjy], forest[x][y] + 1);
//            }
//        }
//    }
//}
//int n, m;
//vector<vector<int>> adj;
//vector<bool> visited;

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



bool helpComp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first < p2.first)return true;
    else if (p1.first > p2.first)return false;
    return p1.second < p2.second;
}

int n, m, x;
vector<vector<char>> grid;
vector<vector<bool>> visited;
set<char> canReach;

bool isValid(int i, int j) {
    return i < n && i >= 0 && j < m && j >= 0;
}

bool eclideanDist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= x * x;
}

void dfs(int i, int j, int srcX, int srcY) {
    if (!isValid(i, j) || visited[i][j])return;

    visited[i][j] = true;
//    if (grid[i][j] == 'S')return;
    if (grid[i][j] != 'S') {
        if (eclideanDist(i, j, srcX, srcY)) {
            canReach.insert(grid[i][j]);
        } else return;
    }

    dfs(i + 1, j, srcX, srcY);
    dfs(i + 1, j + 1, srcX, srcY);
    dfs(i + 1, j - 1, srcX, srcY);
    dfs(i, j + 1, srcX, srcY);
    dfs(i, j - 1, srcX, srcY);
    dfs(i - 1, j, srcX, srcY);
    dfs(i - 1, j + 1, srcX, srcY);
    dfs(i - 1, j - 1, srcX, srcY);
}

int main() {
//    freopen("gcd.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> x;
    grid = vector<vector<char>>(n, vector<char>(m));
    vector<pair<int, int>> shifts;
    set<char> contain;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                shifts.push_back({i, j});
            else
                contain.insert(grid[i][j]);
        }
    }

    for (int i = 0; i < shifts.size(); ++i) {
        visited = vector<vector<bool>>(n, vector<bool>(m));
        dfs(shifts[i].first, shifts[i].second, shifts[i].first, shifts[i].second);
    }

    int q, cnt = 0;
    string s;
    cin >> q >> s;
    for (int i = 0; i < q; ++i) {
        if (contain.count((char) tolower(s[i])) == 0) {
            cout << -1;
            return 0;
        }
        if (isupper(s[i]) && canReach.count((char) tolower(s[i])) == 0) {
            if (shifts.empty()) {
                cout << -1;
                return 0;
            }
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
