#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef struct p { char c; int idx; }p;

string s;

bool oper(char x) {
	if (x == '+' || x == '-' ||
		x == '*' || x == '/' || x == '%') return true;
	return false;

}

p rec(int idx, bool first) {
	bool proper = true;
	int i;
	for (i = 1; idx < s.size(); i++) {
		if (i & 1) {
			if (s[idx] == '(') {
				p now = rec(idx + 1, false);
				if (now.c == 'e') return p{ 'e', 0 };
				if (now.c == 'n') proper = false;
				idx = now.idx;
			}
			else if (oper(s[idx]) || s[idx] == ')')
				return p{ 'e', 0 };
		}
		else {
			if (s[idx] == ')') {
				if(first) return p{ 'e', 0 };
				if (i != 4) proper = false;
				break;
			}
			if (!oper(s[idx]) || s[idx] == '(')
				return p{ 'e', 0 };
		}
		idx++;
	}
	if (i != 4) proper = false;
	if(i & 1 || (!first && s[idx] != ')')) return p{ 'e', 0 };
	return p{ proper ? 'y' : 'n', idx };
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string temp; getline(cin, temp);
	for (auto i : temp)
		if (i != ' ') s += i;
	if (s.size() == 1 && s[0] >= 'a' && s[0] <= 'z') {
		cout << "proper\n";
		return 0;
	}
	p ans = rec(0, 1);
	if (ans.c == 'e')
		cout << "error\n";
	else if(ans.c == 'n' || ans.idx < s.size())
		cout << "improper\n";
	else 
		cout << "proper\n";
	return 0;
}