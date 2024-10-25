
    fast;
    ll n;
    cin >> n;
    ll answer = 0;
    Math<int> m(N);  // Use larger N to prevent out-of-bound access
    for (int i = 0; i <= n - 1; i++) {
        answer = (answer + 2 * m.choose(i+n-1, i)) % MOD;
    }
    cout << (answer - n+MOD) % MOD << endl;
    return 0;
}
