#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

char ch[11];
vector<int> minNum, maxNum;
int k;

bool isPossible(vector<int> numbers){

    // 부등호 갯수만큼 확인
    for(int i=0; i<k; i++){
        
        // 조건에 맞지 않는 경우를 false 로 반환한다.
        if(ch[i] == '>' && numbers[i] < numbers[i+1]){
            return false;
        }
        
        if(ch[i] == '<' && numbers[i] > numbers[i+1]){
            return false;
        }
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> k;
    
    for(int t=0; t<k; t++){
        cin >> ch[t];
    }
    
    for(int i=0; i<=k; i++){
        minNum.push_back(i);
        maxNum.push_back(9-i);
    }
    
    // 최대를 찾는 경우
    /*
     9~0 순번으로 저장 된 수들을 이전 순열(내림차순)*을 통해 하나씩 이동하면서 바꾼다.
     */
    do {
        if(isPossible(maxNum)){
            break;
        }
    } while (prev_permutation(maxNum.begin(), maxNum.end()));
    
    
    // 최소를 찾는 경우
    /*
     0~ 9 순번으로 저장 된 수들을 다음 순열(오름차순)을 통해 하나씩 이동하면서 바꾼다.
     */
    do {
        if( isPossible(minNum)){
            break;
        }
    } while (  next_permutation( minNum.begin(), minNum.end()));
    
    
    for(int i=0; i<= k; i++){
        cout << maxNum[i];
    }
    cout <<'\n';
    
    for(int i=0; i<=k; i++){
        cout << minNum[i];
    }
    return 0;
}
