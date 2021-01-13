#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
deque<int> d;

void push_front(int n) {
	d.push_front(n);
}

void push_back(int n) {
	d.push_back(n);
}

void size() {
	printf("%d\n", d.size());
}

void empty() {
	printf("%d\n", d.empty() ? 1 : 0);
}

void front() {
	printf("%d\n", d.empty() ? -1 : d.front());
}

void back() {
	printf("%d\n", d.empty() ? -1 : d.back());
}

void pop_front() {
	front();
	if(!d.empty()) d.pop_front();
}

void pop_back() {
	back();
	if (!d.empty()) d.pop_back();
}

int main() {
	int n, a;
	char comm[15];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", comm, sizeof(comm));
		if (strcmp(comm, "front") == 0) front();
		else if (strcmp(comm, "size") == 0) size();
		else if (strcmp(comm, "back") == 0) back();
		else if (strcmp(comm, "empty") == 0) empty();
		else if (strcmp(comm, "pop_front") == 0) pop_front();
		else if (strcmp(comm, "pop_back") == 0) pop_back();
		else {
			scanf("%d", &a);
			strcmp(comm, "push_back") == 0 ? push_back(a) : push_front(a);
		}
	}
}