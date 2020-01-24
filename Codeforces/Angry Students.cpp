#include <cstdio>
#include <iostream>
#include <string>
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
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		string x = s;
		int ans = 0;
		while (1) {
			int cnt = 0;
			for (int i = 1; i < n; i++) {
				if (s[i - 1] == 'A' && x[i] == 'P') {
					x[i] = 'A';
					cnt++;
				}
			}
			if (!cnt) break;
			ans++;
			s = x;
		}
		cout << ans << '\n';
	}
	return 0;
}