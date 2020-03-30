#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define mod (int)1e9
using namespace std;

struct Edge {
	int a, b, w;
	bool operator< (const Edge& t)const {
		return w < t.w;
	}
};

struct UF {
	int* v, * sz;
	UF(int n) {
		v = new int[n + 1];
		sz = new int[n + 1];
		FOR(i, 1, n) v[i] = i, sz[i] = 1;
	}
	int find(int x) {
		return v[x] == x ? x : x = find(v[x]);
	}
	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (sz[x] > sz[y]) swap(x, y);
		v[x] = y, sz[y] += sz[x];
	}
	~UF() {
		delete[] v, delete[] sz;
	}
};

int main() {
	FIO;
	int n, m; cin >> n >> m;
	Edge* e = new Edge[m];
	int sum = 0, ans = 0;
	FOR(i, 0, m - 1) {
		int x, y, w; cin >> x >> y >> w;
		e[i] = Edge{ x,y,w };
		sum = (sum + w) % mod;
	}
	sort(e, e + m);
	UF uf(n);
	RFOR(i, m - 1, 0) {
		int x = uf.find(e[i].a);
		int y = uf.find(e[i].b);
		if (x != y) {
			ans = (ans + 1ll * sum * uf.sz[x] * uf.sz[y]) % mod;
			uf.merge(x, y);
		}
		sum = (sum - e[i].w + mod) % mod;
	}
	cout << ans << '\n';
	return 0;
}