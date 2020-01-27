#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int test; cin >> test; for(int k=1;k<=test;k++) {
		int n, m; cin >> n >> m;
		vector <int> cost = vector <int>(n + 1);
		vector <int> car = vector <int>(m + 1);
		vector <int> check = vector <int>(n + 1);
		queue <int> q;
		for (int i = 1; i <= n; i++) cin >> cost[i];
		for (int i = 1; i <= m; i++) cin >> car[i];
		int ans = 0;
		for (int i = 1; i <= 2 * m; i++) {
			int x; cin >> x;
			if (x > 0) q.push(x);
			for (int j = 1; j <= n; j++) {
				if (x < 0 && check[j] == -x) check[j] = 0;
			}
			for(int j=1;j<=n;j++)
				if (!check[j] && !q.empty()) {
					check[j] = q.front();
					ans += (car[q.front()] * cost[j]);
					q.pop();
				}
		}
		cout << '#'<<k<< ' ' <<ans << '\n';
	}
	return 0;
}