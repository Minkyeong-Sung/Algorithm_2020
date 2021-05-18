#include <iostream>
#include <algorithm>

using namespace std;

int n;
int ch[11];

void DFS(int num){
    
    if(num == n+1){
        for(int i=1; i<=n;i++){
            if(ch[i] == 1){
                cout << i  << ' ' ;
            }
        }
        cout << '\n';
    }
    else{
        // left : 사용 o
        ch[num] = 1;
        DFS(num+1);
        
        // right : 사용 x
        ch[num] = 0;
        DFS(num+1);
    }
    
}

int main(){
    
    cin >> n;
    
    DFS(1);
    
    return 0;
}
