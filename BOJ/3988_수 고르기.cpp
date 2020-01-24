#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	sort(v.begin() + 1, v.end());
	map <int, int> m;
	for (int i = 1; i <= n - k - 1; i++)
		m[v[i + 1] - v[i]]++;
	int ans = v[n - k] - v[1] + m.begin()->first;
	for (int i = 1; i <= k; i++) {
		int s = i, e = i + n - k - 1;
		if (!(--m[v[s + 1] - v[s]]))
			m.erase(v[s + 1] - v[s]);
		m[v[e + 1] - v[e]]++;
		int Min = m.begin()->first;
		ans = min(ans, Min + v[e + 1] - v[s + 1]);
	}
	printf("%d\n", ans);
	return 0;
}