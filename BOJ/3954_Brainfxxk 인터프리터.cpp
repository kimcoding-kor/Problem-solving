#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define MAX 50000000
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
		int p = 0, c = 0, cnt = 0, chk = 1e9, flag = 0;
		FOR(i, 0, m - 1) {
			if (a[i] == '-') arr[p] = (arr[p] + 255) % 256;
			else if (a[i] == '+') arr[p] = (arr[p] + 1) % 256;
			else if (a[i] == '<') p = (p - 1 + n) % n;
			else if (a[i] == '>') p = (p + 1) % n;
			else if (a[i] == '[') {
				if (MAX <= cnt)
					chk = min(chk, i);
				if (MAX * 2 <= cnt)
					flag = 1;
				if (!arr[p]) i = idx[i] - 1;
			}
			else if (a[i] == ']' && arr[p]) i = idx[i] - 1;
			else if (a[i] == ',') arr[p] = (c == k ? 255 : (int)b[c++]);
			if (++cnt && flag) {
				cout << "Loops " << chk << ' ' << idx[chk] << '\n';
				break;
			}
		}
		if (!flag) cout << "Terminates\n";
	}
	return 0;
}