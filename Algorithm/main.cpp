#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool remocon[11];

int isPossible(int n){
    
    
    if(n==0){
        // 고장난 번호라면 0을 리턴
        if(remocon[n]){
            return 0;
        }
        else{
            return 1;
        }
    }
    
    int len = 0;
    
    while(n > 0){
        
        if(remocon[n%10]) {
            return 0;
        }
        n /= 10;
        len +=1;
    }
    
    return len;
}

int main(){
    
    int n, m, x;
    int ans = 0;
    
    cin >> n >> m ;
    
    for(int i=0; i<m; i++){
        cin >> x;
        remocon[x] = true;
    }
    
    // 양수로 설정
    ans = n - 100;
    if(ans < 0){
        ans = -ans;
    }

    // 리모컨을 눌러볼 수 있는 최대 갯수만큼 탐색한다.
    for(int i=0; i<= 1000000; i++){

        // check available number
        // 고장난 리모컨 번호가 몇개 있는지 확인한다.
        int len = isPossible(i);

        //고장난 번호가 없다면, 이동해야하는 채널 - 현재번호(100) 만큼의 최소 값을 구한다.
        if(len >0){
            int press = i - n;
            
            if(press<0){
                press = -press;
            }
            
            if(ans > press + len){
                ans = press + len;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
