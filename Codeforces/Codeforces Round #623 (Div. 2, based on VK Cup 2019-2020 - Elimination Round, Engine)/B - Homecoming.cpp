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
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int a, b, p;
		cin >> a >> b >> p;
		string s; cin >> s;
		int i = (int)s.size() - 2;
		for (;i >= 0;) {
			if (s[i] == 'A' && p < a) break;
			else if (s[i] == 'A' && p >= a) p -= a;
			if (s[i] == 'B' && p < b) break;
			else if (s[i] == 'B' && p >= b) p -= b;
			while (i && s[i] == s[i - 1]) i--;
			i--;
		}
		//if (i == (int)s.size() - 1) i--;
		cout << i + 2 << '\n';
	}
	return 0;
}