/* @author torium, (musapixel) */
#include <bits/stdc++.h>	
using namespace std;

typedef long long ll;
typedef int i32;
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
typedef long double f64;
#define debug(x) cout << (#x) << "=" << (x) << endl
#define endl '\n'
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define fi first
#define se second

vector<i32> factorization(i32 n) {
	vector<i32> p;

	while (n % 2 == 0) {
		p.pub(2);
		n /= 2;
	}
	i32 d = 3;
	while (d * d <= n) {
		if (n % d == 0) {
			p.pub(d);
		}
		else {
			d += 2;
		}
	}

	if (n > 1) {
		p.pub(n);
	}
	return p;
}

void solve() {
	i32 n;
	cin >> n;

	for (auto &i : factorization(n)) {
		cout << i << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// cout.precision();
	solve();
	return 0;
}
