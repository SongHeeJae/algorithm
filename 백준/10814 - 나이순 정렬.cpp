#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Person {
	int age;
	string name;
	int order;
};

bool comp(const Person& a, const Person& b) {
	return a.age != b.age ? a.age < b.age : a.order < b.order;
}

int main() {
	vector<Person> p;
	int n, a;
	string s;
	scanf("%d", &n);
	for (int i = 0; i < n && cin >> a >> s; i++) p.push_back(Person{a, s, i});
	std::sort(p.begin(), p.end(), comp);
	for (Person pp : p) cout << pp.age << " " << pp.name << "\n";
}