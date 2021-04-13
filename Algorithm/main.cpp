#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int s, n , input, pos =0;
    int i, j;
    cin >> s >> n;
    
    int arr[20];
    
    for( i=1; i<=n; i++){
        cin >> input;
        
        // 중단점 찾기
        pos = -1;
        for( j=0; j<s; j++){
            if( arr[j] == input){
                pos = j;
            }
        }
        
        // insert
        if(pos == -1){
            for(j = s-1; j>=1; j--){
                arr[j] = arr[j-1];
            }
        }
        // move and insert
        else{
            for(j = pos; j>=1; j--){
                arr[j] = arr[j-1];
            }
        }
        arr[j] = input;
    }
    
    for(int i=0;i<s; i++){
        cout << arr[i] << ' ';
    }
    
    
    
    
    return 0;
}
