#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Extended Euclidian Algorithm for Finding Bézout's Coefficients in O(log a) */

pair <ll, ll> xgcd(ll a, ll b) {
    if (!b) { return {1, 0}; }
    pair <ll, ll> temp = xgcd(b, a % b);
    return {temp.second, temp.first - temp.second * (a / b)};
}

/* Finds n where an ≡ 1 (mod m), if a and m are relatively prime based in the
   fact that an + km = 1, since a and m are relatively primes, then an = 1 - km. */

ll mod_inv(ll a, ll m) {
    return (xgcd(a, m).first % m + m) % m;
}

/* n ^ k mod m in O(log_2(k)) */

ll mod_pow(ll n, ll k, ll m = LLONG_MAX) {
    ll sol = 1;
    while (k) {
        if (k & 1) { sol = (sol * n) % m; }
        n = (n * n) % m;
        k >>= 1;
    }
    return sol;
}

/* Find factorial of all numbers between [0 and n) mod p */

vector <ll> facts(ll n, ll p) {
    vector <ll> f = {1};
    for (int i = 1; i < n; ++i) {
        f.push_back((f[i - 1] * i) % p);
    }
    return f;
}

/* Chinese Remainder Theorem states that if we have a system of congruences
   in the form of: x ≡ a1 (mod m1), x ≡ a2 (mod m2), ..., x ≡ an (mod mn) where
   mi is relatively prime with mj for all i != j then, the solution of the system
   can be found uniquely modulo Π mi.

   Here it works in O(n log(Π mi)) */

ll chinese_remainder_theorem(vector <pair <ll, ll> > &eq) {
    ll m = 1;
    for (pair <ll, ll> &e : eq) {
        m *= e.second;
    }
    ll x = 0;
    for (pair <ll, ll> &e : eq) {
        ll p = m / e.second;
        x += e.first * p * mod_inv(p, e.second);
        x %= m;
    }
    return x;
}

/* Pascal Triangle with Dynamic Programming O(n ^ r)
   1
   1 1
   1 2 1
   1 3 3 1
   1 4 6 4 1 */

vector <vector <ll> > comb;

void pascal_triangle(ll n, ll r, ll m) {
    comb = vector <vector <ll> >(n, vector <ll> (r));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == 0 or j == 0) {
                comb[i][j] = 1;
            } else {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                comb[i][j] %= m;
            }
        }
    }
}

/* Lucas Theorem states that if m is a prime number then
   nCr(n, r) mod m ≡ Π nCr(ni, ri) mod m where ni and ri are
   the correspondent digits of n and r in base m, respectively.

   Here it works in O(m ^ 2 log_p(r))*/

vector <ll> convert(ll n, ll b) {
    vector <ll> sol;
    while (n) {
        sol.push_back(n % b);
        n /= b;
    }
    return sol;
}

ll lucas_theorem(ll n, ll r, ll m) {
    vector <ll> ns = convert(n, m);
    vector <ll> rs = convert(r, m);
    if (ns.size() < rs.size()) {
        return 0;
    }
    ll x = 1;
    pascal_triangle(m, m, m);
    for (int i = 0; i < rs.size(); ++i) {
        x *= comb[ns[i]][rs[i]];
        x %= m;
    }
    return x;
}

/* Wilson's Theorem for finding n! mod p */

ll fact(ll n, ll p, ll m) {
    if (n <= 1) { return 1; }
    vector <ll> f = facts(m, m);
    if (n < m) {
        return (f[n] * fact(n / p, p, m)) % m;
    } else {
        ll a = f[m - 1];
        ll b = f[n % m];
        ll c = fact(n / p, p, m);
        return (mod_pow(a, n / m, m) * ((b * c) % m)) % m;
    }
}
