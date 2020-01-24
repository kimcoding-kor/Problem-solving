#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector <int> check(10);

void dfs(int level, int here, vector <pair<int,int>> &v) {
	if (n / 2 == level) {
		ans++;
		return;
	}
	for (int i = here; i < m; i++) {
		if (check[v[i].first] || check[v[i].second]) continue;
		check[v[i].first] = check[v[i].second] = 1;
		dfs(level + 1, i + 1, v);
		check[v[i].first] = check[v[i].second] = 0;
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &n, &m);
		vector <pair<int, int>> v;
		for (int i = 1,a,b; i <= m; i++) {
			scanf("%d %d", &a, &b);
			v.push_back({ a,b });
		}
		ans = 0;
		dfs(0, 0, v);
		printf("%d\n", ans);
	}
	return 0;
}