#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <string> vs;
typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

#define pb(x) push_back(x)

vvi can_eat, food;
int ans, n, m;

void dfs(ll visit, int cnt) {
	if (ans <= cnt) return;
	int idx = 1;
	while (idx <= n && visit & (1<<idx)) idx++;
	if (idx == n + 1) {
		ans = cnt;
		return;
	}
	for (auto& now : can_eat[idx]) {
		ll sum = 0;
		for (auto& foodnow : food[now]) sum += (1 << foodnow);
			dfs(visit | sum, cnt + 1);
	}
}

int main() {
	int test; scanf("%d", &test); while (test--) {
		scanf("%d %d", &n, &m);
		ans = 1e9;
		vs name(n + 1);
		can_eat.resize(n + 1);
		food.resize(m + 1);
		for (int i = 1; i <= n; i++) {
			char arr[15];
			scanf("%s", arr);
			name[i] = arr;
		}
		for (int i = 1,x; i <= m; i++) {
			scanf("%d", &x);
			while (x--) {
				char arr[15];
				scanf("%s", arr);
				for (int j = 1; j <= n; j++)
					if (name[j] == arr) {
						can_eat[j].pb(i);
						food[i].pb(j);
					}
			}
		}
		dfs(0, 0);
		printf("%d\n", ans);
		can_eat.clear();
		food.clear();
	}
	return 0;
}