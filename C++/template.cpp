/* Shubhodip Pal*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include<ext/pd_ds/tree_policy.hpp>
#define ll long long int
const ll N = 998244353;
const ll M = 1e9 + 7;
const ll NN = 1e6 + 7;
const int p = 31;
#define f(a, b, c) for (int a = b; a < c; a++)
#define rf(a, b, c) for (int a = b; a >= c; a--)
#define vl vector<ll>
#define vs vector<string>
#define vpp vector<pair<ll, ll>>
#define pll pair<ll, ll>
#define vll vector<pll>
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define pb push_back
#define ltransfr(str) transform(str.begin(), str.end(), str.begin(), ::tolower)
#define utransfr(str) transform(str.begin(), str.end(), str.begin(), ::toupper)
#define PI 3.1415926535897932384626433832795
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define R return
#define C continue
#define bpc(x) __builtin_popcountll(x)
// vector<ll>factorial(1e6+1);
const ll INF = 0xFFFFFFFFFFFFFFFLL;

using namespace std;
using namespace __gnu_pbds;



ll mul(ll a, ll b, ll m = mod){
    return ((a % m) * (b % m)) % m;
}

ll modexp(ll a, ll e, ll m = mod){
	a %= m;
	ll r = 1;
	while(e){
	    if (e & 1) r = mul(r, a, m); 
	    a = mul(a, a, m);          
	    e >>= 1;              
	}
	return r;
}

// Modular inverse using Fermat's little theorem (mod is prime)
ll inv(ll a, ll m = mod){ 
    return modexp(a, m - 2, m); 
}





ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    ll res = a * (b / g);
    return res;
}
ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

ll mod_inv(ll a, ll m = M)
{
    a = a % m;
    return binExp(a, m - 2, m);
} // only for prime m
ll mod_add(ll a, ll b, ll m = M)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m = M)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m = M)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m = M)
{
    a = a % m;
    ll binv = mod_inv(b, m);
    return (((a * binv) % m) + m) % m;
}
// ll facto(ll n , ll m=N){ ll ans=1;  while(n) { ans*=n ; n--; ans%=m; } return ans;}
// ll facto(){factorial[1]=1;for(ll i=2;i<1e6+1;i++) {factorial[i]=(factorial[i-1]*i)%N;}}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order , order_of_key
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> order_set;

//DSU
int dsu[200000+1];
int siz[200000+1];
void create_set(int x) 
{
    dsu[x] = x;
    siz[x] = 1;
}
int find_root(int x) 
{
     if (x == dsu[x])
        return x;
     dsu[x] = find_root(dsu[x]);
     return dsu[x];
}
void union_set(int u, int v , bool &f) 
{
    int a = find_root(u);
    int b = find_root(v);
    if (a != b) 
    {   f=1;
        if (siz[a] < siz[b])
            swap(a, b);
        dsu[b] = a;
        siz[a] += siz[b];
    }
}
void initialize_dsu(int n)
{
	for(int i=1;i<=n;i++)
		create_set(i);
}

bool prime(int a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void dfs(int node, vector<int> adj[], int vis[], vector<int> &v)
{
    vis[node] = 1;
    v.pb(node);
    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            dfs(x, adj, vis, v);
        }
    }
}
set<ll> pr_factors;
void sieve(int n)
{
    bool prime[n + 1];
    for (int i = 0; i < n; i++)
    {
        prime[i] = true;
    }
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            pr_factors.insert(p);
}
bool isPalindrome(string s, int i)
{
    if (i > s.size() / 2)
    {
        return true;
    }
    return s[i] == s[s.size() - i - 1] && isPalindrome(s, i + 1);
}
bool comp(pair<ll,ll> a, pair<ll,ll> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
ll mod(ll a)
{
    if (a >= 0)
    {
        return a % N;
    }
    else
    {
        ll d = abs(a) / N;
        return (N * (d + 1) + a) % N;
    }
}
vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}
//trie
struct Trie{
    Trie* arr[26];
    bool flag=false;
    bool isPresent(char c, Trie* temp){
        return temp->arr[c-'a'] != NULL;
    }
};

string prefix_palindrom(string &s){
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    ll c = 0;
    vector<ll>pref(a.size(),0);
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}
const int N = 1e5+10;
int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]); // Path compression 
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]){  // Union by size
            swap(a,b);
        }
        parent[b] = a; 
        size[a] += size[b];
    }
}
ll powm(ll a,ll n){
    ll res = 1;
    a = a%mod;
    while(n > 0){
        if(n & 1) res = (res * a)%mod;
        a = (a*a)%mod;
        n = n >> 1;
    }
    return res;
}

ll power(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
ll modInverse(ll n) {
    return power(n, mod - 2);
}


// -------------------------<RANDOM NUMBER GENERATOR>-------------------------
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);

void solve(){

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t = 1;
    // cin >> t;
    ll a = 1;
    while (t--)
    {   
        solve();
    }
    return 0;
}

void factors(int n, vector<int> &ans) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 1) ans.push_back(n);
}


