#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; // Example MOD value

// Function to calculate a % MOD
int mod(int a, int m = MOD) {
    return a % m;
}

// Template class for mathematical operations
template <class T>
class Math {
public:
    vector<T> fact, invfact; // Factorial and Inverse Factorial arrays

    // Constructor
    Math() {}

    // Constructor that initializes factorial and inverse factorial arrays up to n
    Math(int n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = mod(i * fact[i - 1]);
            invfact[i] = modinv(fact[i]);
        }
    }

    // Function to calculate modular inverse using Fermat's Little Theorem
    T modinv(T x, T m = MOD) {
        return expo(x, m - 2, m);
    }

    // Function to perform modular exponentiation
    T expo(T base, T exp, T m = MOD) {
        T res = 1;
        while (exp) {
            if (exp & 1) {
                res = mod(res * base, m);
            }
            base = mod(base * base, m);
            exp >>= 1;
        }
        return res;
    }

    // Function to calculate n choose k (nCk) modulo MOD
    T choose(T n, T k) {
        if (k < 0 || k > n) {
            return 0;
        }
        T ans = fact[n];
        ans = mod(ans * invfact[n - k]);
        ans = mod(ans * invfact[k]);
        return ans;
    }
};
