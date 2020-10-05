#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[20][20];

int calculate(vector<int> t1, vector<int> t2){
    
    int sum = 0;
    int num1 = 0, num2 = 0;
    
    // 대각선 라인을 제외 하고, 계산한다.
    for(int i=0; i<t1.size(); i++){
        for(int j=0; j<t1.size(); j++){
         
            if(i==j) continue;
            num1 += arr[t1[i]][t1[j]];
        }
    }
    
    for(int i=0; i<t2.size(); i++){
        for(int j=0; j<t2.size(); j++){
         
            if(i==j) continue;
            num2 += arr[t2[i]][t2[j]];
        }
    }
    
    sum = abs(num1 - num2);
    return sum;
}

int main(){
    
    int n;
    int ans = 987654321;
    
    
    // input
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    vector<int> vt;
    
    // 팀 편성을 위해, 0과 1을 각각 넣어서 순열을 돌리기 위한 사전 작업을 한다
    // 그래서 0인 값, 1인 값의 인덱스로 각각 나누어 본다
    for(int i=0; i<n/2; i++){
        vt.push_back(0);
    }
    for(int i=0; i<n/2; i++){
        vt.push_back(1);
    }
    
    
    // 순열 시작
    do {
        vector<int> t1, t2;
        
        // 순열 값을 통해서 실제 값을 저장할 때 필요한 인덱스를 저장한다.
        for(int i=0; i<vt.size(); i++){
            
            if(vt[i] == 1){
                t1.push_back(i);
            }
            else{
                t2.push_back(i);
            }
        }
        
        // 배열에 따른 값 계산
        ans = min ( ans, calculate(t1, t2));
        
    } while ( next_permutation(vt.begin(), vt.end()));
    
    
    cout << ans ;
    
    return 0;
}


