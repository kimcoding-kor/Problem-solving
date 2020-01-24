#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int n;
vvi adj(26);
vi in(26,-1), visit(26);
string s[105];

bool order(string a, string b) {
	int len = min(a.length(), b.length());
	for (int i = 0; i < len; i++) {
		if (a[i] != b[i]) {
			adj[a[i] - 'a'].push_back(b[i] - 'a');
			in[b[i] - 'a']++;
			return 1;
		}
	}
	return a.length() <= b.length();
}

bool cycle(int now) {
	if (visit[now] == 1) return 1;
	if (visit[now] == -1) return 0;
	visit[now] = 1;
	for (auto i : adj[now])
		if (cycle(i)) return 1;
	visit[now] = -1;
	return 0;
}

string bfs() {
	for (int i = 0; i < 26; i++)
		if (cycle(i)) 
			return "!";
	int st = -1;
	for (int i = 0; i < 26; i++) {
		if (in[i]==-1) continue;
		if (!in[i] && st != -1) return "?";
		if (!in[i]) st = i;
	}
	string ans;
	queue <int> q;
	q.push(st);
	while (q.size()) {
		int now = q.front(); q.pop();
		ans += (now + 'a');
		int flag = 0;
		for (auto next : adj[now]) {
			if (!(--in[next])) {
				if (flag++) return "?";
				q.push(next);
			}
		}
	}
	return ans += "\0";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (auto j : s[i]) in[j - 'a'] = 0;
	}
	for (int i = 2; i <= n; i++)
		if (!order(s[i - 1], s[i])) {
			cout << "!\n";
			return 0;
		}
	cout << bfs() << '\n';
	return 0;
}