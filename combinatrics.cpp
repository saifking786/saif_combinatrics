#include<bits/stdc++.h>
using namespace std;

// Code Shortner
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define len(s) (int)s.size()
#define print(x) cout<<x<<'\n'
#define REP(i,a,b) for( int i = a; i <= b; i++)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define fast ios_base:: sync_with_stdio(0) ;cin.tie(0);cout.tie(0);
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MOD = 1e9 + 7;
const int N = 1e6;
 
int mod(int a, int m = MOD) {
    return a % m;
}
 
template <class T> class Math {
  public:
    vector<T> fact, invfact;
    Math() {}
    Math(int n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = mod(i * fact[i - 1]);
            invfact[i] = modinv(fact[i]);
        }
    }
    T modinv(T x, T m = MOD) { return expo(x, m - 2, m); }
    T expo(T base, T exp, T m = MOD) {
        T res = 1;
        while (exp) {
            if (exp & 1)
                res = mod(res * base, m);
            base = mod(base * base, m);
            exp >>= 1;
        }
        return res;
    }
    T choose(T n, T k) {
        if (k < 0 || k > n)
            return 0;
        T ans = fact[n];
        ans = mod(ans * invfact[n - k]);
        ans = mod(ans * invfact[k]);
        return ans;
    }
};