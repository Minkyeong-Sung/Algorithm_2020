#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    
    int t, n, m, x, y;
    cin >> t;
    
    for(int i=0; i<t; i++){
        
        cin >> n >> m >> x >> y;
        
        bool flag = true;
        
        // 하나의 수를 고정하면, 최대 탐색 경우의 수는 절반이 된다.
        for(int j=x; j< m*n; j += n){
            
            // 고정 시킨 후, y값을 도출해내는 조건 검색
            if( (((j-1)%m) + 1 )== y ){
                cout << j <<'\n';
                flag = false;
                break;
            }
        }
        
        // 최대로 탐색해도 답이 없을 경우 
        if(flag){
            cout << "-1\n";
        }
    }
    return 0;
}


/*
 || tmpY <= 4000
 **/
