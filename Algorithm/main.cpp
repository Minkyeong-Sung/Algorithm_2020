#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[52][52];
int map[52][52];

int main(){
    
    int h, w, n,m;
    
    cin >> h >> w;
    
    // boundry check
    memset(arr, 0, sizeof(arr[h][w]));
           
    for(int i=1; i<= h; i++){
        for(int j=1; j<= w; j++){
            cin >> arr[i][j];
            map[i][j] = map[i][j-1] + map[i-1][j] - map[i-1][j-1] + arr[i][j];
        }
    }
    
    cin >> n >> m;
    
    int result = 0;
    int max = 0;
    
    for(int i=n; i<=h ; i++ ){
        for(int j=m; j<= w; j++){
            
            result = map[i][j] - map[i-n][j] - map[i][j-m] + map[i-n][j-m];
            if(result > max){
                max = result;
            }
            
        }
    }
    
    cout << max;
    
    return 0;
}
