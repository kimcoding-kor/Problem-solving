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
	int n; cin >> n;
	vi Min, Max;
	ll ans = 0;
	FOR(i, 1, n) {
		int x, s;
		cin >> x;
		bool asc = false;
		int MIN = 1e9, MAX = -1;
		FOR(j, 1, x) {
			cin >> s;
			if (s > MIN) asc = true;
			MIN = min(MIN, s);
			MAX = max(MAX, s);
		}
		if (asc) ans += n;
		else Min.push_back(MIN), Max.push_back(MAX);
	}
	ans += 1LL * ((int)Min.size()) * (n - (int)Min.size());
	int j = 0;
	sort(all(Min)), sort(all(Max));
	FOR(i, 0, (int)Min.size() - 1) {
		while (j < (int)Min.size() && Max[j] <= Min[i]) j++;
		if (j == (int)Min.size()) break;
		ans += 1LL * ((int)Min.size() - j);
	}
	cout << ans << '\n';
	return 0;
}