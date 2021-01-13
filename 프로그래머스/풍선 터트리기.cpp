#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a[], size_t a_len) {
    int answer = 0, l = 0, r = a_len-1;
    for(int i=0; i<a_len; i++) {
        if(a[i] <= a[l]) {
            l = i;
            answer++;
        }
        if(a[a_len-1-i] <= a[r]) {
            r = a_len-1-i;
            answer++;
        }
    }
    return answer - (l == r);
}

/*

'?'는 query 문자열에 무조건 들어가고, 중간에는 들어가지않는 조건을 염두에 두고 풀었습니다.

효율성 테스트 때문에 Trie를 최대 길이만큼 선언해준 뒤, 각 word의 길이에 해당하는 Trie에만 삽입해주었습니다.

'?'는 query 문자열의 뒤에서 시작할 수도 있기 때문에, 문자열을 역순으로 뒤집은 것도 별도의 Trie에 삽입해주었습니다.

예를 들어, 'abc'는 역순으로 뒤집은 'cba'도 역순 Trie에 삽입하였습니다.

삽입을 하며, 지나가는 경로의 cnt를 1씩 계속 증가시켜주었습니다.

그렇게 되면, 루트에는 현재 Trie에 들어간 모든 단어의 개수가 나옵니다.

검색을 할 때는, query 문자열에서 '?'를 만났을 때의 cnt를 반환해주면 됩니다. 어차피 길이별로 구분해서 넣어주기 때문입니다.

*/