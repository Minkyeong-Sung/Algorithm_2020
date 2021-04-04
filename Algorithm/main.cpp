#include <iostream>

using namespace std;

int main(){
    
    int n, cnt = 0;
    bool flag = true;
    cin >> n;
    
    for(int i=2; i<=n; i++){
        flag = true;
        // 소수는 구하고자 하는 수의제곱근 만큼만 비교해서, 약수가 존재하는지만 판단하면 된다.
        for(int j=2;j*j<=i; j++){
            if(i % j==0){
                flag= false;
                break;
            }
        }
        if(flag == true) cnt ++;
    }
    
    cout << cnt;
    return 0;
}
