#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
 입력으로 양의 정수 N이 입력되면 2개 이상의 연속된 자연수의 합으로 정수 N을 표현하는 방 법의 가짓수를 출력하는 프로그램을 작성하세요.
 만약 N=15이면
 7+8=15
 4+5+6=15
 1+2+3+4+5=15
 와 같이 총 3가지의 경우가 존재한다.
 */

int main(){
    
    int n, i;
    int num= 1;
    int tmp;
    cin >> n;
    
    tmp = n;
    n --;
    while(n>0){
        num++;
        n = n - num;
        
        if( n% num ==0){
            
            for(i = 1; i<num; i++){
                cout << (n / num) + i  << " + " ;
            }
            cout << (n/num) + i << " = " << tmp << '\n';
        }
    }
    
    
    return 0;
}
