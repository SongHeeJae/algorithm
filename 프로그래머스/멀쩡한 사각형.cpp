int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

long long solution(int w,int h) {
    int g = gcd(w, h);
    return (long long)w*h- g*((w/g)+(h/g)-1);
}

/*
블록 덩어리의 개수는 최대 공약수입니다. 각 블록의 정사각형 개수를 구한 뒤 계산해줬습니다.


*/