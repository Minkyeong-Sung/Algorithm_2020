#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 
 N개의 마구간이 1차원 수직선상에 있습니다. 각 마구간은 x1, x2, x3, ......, xN의 좌표를 가 지며, 마구간간에 좌표가 중복되는 일은 없습니다.
 현수는 C마리의 말을 가지고 있는데, 이 말들은 서로 가까이 있는 것을 좋아하지 않습니다. 각 마구간에는 한 마리의 말만 넣을 수 있고, 가장 가까운 두 말의 거리가 최대가 되게 말을 마구간에 배치하고 싶습니다.
 C마리의 말을 N개의 마구간에 배치했을 때 가장 가까운 두 말의 거리가 최대가 되는 그 최대 값을 출력하는 프로그램을 작성하세요.
 */

int n;
vector<int> vt;

int isPossible(int num){

    int cnt =1;
    int position = vt[0];
    
    // 두번쨰 좌표부터 검증
    for(int i=1; i<n; i++){
        
        if(vt[i] - position >= num ){
            cnt++;
            position = vt[i];
        }
    }
    
    return cnt;
}


int main(){
    
    int  c;
    int num;
    
    cin >> n >> c;

    for(int i=0; i<n; i++){
        cin >> num;
        vt.push_back(num);
    }
    
    sort(vt.begin(), vt.end());
    
    int lt = 0, rt = vt.size() -1;
    int mid  = 0;
    int max = 0;
    int result = 0;
    
    while(lt<= rt){
        
        mid = (lt + rt)/2;
        
        if(isPossible(mid) >= c){
            result =  mid;
            lt = mid + 1;
        }
        else{
            rt = mid -1;
        }
    }
    
    cout << result;
    
    return 0;
    
}
