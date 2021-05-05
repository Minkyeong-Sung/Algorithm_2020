#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
 N개의 수를 오름차순으로 정렬한 다음 N개의 수 중 한 개의 수인 M이 주어지면 이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지
 */

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> vt(n);
    
    for(int i=0; i<n; i++){
        cin >> vt[i];
    }
    
    int lt=0, rt = n-1;
    int mid = 0;
    sort(vt.begin(), vt.end());
    
    while(lt <= rt){
        
        mid = (lt + rt)/2;
        
        if(vt[mid] == m){
            cout << mid + 1;
            break;
            
        }else if(vt[mid] < m){
            lt = mid + 1;
        }
        else{
            rt = mid -1;
        }
    }
    
    
    return 0;
}
