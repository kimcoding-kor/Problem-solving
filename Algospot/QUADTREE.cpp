#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int index;

string function(string &st) {
	string temp[4];
	string ans = "x";
	if (st[index++] != 'x')
		return st[index - 1] == 'w' ? "w" : "b";
	for (int i = 0; i < 4; i++)
		temp[i] = function(st);
	for (int i = 2; i < 6; i++)
		ans += temp[i%4];
	return ans;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		char arr[1005];
		scanf("%s", arr);
		string st = arr;
		index = 0;
		printf("%s\n", function(st).c_str());
	}
	return 0;
}