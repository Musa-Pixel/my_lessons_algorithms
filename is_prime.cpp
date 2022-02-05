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

set<i32> primes;

bool is_prime (i32 num) {
	for (i32 i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void solve() {
	i32 n;
	cin >> n;

	i32 i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			if (is_prime(i)) {
				primes.insert(i);
			}
			if (is_prime(n / i)) {
				primes.insert(n / i);
			}
		}
		i++;
	}
	if (is_prime(n)) {
		primes.insert(n);
	}
	for (auto &i : primes) {
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
