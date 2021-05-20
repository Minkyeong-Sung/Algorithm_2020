#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int visit[21];
vector<int> vt[21];
int n, cnt = 0;

void DFS(int num){
    
    if(num == n){
        cnt++;
    }
    else{
        
        for(int i=0; i<vt[num].size(); i++){
            
            // 갔던 곳인지 검사
            if(visit[vt[num][i]] == 0){
                // visit
                visit[vt[num][i]] = 1;
                // v와 연결된 노드 번호를 넘겨준다. 
                DFS(vt[num][i]);
                // 방문 해제
                visit[vt[num][i]] = 0;
            }
        }
    }
    
}


int main(){
    
    int m;
    int v, u;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        cin >> v >> u;
        vt[v].push_back(u);
    }
    
    visit[1] = 1;
    DFS(1);
    
    cout << cnt;
    
    return 0;
}
