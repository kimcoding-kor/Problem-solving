#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
//#include <map>
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
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		string s;
		vector <pair<int, int>> v;
		pair <int, int> now;
		for (int i = 1, a, b; i <= n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(all(v));
		int flag = 0;
		for (auto i : v) {
			flag = 0;
			while (now.first < i.first) {
				now.first++;
				s += 'R';
			}
			while (now.second < i.second) {
				now.second++;
				s += 'U';
			}
			if ((now.first == i.first) && (now.second == i.second)) flag = 1;
			if (!flag) break;
		} 
		if (flag) cout << "YES\n" << s << '\n';
		else cout << "NO\n";
	}
	return 0;
}