#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main() {
	FIO;
	string s;
	auto vow = [&](char ch) {
		return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u');
	};
	auto check = [&]() {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			cnt += vow(s[i]);
			if (i <= (int)s.size() - 3 && vow(s[i]) == vow(s[i + 1]) && vow(s[i + 2]) == vow(s[i])) return 0;
			if (i <= (int)s.size() - 2 && s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o') return 0;
		}
		if (!cnt) return 0;
		return 1;
	};
	while (cin >> s && s != "end")
		cout << '<' << s << "> is " << (check() ? "" : "not ") << "acceptable." << '\n';
	return 0;
}