/* @author torium, (musapixel) */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int i32;
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
typedef long double f64;
typedef pair<i32, i32> pii;
#define debug(x) cout << (#x) << "=" << (x) << endl
#define endl '\n'
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define fi first
#define se second

vector<pair<i32, i32>> g[110];
i32 d[110];

void solve()
{
	i32 n, m, st, en;
	cin >> n >> m >> st >> en;

	for (i32 i = 0; i < m; i++)
	{
		i32 x, y, w;
		cin >> x >> y >> w;
		g[x].push_back({y, w});
	}

	fill(begin(d), end(d), INT_MAX);

	set<pair<i32, i32>> s;
	s.insert({0, st});
	d[st] = 0;

	while (!s.empty())
	{
		i32 v = (*s.begin()).second;
		s.erase(s.begin());

		for (auto &it : g[v])
		{
			i32 to = it.first, w = it.second;

			if (d[to] > d[v] + w)
			{
				s.erase({d[to], to});
				d[to] = d[v] + w;
				s.insert({d[to], to});
			}
		}
	}
	if (d[en] == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << d[en] << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// cout.precision();
	solve();
	return 0;
}
