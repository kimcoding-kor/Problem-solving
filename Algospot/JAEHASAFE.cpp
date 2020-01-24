#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector <int> vi;

vi get_pi(string &s) {
	int len = s.length();
	vi pi(len);
	for (int i = 1, j = 0; i < len; i++) {
		while (j && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}

int kmp(string &s, string &w) {
	int slen = s.length();
	int wlen = w.length();
	vi pi = get_pi(w);
	for (int i = 0, j = 0; i < slen; i++) {
		while (j && s[i] != w[j])
			j = pi[j - 1];
		if (s[i] == w[j]) {
			j++;
			if (j == wlen) return i - j + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int test; cin >> test; while (test--) {
		int n; cin >> n;
		int sum = 0;
		string s, w;
		cin >> s;
		for (int i = 1; i <= n; i++) {
			cin >> w;
			string temp;
			if (i & 1) {
				temp = w + w; temp.pop_back();
				sum += kmp(temp, s);
			}
			else {
				temp = s + s; temp.pop_back();
				sum += kmp(temp, w);
			}
			s = w;
		}
		cout << sum << "\n";
	}
	return 0;
}