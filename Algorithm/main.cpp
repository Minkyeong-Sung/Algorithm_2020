#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    
    // input
    int N;
    cin >> N;
    
    int tmp = N;
    int len = 0;
    
    // 총 자릿수 구하기 ( 문자 길이로 확인하는 것보다 시간이 빠르다고 한다)
    while(tmp > 0){
        len++;
        tmp /= 10;
    }
    
    int answer = 0;
    int i;
    
    // 자릿수 계산
    for(i=1; i< len; i++){
        answer += ( i* (pow(10, i) - pow(10, i-1)));
    }
    
    answer += ((N - pow(10, i-1) + 1) * i);
    
    cout << answer;
    
    
    return 0;
}
