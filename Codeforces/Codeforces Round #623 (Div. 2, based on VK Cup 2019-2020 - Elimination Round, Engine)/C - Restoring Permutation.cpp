#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		bool chk[205] = {};
		vi ans, arr(n + 1);
		for (int i = 1; i <= n; i++) cin >> arr[i], chk[arr[i]] = 1;
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			flag = 0;
			for (int j = arr[i] + 1; j <= 2 * n; j++) {
				if (chk[j]) continue;
				flag = 1;
				chk[j] = 1;
				ans.eb(arr[i]); ans.eb(j);
				break;
			}
			if (!flag) break;
		}
		if (!flag) {
			cout << -1 << '\n';
			continue;
		}
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}