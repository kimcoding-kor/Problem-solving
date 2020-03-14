#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define vvl vector <vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
#define mod 998244353
using namespace std;

int main() {
	FIO;
	int t; cin  t; while (t--) {
		string s;
		cin  s;
		int ans = 0;
		int pre = -1;
		FOR(i,0,(int)s.size()-1) {
			if (s[i] == 'R') {
				ans = max(ans, i - pre);
				pre = i;
			}
		}
		ans = max(ans, (int)s.size() - pre);
		cout  ans  'n';
	}
	return 0;
}