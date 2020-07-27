#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main() {
	FIO;
	map <string, int> m;
	int cnt = 0;
	string s;

	while (getline(cin,s)) {
		cnt++;
		m[s]++;
	}

	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << fixed;
		cout.precision(4);
		cout << it->first << ' ' << 100.0 * it->second / cnt << '\n';
	}
	return 0;
}