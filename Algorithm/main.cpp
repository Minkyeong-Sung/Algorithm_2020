#include <string>
#include <vector>
#include <queue>

using namespace std;

// 다리 길이는 bridge_length,  다리는 무게 weight
int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int time = 0;
    int sumTruct = 0;
    int idx = 0;
    queue<int> q;
    
    while(1){
        // 시간은 계속 가는 것을 인지
        time++;
        
        // 트럭이 다리를 지나가면, 전체 다리에 있는 트럭 무게를 뺴준다.
        if(q.size() == bridge_length){
            sumTruct -= q.front();
            q.pop();
        }
        
        if( truck_weights[idx] +  sumTruct   <= weight ){
            
            // 마지막 트럭까지 삽입하고 나면 종료
            if(idx == truck_weights.size()-1){
                // 마지막 트럭이 다리를 통과하는 시간 = 다리길이만큼만 더해주면 된다
                time += bridge_length;
                break;
            }
            
            q.push(truck_weights[idx]);
            sumTruct += truck_weights[idx];
            idx ++;
        }
        else{
            // 트럭의 무게가 다리무게를 초과한다면, 트럭을 출발점으로 이동한다
            q.push(0);
        }
    }
    return time;
}

int main(){
    
    
    return 0;
}
