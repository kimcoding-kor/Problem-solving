#include <cstdio>
#include <iostream>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	function <void(int)> dfs = [&](int level) {
		function <void()> underline = [=] {
			for (int i = 1; i <= level * 4; i++) cout << '_';
		};
		underline();
		cout << "\"����Լ��� ������?\"" << '\n';
		if (level == n) {
			underline();
			cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		}
		else {
			underline();
			cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
			underline();
			cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
			underline();
			cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';
			dfs(level + 1);
		}
		underline();
		cout << "��� �亯�Ͽ���." << '\n';
	};
	dfs(0);
	return 0;
}