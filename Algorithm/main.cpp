#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    
    int n, m;
    queue<int> q;
    
    cin >> n >> m;
    
    for(int i=1; i<= n; i++){
        q.push(i);
    }
    
    int cnt = 0;
    while(!q.empty()){
        
        if(q.size() == 1){
            break;
        }
        
        cnt ++;
        int next = q.front();
        q.pop();
        
        if(cnt == m){
            cnt = 0;
        }
        else{
            q.push(next);
        }
    }
    
    cout << q.front();
    
    return 0;
}
