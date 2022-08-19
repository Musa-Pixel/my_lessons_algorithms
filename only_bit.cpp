#include <bits/stdc++.h>
/* @author torium, (musapixel) */
using namespace std;
typedef int i32;
typedef long long ll;
typedef __int128_t i28;
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
typedef double f64;
typedef long double f80;
typedef pair<i32, i32> p2;
typedef pair<i32, pair<i32, i32>> p3;
#define DEBUG
#ifdef DEBUG
	#define debug(x) cout << (#x) << "=" << (x) << endl
#else
	#define debug(x)
#endif
#define print(x) { cout << (#x) << endl; }
#define endl '\n'
void printbit2(i32 nm, i32 n) {
	for (i32 j = 1 << (n - 1); j >= 1; j >>= 1) {
		if ((nm & j) == 0) {
			cout << 0;
		}
		else {
			cout << 1;
		}
	}
	cout << endl;
}
// https://cses.fi/problemset/task/2205
void solve() {
	i32 n;
	cin >> n;

	vector<i32> a((1 << n) + 100);
	for (i32 i = 0; i < n; i++) {
		i32 start = 1 << (n - i - 1);
		i32 add = (1 << (n - i + 1));
		for (i32 j = start; j < (1 << n); j += add) {
			for (i32 k = j; k < min(j + (add >> 1), 1 << n); k++) {
				a[k] |= (1 << (n - 1 - i));
			}
		}
	}

	i32 sz = 1 << n;
	for (i32 i = 0; i < sz; i++) {
		printbit2(a[i], n);
	}
}

void optimization() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
}

int main() {
	optimization();
    cout << fixed;
    cout.precision(11);
    solve();
    return 0;
}
