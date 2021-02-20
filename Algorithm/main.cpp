#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> qOrder; // 순서를 비교하기 위해 선언
    
    // 큐에 정보 입력
    for(int i=0; i<priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
        qOrder.push(priorities[i]);
    }
    
    
    while(!q.empty()){
        
        // 현재 작업 중인 큐의 순번이 우선순위 중 가장 높은지 확인
        if(q.front().second == qOrder.top()  ){
            
            if(q.front().first == location){
                return answer+1;
            }
            else{
                answer++;
                q.pop();
                qOrder.pop();
            }
        }
        else{
            // 지금 출력해야 하는 순서가 아니라면, 맨 뒤로 이동
            q.push(q.front());
            q.pop();
        }
    }
    
    
    return answer;
}


int main(){
    
    
    return 0;
}
