#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
#define all(x) (x).begin(), (x).end()

vi get_pi(string &s, int len) {
	vi pi(len);
	for (int i = 1, j = 0; i < len; i++) {
		while (j && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}

int kmp(string &s, int len) {
	string temp = s;
	reverse(all(temp));
	vi pi = get_pi(temp, len);
	for (int i = 0, j = 0; i < len; i++) {
		while (j && s[i] != temp[j])
			j = pi[j - 1];
		if (s[i] == temp[j]) {
			j++;
			if (len == i + 1) return 2 * len - j;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int test; cin >> test;
	while (test--) {
		string s;
		cin >> s;
		cout << kmp(s, (int)s.size()) << "\n";
	}
	return 0;
}