#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct p { int a, b; }p;

int w, n;
vector <int> v;
vector <vector <p>> pr(400005);

int main() {
	scanf("%d %d", &w, &n);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pr[v[i] + v[j]].push_back(p{ i,j });
			if (w - v[i] - v[j] < 0 || w - v[i] - v[j] > 400000) continue;
			for (auto& now : pr[w - v[i] - v[j]]) {
				if (now.a == i || now.b == j || now.a == j || now.b == i) continue;
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}