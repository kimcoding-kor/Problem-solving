#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector <string> vs;
typedef vector <int> vi;
typedef vector <vi> vvi;

vi get_pi(string w) {
	vi pi(w.size());
	for (int i = 1, j = 0; i < w.size(); i++) {
		while (j && w[i] != w[j]) j = pi[j - 1];
		if (w[i] == w[j]) pi[i] = ++j;
	}
	return pi;
}

int kmp(string s, vs w, vvi pi, int n) {
	vi idx(n), dp(s.size() + 1);
	for (int i = 0; i < s.size(); i++) {
		dp[i + 1] = max(dp[i], dp[i + 1]);
		for (int j = 0; j < n; j++) {
			int &k = idx[j];
			while (k && s[i] != w[j][k]) 
				k = pi[j][k - 1];
			if (s[i] == w[j][k]) {
				if (k + 1 == w[j].size()) {
					dp[i + 1] = max(dp[i + 1], dp[i - k] + k + 1);
					k = pi[j][k];
				}
				else ++k;
			}
		}
	}
	return dp[s.size()];
}

int main() {
	string s;
	int n;
	cin >> s >> n;
	vs w(n);
	vvi pi(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		pi[i] = get_pi(w[i]);
	}
	cout << kmp(s, w, pi, n) << '\n';
	return 0;
}