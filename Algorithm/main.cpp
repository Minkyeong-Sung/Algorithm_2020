#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 날짜 기준으로 내림차순 
bool compare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(){
    
    int n,d, m, max = -2147000000;
    vector<pair<int, int>> vt;
    priority_queue<int> pQ;
    
    // input
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m >> d;
        vt.push_back(make_pair(m, d));
        
        // 가장 늦은 마감 일자 찾기
        if(max < d){
            max = d;
        }
    }
    // sort
    sort(vt.begin(), vt.end(), compare);
    
    // solve
    // 가장 늦은 날부터 가점 +
    int j = 0;
    int result = 0;
    for(int i=max; i>= 1; i--){
        for( ; j< n; j++){
            
            // 지금 날짜보다 적은 날짜는 카운트 하지 않겠다.
            if( vt[j].second < i) break;
            
            // 가능한 모든 돈 넣기
            pQ.push(vt[j].first);
        }
        
        if(!pQ.empty()){
            result += pQ.top();
            pQ.pop();
        }
    }
    
    cout << result;
    
    return 0;
}
