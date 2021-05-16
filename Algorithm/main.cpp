#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
 10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요
 */

int st[100];
int top = -1;

void push(int num){
    st[++top] = num;
}

int pop(){
    return st[top--];
}

int main(){
    int n, k;
    
    cin >> n >> k;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6' , '7', '8', '9' , 'A', 'B', 'C', 'D', 'E', 'F' };
    
    while(n >0){
        push(n%k);
        n/= k;
    }
    
    while(top != -1){
        cout << arr[pop()];
    }
    
    return 0;
}
