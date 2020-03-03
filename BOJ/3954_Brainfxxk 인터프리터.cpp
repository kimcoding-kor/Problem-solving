#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		string a, b;
		cin >> a >> b;
		int idx[4100], arr[100005] = {};
		stack <int> st;
		FOR(i, 0, m - 1) {
			if (a[i] == '[') st.push(i);
			if (a[i] == ']') {
				idx[i] = st.top();
				idx[st.top()] = i;
				st.pop();
			}
		}
		int p = 0, c = 0, cnt = 0, chk = -1;
		FOR(i, 0, m - 1) {
			if (a[i] == '-') arr[p] = (arr[p] + 255) % 256;
			if (a[i] == '+') arr[p] = (arr[p] + 1) % 256;
			if (a[i] == '<') p = (p - 1 + n) % n;
			if (a[i] == '>') p = (p + 1) % n;
			if (a[i] == '[' && !arr[p]) i = idx[i];
			if (a[i] == ']' && arr[p]) chk = max(chk, i), i = idx[i];
			if (a[i] == ',') arr[p] = (c == k ? 255 : (int)b[c++]);
			if (++cnt == 50000000) {
				cout << "Loops " << idx[chk] << ' ' << chk << '\n';
				break;
			}
		}
		if(cnt < 50000000) cout << "Terminates\n";
	}
	return 0;
}