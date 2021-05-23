#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Road{
    int s;
    int e;
    int price;
};

bool compare(Road &a, Road &b){
    return a.price < b.price;
}

int unf[10001];

//메모이제이션 활용 & 해당 배열 찾기
int Find(int n){
    if(unf[n] == n){
        return  n;
    }
    else{
        return unf[n] = Find(unf[n]);
    }
}
// 찾은 후, 합치기
void Union(int a, int b){
    
    a = Find(a);
    b = Find(b);
    
    // 합치기
    if(a != b){
        unf[a] = b;
    }
}

int main(){
    int n, m;
    
    vector<Road> vt;
    Road r;
    
    cin >> n >> m;
    
    for(int i=1; i<= n; i++){
        unf[i] = i;
    }
    // 구조체 형식으로 벡터에 저장  (가중치 값을 기준으로 넣음)
    for(int i=0; i<m; i++){
        cin >> r.s >> r.e >> r.price;
        vt.push_back(r);
    }
   
    sort(vt.begin(), vt.end(), compare );
    
    int a, b;
    int result = 0;
    for(int i=0; i<m; i++){
        // 간선을 먼저 선택한다.
        a = Find(vt[i].s);
        b = Find(vt[i].e);
        
        // 서로 다른 집합이라면, 값을 누적하고 union 한다.
        // 가중치를 최소 값을 구하지 않은 이유는 사전에 오름차순으로 정렬했기때문 .
        if( a != b){
            result += vt[i].price;
            Union(vt[i].s, vt[i].e);
        }
    }
    
    
    return 0;
}
