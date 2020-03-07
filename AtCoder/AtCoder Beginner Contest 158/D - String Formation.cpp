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
using namespace std;

int main() {
	FIO;
	string s; cin >> s;
	deque <char> dq;
	for (auto i : s) dq.eb(i);
	int m = 0;
	int t; cin >> t; while (t--) {
		int a; cin >> a;
		if (a == 1) m ^= 1;
		else {
			int b; char c;
			cin >> b >> c;
			if ((!m && b == 1) || (m && b == 2)) dq.emplace_front(c);
			else dq.eb(c);
		}
	}
	while (dq.size()) {
		cout << (m ? dq.back() : dq.front());
		if (m) dq.pop_back();
		else dq.pop_front();
	}
	return 0;
}
