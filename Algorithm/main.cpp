#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int visit[30];

struct Node{
  
    int n;
    int val;
    
    Node(int a, int b){
        n = a;
        val = b;
    };
    
    // 가중치 기준으로 오름차순 (최소 힙)
    bool operator<(const Node &b)const{
        return val > b.val;
    }
    
};

int main(){
    
    int v, e, a, b, c;
    int result = 0;
    
    vector<pair<int, int>> vt[30];
    priority_queue<Node> q;
    
    // input
    cin >> v >> e;
    
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        vt[a].push_back(make_pair(b, c));
        vt[b].push_back(make_pair(a, c));
    }
    
    // 시작 위치 설정
    q.push( Node(1, 0));
    while(!q.empty()){
        
        Node tmp = q.top();
        q.pop();
        
        // 다음 위치 탐색
        int v = tmp.n;
        int val = tmp.val;
        
        // 방문하지 않은 노드인 경우
        if(visit[v] == 0){
            
            result += val;
            visit[v] = 1;
            
            // 그 노드와 연결된 정보 저장
            for(int i=0; i< vt[v].size(); i++){
                q.push( Node(vt[v][i].first, vt[v][i].second));
            }
        }
    }
    
    cout << result;
    
    return 0;
}
