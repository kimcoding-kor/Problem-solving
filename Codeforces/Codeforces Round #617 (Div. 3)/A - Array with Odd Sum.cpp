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
 
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int test; cin >> test; while (test--) {
		int n; cin >> n;
		int o = 0, e = 0;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			x & 1 ? o++ : e++;
		}
		if (o >= 1 && !e && o & 1) cout << "YES\n";
		else if (o >= 1 && e) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}