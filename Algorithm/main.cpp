#include <iostream>
#include <algorithm>

using namespace std;

int map[8][8];
int visit[8][8];
int cnt = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y){
    
    if(x == 7 && y == 7){
        cnt++;
    }
    else{
        
        for(int d=0; d<4; d++){
            int tx = x + dx[d];
            int ty = y + dy[d];
            
            if(tx < 1  || tx > 7 || ty < 1 || ty > 7) continue;;
            
            if(visit[tx][ty] == 0 && map[tx][ty] == 0){
                visit[tx][ty] = 1;
                DFS(tx, ty);
                visit[tx][ty] = 0;
            }
        }
        
        
    }
    
}

int main(){
    
    for(int i=1; i<= 7; i++){
        for(int j=1; j<= 7; j++){
            cin >> map[i][j];
        }
    }
    
    visit[1][1] = 1;
    DFS(1,1);
    
    cout << cnt;
    
    return 0;
}
