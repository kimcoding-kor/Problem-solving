#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define all(x) (x).begin(), (x).end()
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;
typedef vector <ll> vl;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int test; cin >> test; while (test--) {
		int n; cin >> n;
		vl v = vl(n + 1);
		vl sum = vl(n + 1);
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			sum[i] = v[i] + sum[i - 1];
			if (i < n && sum[i] <= 0) flag = 1;
		}
		map <ll, int> m;
		m[0] = 1;
		ll temp = 0;
		for (int i = 2; i < n; i++) {
			temp += v[n - i + 2];
			if (temp <= 0) {
				flag = 1;
				break;
			}
			m[temp] = 1;
			auto it = m.upper_bound(-sum[n - i]);
			if (m.begin() == it) continue;
			flag = 1;
			break;
		}
		if (temp + v[2] <= 0) flag = 1;
		if (sum[n] < v[1] || sum[n] < v[n]) flag = 1;
		if (flag) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
	}
	return 0;
}