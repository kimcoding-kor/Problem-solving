#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ll long long
#define fs first
#define sd second
#define eb emplace_back
using namespace std;
 
char ctoi(char x) {
	return x - 'a';
}
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		vvi adj(26);
		vi visit(26);
		string s; cin >> s;
		int check[26][26] = {};
		for (int i = 0; i < s.size() - 1; i++) {
			if(!check[ctoi(s[i])][ctoi(s[i + 1])])
				adj[ctoi(s[i])].eb(ctoi(s[i + 1]));
			check[ctoi(s[i])][ctoi(s[i + 1])] = 1;
			if(!check[ctoi(s[i + 1])][ctoi(s[i])])
				adj[ctoi(s[i + 1])].eb(ctoi(s[i]));
			check[ctoi(s[i + 1])][ctoi(s[i])] = 1;
		}
		vi ans;
		int start = 0;
		function <bool(int, int)> dfs = [&](int now, int par) {
			int child = 0;
			visit[now] = 1;
			for (int next : adj[now]) {
				child++;
				if (par == next) continue;
				if (visit[next]) return 0;
				if (!dfs(next, now)) return 0;
			}
			if (child > 2) return 0;
			if (child == 1) start = now;
			return 1;
		};
		function <void(int, int)> dfs2 = [&](int now, int par) {
			ans.eb(now);
			visit[now] = 1;
			for (int next : adj[now]) {
				if (next == par) continue;
				dfs2(next, now);
			}
		};
		int flag = 1;
		for (int i = 0; i < 26; i++)
			if (!visit[i] && !dfs(i, -1)) flag = 0;
		visit = vi(26, 0);
		if (flag) {
			dfs2(start, -1);
			cout << "YES\n";
			for (int i : ans) cout << (char)(i + 'a');
			for (int i = 0; i < 26; i++) if (!visit[i]) cout << (char)(i + 'a');
			cout << '\n';
		}
		else cout << "NO\n";
	}
	return 0;
}