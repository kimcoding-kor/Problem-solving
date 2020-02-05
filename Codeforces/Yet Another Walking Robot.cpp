#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define all(x) (x).begin(), (x).end()
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;
typedef pair <int, int> pii;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int test; cin >> test; while (test--) {
		int n; cin >> n;
		int r = 0, c = 0;
		map <pii, int> m;
		m[{r, c}] = 1;
		int Min = 1e9, ans1 = -1, ans2 = -1;
		for (int i = 1; i <= n; i++) {
			char ch; cin >> ch;
			if (ch == 'L') c--;
			if (ch == 'R') c++;
			if (ch == 'U') r++;
			if (ch == 'D') r--;
			auto it = m.find({ r,c });
			if (it != m.end()) {
				if (Min > i - it->second ) {
					Min = i - it->second;
					ans1 = it->second, ans2 = i;
				}
			}
			m[{r, c}] = i + 1;
		}
		if (ans1 == -1) cout << "-1\n";
		else cout << ans1 << ' ' << ans2 << '\n';
	}
	return 0;
}
