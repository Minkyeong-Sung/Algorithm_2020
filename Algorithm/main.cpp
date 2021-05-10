#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 
 1) 컴퓨터는 1번 작업부터 순서대로 1초씩 작업을 한다. 즉 각 작업을 1초만 작업하고 다음 작업을 하는 식이다.
 2) 마지막 번호의 작업을 1초 했으면 다시 1번 작업으로 가서 다시 1초씩 후속 처리를 한다. 3) 처리가 끝난 작업은 작업 스케쥴에서 사라지고 새로운 작업은 들어오지 않는다.
 그런데 현수의 컴퓨터가 일을 시작한 지 K초 후에 정전이 되어 컴퓨터가 일시적으로 멈추었 다. 전기가 들어오고 나서 현수의 컴퓨터가 몇 번 작업부터 다시 시작해야 하는지 알아내는 프로그램을 작성하세요.
 첫 번째 줄에 몇 번 작업부터 다시 시작해야 하는지 작업 번호를 출력한다. 만약 더 이상 처리할 작업이 없다면 -1를 출력한다.
 
 */

int main(){
    
    int n,k, sum = 0;
    cin >> n;
    
    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    cin >> k;
    
    if(k > sum){
        cout << -1 ;
        return 0;
    }
    
    int time = 0;
    int pos = 0;
    while(1){
        
        pos ++;
        if(pos>n) pos =1;
        
        if(arr[pos] == 0) continue;
        
        arr[pos]--;
        time++;
        
        if(time == k){
            break;
        }
    }
    
    while(1){
        
        pos ++;
        if(pos>n) pos =1;
        
        if(arr[pos] != 0) break;
        
    }
    cout <<  pos ;
    
    
    return 0;
}
