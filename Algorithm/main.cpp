#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    
    int n, m;
    int visit[100001];
    queue<int> q;
    
    cin >> n >> m;
    
    memset(visit, 0, sizeof(100001));
    
    q.push(n);
    visit[n] = 1;
    
    // +1, -1, +5 만큼 이동할 배열
    int dir[3] = {1, -1, 5};
    
    while(!q.empty()){
        int next = q.front();
        q.pop();
        
        for(int d=0; d<3; d++){
            
            if(next + dir[d] == m){
                cout << visit[next] ;
                return 0;
            }
            
            if(visit[next + dir[d]] == 0){
                visit[next + dir[d]] = visit[next] + 1;
                q.push(next + dir[d]);
            }
        }
    }
    
    
    
    return 0;
}
