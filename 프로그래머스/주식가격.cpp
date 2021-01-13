#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    for(int i=0; i<prices_len; i++) {
        int j;
        for(j=i+1; j<prices_len; j++) {
            if(prices[j] < prices[i]) {
                break;
            }
        }
        answer[i] = j - i - (j == prices_len);
    }
    return answer;
}