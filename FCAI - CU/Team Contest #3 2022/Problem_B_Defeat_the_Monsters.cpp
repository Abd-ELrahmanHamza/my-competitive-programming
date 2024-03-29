
#include <bits/stdc++.h>

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
int n, m;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node, int parent, int &cnt, bool &cycle) {
    cnt++;
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); ++i) {
        int child = adj[node][i];
        if (parent != child && visited[child])
            cycle = true;
        else if (child != parent)
            dfs(child, node, cnt, cycle);
    }
}

int solve() {
    int remove = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bool cycle = false;
            int cnt = 0;
            dfs(i, -1, cnt, cycle);
            if (cycle) {
//                cout << "Cycle\n";
                remove += cnt % 2;
            }
        }
    }
    remove += (n - remove) % 2;
    return remove;
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
        vi v(n);
        unordered_map<int, int> primes;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            auto s = prime_factors_set(x);
            for (int y: s) {
                primes[y]++;
            }
        }
        ll r = 0;
        for (auto p: primes) {
            r += ceil(p.second / 3.0);
        }
        cout<<r<<endl;
    }
    return 0;
}