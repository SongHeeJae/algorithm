#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	int c = 0;
	cin >> word;
	for (int i = 0;i<word.length(); i++) {
		if (word[i] == 'c' && i + 1 < word.length() && (word[i + 1] == '=' || word[i + 1] == '-'))
			i++;
		else if (word[i] == 'l' && i + 1 < word.length() && word[i+1] == 'j')
			i++;
		else if (word[i] == 'n' && i + 1 < word.length() && word[i + 1] == 'j')
			i++;
		else if (word[i] == 's' && i + 1 < word.length() && word[i + 1] == '=')
			i++;
		else if (word[i] == 'z' && i + 1 < word.length() && word[i + 1] == '=')
			i++;
		else if (word[i] == 'd' && i + 1 < word.length() && word[i + 1] == '-')
			i++;
		else if (word[i] == 'd' && i + 2 < word.length() && word[i + 1] == 'z' && word[i+2]=='=')
			i+=2;
		c++;
	}
	printf("%d\n", c);
}