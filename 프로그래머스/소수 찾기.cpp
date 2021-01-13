#include <string>
#include <vector>
#include <set>
#define MAX 10000000
using namespace std;
vector<bool> primes(MAX, true);
string my_numbers = "";
vector<bool> visit(7, false);
set<int> answer;

void initPrimes() {
    primes[0] = primes[1] = false;
    for(int i=2; i<MAX; i++)
        for(int j=i+i; j<MAX; j+=i)
            primes[j] = false;
}

int stringToNumber() {
    int num = 0;
    for(int i=0; i<my_numbers.size(); i++)
        num = num * 10 + (my_numbers[i] - '0');
    return num;
}

void dfs(string& numbers, int depth) {
    int num = stringToNumber();
    if(primes[num]) answer.insert(num);
    if(depth == numbers.size()) return;
    for(int i=0; i<numbers.size(); i++) {
        if(!visit[i]) {
            visit[i] = true;
            my_numbers.push_back(numbers[i]);
            dfs(numbers, depth + 1);
            visit[i] = false;
            my_numbers.pop_back();
        }
    }
}


int solution(string numbers) {
    initPrimes();
    dfs(numbers, 0);
    return answer.size();
}