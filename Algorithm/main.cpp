#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
 어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를 Ugly Number라고 부릅니다. Ugly Number를 차례대로 적어보면
 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다. 숫자 1은 Ugly Number의 첫 번째 수로 합 니다. 자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하는 프로그램을 작성하세요.
 
 input : 10 / output : 12
 input : 1500 / output : 859963392
 
 
 */

int main(){
    
    int n, p2=1, p3=1, p5=1;
    cin >> n;
    
    int arr[1502];
    arr[1] = 1;
    int min = 0;
    
    for(int i=2; i<= n; i++){
        
        // find min value
        if(arr[p2] * 2 < arr[p3]*3){
            min = arr[p2]* 2;
        }
        else{
            min = arr[p3]*3;
        }
        if(arr[p5]* 5 < min){
            min = arr[p5]*5;
        }
        
        // 최솟값 적용 후, 포인터 1 증가
        if(arr[p2]*2 == min) p2++;
        if(arr[p3]*3 == min) p3++;
        if(arr[p5]*5 == min) p5++;
        
        arr[i] = min;
    }
    
    cout << arr[n] ;
    
    return 0;
}
