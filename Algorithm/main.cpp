#include <iostream>
#include <algorithm>

using namespace std;

int arr[21][21];
int visit[21]; //
int n, cnt = 0;

void DFS(int num){
    
    if(num == n){
        cnt ++;
    }
    else{
        for(int i=1; i<= n; i++){
            if(arr[num][i] == 1 && visit[i] == 0){
                // 방문 표시
                visit[i] = 1;
                DFS(i);
                // 다시 방문 해제
                visit[i] = 0;
                
            }
        }
         
        
    }
}

int main(){
    int m, x, y;
    cin >> n >> m;
    
    memset(arr, 0, sizeof(arr));
    
    for(int i=1; i<=m; i++){
        cin >> x >> y;
        arr[x][y] = 1;
    }
    
    visit[1] = 1;
          
    DFS(1);
    
    cout << cnt;
    
    return 0;
}
