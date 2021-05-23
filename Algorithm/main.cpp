#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int DFS(int n, int r){
    
    if( n == r || r == 0){
        return 1;
    }
    else{
        // n-1 개중 r-1 만큼만 뽑겠다 , n-1개중 r 만큼 모두(내가 참여하지 않는 경우) 뽑겠다
        return  DFS(n-1, r-1) + DFS(n-1, r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << DFS(n, m);
    
    
    return 0;
}
