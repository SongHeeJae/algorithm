#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> set;
unordered_map<string, int> cnt;
int t, f;
int graph[200][200];
string a, b;

string findParent(string x) {
	auto f = set.find(x);
	if (f == set.end()) return x;
	else return f->second = findParent(f->second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		set.clear(); cnt.clear();
		cin >> f;
		while (f--) {
			cin >> a >> b;
			string pa = findParent(a), pb = findParent(b);
			if (pa != pb) {
				set.insert({ pa, pb });
				auto fa = cnt.find(pa), fb = cnt.find(pb);
				int s = fb == cnt.end() ? 1 : fb->second, res;
				if (fa == cnt.end()) cnt.insert({ pa, res = 1 + s });
				else res = fa->second += s;
				if (fb == cnt.end()) cnt.insert({ pb, res });
				else fb->second = res;
				cout << res << "\n";
			}
			else cout << cnt.find(pa)->second << "\n";
		}
	}
}

/*
먼저 입력받은 두 친구가 같은 네트워크인지 확인해줍니다.
이미 같은 네트워크라면, 친구 수는 동일하므로 그대로 출력해줍니다.
다른 네트워크라면, 두 그룹을 같은 그룹으로 합쳐줍니다. 
친구 수를 저장하는 별도의 map을 두어, 그 곳에 각 그룹의 최상위 부모를 기준으로 변경된 친구 수를 업데이트해주었습니다.
*/