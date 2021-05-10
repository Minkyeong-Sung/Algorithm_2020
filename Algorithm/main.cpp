#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/*
 지도 정보가 N*N 격자판에 주어집니다. 각 격자에는 그 지역의 높이가 쓰여있습니다. 각 격자 판의 숫자 중 자신의 상하좌우 숫자보다 큰 숫자는 봉우리 지역입니다. 봉우리 지역이 몇개 있는 지 알아내는 프로그램을 작성하세요.
 격자의 가장자리는 0으로 초기화 되었다고 가정한다.
 
 
 
 */
int main(){
    
    int n;
    int arr[50][50];
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    int result = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            int flag = 1;
            
            // 동서남북으로 탐색 시작
            for(int d = 0; d<4; d++){
                
                int nx = i + dx[d];
                int ny = j + dy[d];
                
                if( nx >= 0 && nx < n && ny >= 0 && ny< n ){
                    
                    if(arr[i][j] <  arr[nx][ny]){
                        flag = 0;
                        break;
                    }
                }
            }
            
            if(flag == 1){
                result ++;
            }
        }
    }
    
    cout << result;
    
    
    return 0;
}
