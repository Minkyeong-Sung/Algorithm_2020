#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    
    int n, m, v, u;
    
    cin >> n >> m;
    
    vector<int> vt[21];
    queue<int> q;
    int visit[21];
    int dist[21];
    
    for(int i=0; i<m; i++){
        cin >> v >> u;
        vt[v].push_back(u);
        
        // init
        dist[i] = 0;
        visit[i] = 0;
    }
    
    q.push(1);
    visit[1] = 1;
    
    while(!q.empty()){
        
        int next = q.front();
        q.pop();
        
        for(int i=0; i< vt[next].size(); i++){
            
            if(visit[vt[next][i]] == 0){
                
                visit[vt[next][i]] = 1;
                q.push(vt[next][i]);
                
                // 다음 좌표까지 가는 최소 간선의 수
                // 현재까지 온 간선 수 + 1 이 최소 간선의 길이 
                dist[vt[next][i]] = dist[next] + 1;
            }
        }
    }
    
    for(int i=2; i<= n; i++){
        cout << i << " : " << dist[i] << '\n';
    }
    
    
    return 0;
}
