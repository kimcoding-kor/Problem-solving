#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 10000000
using namespace std;

int main() {
	FIO;
	bool prime[MAX];
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;
	for (int i = 2; i * 2 < MAX; i++)
		prime[i * 2] = 0;
	for (int i = 3; i * i < MAX; i += 2) {
		if (!prime[i]) continue;
		for (int j = i * 2; j < MAX; j += i) prime[j] = 0;
	}

	int t; cin >> t; while (t--) {
		string s; cin >> s;
		bool visit[10] = {};
		int arr[10], len = s.size(), ans = 0;
		for (int i = 0; i < len; i++)
			arr[i] = s[i] - '0';
		map <int, int> m;
		sort(arr, arr + len);
		do {
			int x = 0;
			for (int i = 0; i < len; i++) {
				x = 10 * x + arr[i];
				if (m.find(x) != m.end()) continue;
				m[x] = 1;
				if (prime[x]) ans++;
			}
		} while (next_permutation(arr, arr + len));
		cout << ans << '\n';
	}
	return 0;
}