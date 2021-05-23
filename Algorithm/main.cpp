#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

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
    int a, b;
    cin >> n >> m;
    for(int i=1; i<= n; i++){
        unf[i] = i;
    }
    for(int i=0; i<m; i++){
        cin >> a >> b;
        Union(a, b);
    }
    int s , e;
    cin >> s >> e;
    
    a = Find(s);
    b = Find(e);
    
    if(a == b){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    
    return 0;
}
