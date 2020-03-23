#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define vi vector <int>
#define all(x) (x).begin(), (x).end()
#define ep emplace
#define eb emplace_back
using namespace std;

struct Edge {
	int a, b, w;
	bool operator<(const Edge& u) const {
		return w < u.w;
	}
};

struct UF {
	int* arr, * sz;
	UF(int n) {
		arr = new int[n + 1];
		sz = new int[n + 1];
		FOR(i, 0, n) arr[i] = i, sz[i] = 1;
	}
	int find(int x) {
		return (arr[x] == x) ? x : x = find(arr[x]);
	}
	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (sz[a] > sz[b]) swap(a, b);
		arr[a] = b, sz[b] += sz[a];
	}
	~UF() {
		delete[] arr, delete[] sz;
	}
};

int main() {
	FIO;
	int n, m, k; cin >> n >> m >> k;
	vector <Edge> v;
	FOR(i, 0, m - 1) {
		int a, b, w; cin >> a >> b >> w;
		v.eb(Edge{ a,b,w });
	}
	sort(all(v));
	UF uf(n);
	int ans = 0;
	FOR(i, 0, m - 1) {
		int a = v[i].a, b = v[i].b;
		if (uf.find(a) == uf.find(b)) continue;
		uf.merge(a, b);
		ans += v[i].w;
	}
	FOR(i, 1, n - 2) ans += i * k;
	cout << ans << '\n';
	return 0;
}