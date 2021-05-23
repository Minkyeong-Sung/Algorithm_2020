#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 메모이제이션 사용
// 해당 배열의 값을 미리 저장해두고 사용
int dy[21][21];

int DFS(int n, int r){
    
    // 미리 구한 값을 바로 사용 : 시간절약
    if(dy[n][r] > 0) return dy[n][r];
    
    if( n == r || r == 0){
        return 1;
    }
    else{
        // n-1 개중 r-1 만큼만 뽑겠다 , n-1개중 r 만큼 모두(내가 참여하지 않는 경우) 뽑겠다
        return  dy[n][r]  = DFS(n-1, r-1) + DFS(n-1, r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << DFS(n, m);
    
    
    return 0;
}
