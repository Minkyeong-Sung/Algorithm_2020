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
    
    int n;
    cin >> n;
    
    int n1=1, n2;
    int tmp = n;
    int cnt = 0;
    
    n2 = 1;
    tmp -= n1;
    while(tmp>0){
        n2++;
        tmp -= n2;
        if( tmp % n2 == 0){
            cnt ++;
            for(int i=n1; i<n2; i++){
                cout << (i + (tmp/n2))<< " + ";
            }
             cout << (n2 + (tmp/n2)) << " = " << n << '\n';
        }
       
    }
    cout << cnt;
    
    
    return 0;
}
