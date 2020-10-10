#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

/*
 [코딜리티] Task 6. NumberOfDiscIntersections - 93% (overflow)
 
 */
bool comp(const pair<int, int>& v1, const pair<int, int>& v2){
    return (v1.first < v2.first);
}

int solution(vector<int> &A) {
    int ans = 0;
    int size = (int)A.size();
    vector<pair<int, int>> vt; // first : 왼쪽  , second : 오른쪽
    
    // input
    for(int i=0; i<size; i++){
        vt.push_back({i-A[i], i+A[i]});
    }
    
    // 왼쪽을 기준으로 정렬 후, 중복되는 원들을 카운트 시작한다.
    sort(vt.begin(), vt.end(), comp);
    //sort(A.begin(), A.end());
    
    // i 범위 : size - 1  => 가장 마지막 원은 카운트 대상이 아니기 때문 ( 이미 중복되는 거라면 앞선 idx에서 포함되기 떄문에
    for(int i=0; i< size-1 ; i++){
        // i 다음에 있는 원들이 포함되어 있는지 확인한다.
        for(int j=i+1; j<size; j++){
            
            // 예외처리 1
            if(ans > 10000000){
                return -1;
            }

            // 비교.right < 지금기준원.left 인경우 포함되지 않는 경우로 종료
            if(vt[i].second < vt[j].first){
                break;
            }

            if(vt[i].first <= vt[j].first && vt[i].second >= vt[j].first){
                ans++;
            }
        }
    }
    
    return ans;
}


