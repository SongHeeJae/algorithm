#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, s1, s2, temp, name;
	getline(cin, s);
	int i = s.find(' ') - 1, j;
	s1 = s.substr(0, i + 1);
	for (j = 0; j < s1.length() && s1[j] != '*' && s1[j] != '&' && s1[j] != '[' && s1[j] != ']'; j++);
	s1 = s.substr(j, i-j+1);
	s2 = s.substr(0, j);
	while (1) {
		j = s.find(',', i + 1);
		j = j == -1 ? s.length()-1 : j;
		temp = s.substr(i + 2, j - i - 2);
		cout << s2 << s1;
		name = "";
		for (int k = temp.size() - 1; k >= 0; k--) {
			char ch = temp[k];
			if (ch == '*' || ch == '&') cout << ch;
			else if (ch == ']') cout << "[]", k--;
			else name += ch;
		}
		reverse(name.begin(), name.end());
		cout << " " << name << ";\n";
		if (j == s.length() - 1) break;
		i = j;
	}

}

/*
일단 전체 문장을 입력받은 뒤, 첫 공백까지 잘라냈습니다.
이를 통해 변수의 타입과 타입 옆에 지정된 [], &, *를 따로 걷어냈습니다.
각 줄마다 변수 타입을 먼저 출력해주고, 쉼표 단위로 계속 다음 변수의 위치를 찾아내면서 역순으로 [], &, *를 출력해준 뒤에, 그 과정에서 저장한 변수명을 역순으로 다시 출력해줬습니다.
*/