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

const i32 N = 1e5;
const i32 logN = log2(N);
i32 n;
i32 up[N][logN];
vector<i32> g[N];

void dfs(i32 v) {
	for (i32 l = 1; l < logN; l++) {
		up[v][l] = up[up[v][l - 1]][l - 1];
	}
	for (i32 u : g[v]) {
		up[u][0] = v;
		dfs(u);
	}
}

i32 kth_ancestor(i32 v, i32 k) {
	for (i32 i = 0; i < logN; i++) {
		if (k & (1 << i)) {
			v = up[v][i];
			cout << i << endl;
			if (v == 0) {
				return 1;
			}
		}
	}
	return v;
}

void solve() {
	cin >> n;

	for (i32 i = 2; i <= n; i++) {
		i32 x;
		cin >> x;
		g[x].push_back(i);
	}

	dfs(1);
	for (i32 i = 1; i <= n; i++) {
		for (i32 j = 0; j < logN; j++) {
			cout << up[i][j] << " ";
		}
		cout << endl;
	}
	cout << kth_ancestor(10, 8) << endl;
}

void optimization() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

i32 main() {
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	optimization();
	cout.precision(11);
	solve();
	cout << endl;
	return 0;
}
