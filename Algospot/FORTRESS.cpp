#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef struct p { int x, y, r; }p;
typedef struct d { int ver, dist; }d;

#define dist(a,b,c,d) (a-c) * (a-c) + (b-d) * (b-d)

bool cmp(p t, p u) {
	return t.r < u.r;
}

vvi tree;
vector <p> v;
vi visit;

d dfs(int now, int level, d ans) {
	if (level > ans.dist) {
		ans.dist = level;
		ans.ver = now;
	}
	visit[now] = 1;
	for (auto& next : tree[now]) {
		if (visit[next]) continue;
		ans = dfs(next, level + 1, ans);
	}
	return ans;
}

int main() {
	int test; scanf("%d", &test); while (test--) {
		int n; scanf("%d", &n);
		v.assign(n + 1, p{ 0,0,0 });
		visit.assign(n + 1, 0);
		tree.resize(n + 1);
		for (int i = 1; i <= n; i++)
			scanf("%d %d %d", &v[i].x, &v[i].y, &v[i].r);
		sort(v.begin() + 1, v.end(), cmp);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if (dist(v[i].x, v[i].y, v[j].x, v[j].y) < v[j].r * v[j].r) {
					tree[j].push_back(i);
					tree[i].push_back(j);
					break;
				}
			}
		d temp = dfs(1, 0, d{ 0,0 });
		visit.assign(n + 1, 0);
		printf("%d\n",dfs(temp.ver, 0, d{ 0,0 }).dist);
		tree.clear();
	}
	return 0;
}