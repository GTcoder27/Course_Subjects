/* GTCoder */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e9 + 7;

 

 
void solve(){
	int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    ll ans = 0;
    int prev = 0;
    
    for (int i = 0; i < m; ++i) {
        ans += abs(pref[b[i]] - pref[prev]);
        prev = b[i];
    }

    ans += pref[n] - pref[prev];

    cout << ans << "\n";



    

    
	
	

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}