#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <pii> vp;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		int n, m; cin >> n >> m;
		vp v;
		for (int i = 1, a, b; i <= m; i++) {
			cin >> a >> b;
			v.push_back({ b, a });
		}
		sort(v.begin(), v.end());
		int ans = 0;
		vi visit(n + 1);
		for (int i = 0; i < m; i++){
			for (int j = v[i].second; j <= v[i].first; j++)
				if (!visit[j]) {
					visit[j] = 1, ans++;
					break;
				}
		}
		cout << ans << '\n';
	}
	return 0;
}