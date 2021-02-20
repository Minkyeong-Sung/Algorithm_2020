#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 소수 판별(에라토스테네스의 체)
bool isPrime(int num){
    
    if(num <2) return false;
    
    for(int i=2; i*i<= num ; i++){
        
        if(num %i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> vt;
    vector<int> num ;
    
    // 숫자만 따로 입력 후, 중복 숫자를 제거하기 위해 정렬한다
    for(int i=0; i<numbers.size(); i++){
        vt.push_back(numbers[i]);
    }
    sort(vt.begin(), vt.end());
    
    
    // 모든 경우의 수
    do{
        string tmp = "";
        for(int i=0; i<vt.size(); i++){
            tmp.push_back(vt[i]);
            num.push_back(stoi(tmp)); // 숫자로 형 변환
        }
        
    }while (next_permutation(vt.begin(), vt.end()));
    
    // 중복 숫자 제거
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(),num.end()), num.end());
    
    for(int i=0; i<num.size(); i++){
        // 소수인지 확인 한 후, 값을 증가한다.
        if(isPrime(num[i])){
            answer++;
        }
    }
    
    return answer;
}


int main(){
    
    
    return 0;
}
