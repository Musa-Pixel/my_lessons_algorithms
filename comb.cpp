/* @author torium, (musapixel) */
#include <bits/stdc++.h>	
using namespace std;

typedef int i32;
typedef long long i64;
typedef double f64;
typedef long double f80;
typedef pair<i32, i32> p2;
typedef pair<i32, p2> p3;
#define endl '\n'
#define DEBUG
#ifdef DEBUG
	#define debug(x) cout << (#x) << "=" << (x) << endl
#else
	#define debug(x)
#endif
#define print(x) cout << (#x) << endl;

const i32 N = 3e6 + 10;
const i32 MOD = 1e9 + 7;
i64 fact[N], rfact[N];

i64 binpow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b % 2 == 0) return binpow(a * a % MOD, b / 2);
	return binpow(a, b - 1) * a % MOD;
}

i64 C(i32 n, i32 m) {
	return fact[n] * rfact[m] % MOD * rfact[n - m] % MOD;
}

void init() {
	fact[0] = 1;
	for (i32 i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	rfact[N - 1] = binpow(fact[N - 1], MOD - 2);
	for (i32 i = N - 2; i >= 0; i--) {
		rfact[i] = rfact[i + 1] * (i + 1) % MOD;
	}
}

void solve() {
	init();
	cout << C(10, 5) << endl;
}

void optimization() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

i32 main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	optimization();
	cout.precision(11);
	solve();
	cout << endl;
	return 0;
}
