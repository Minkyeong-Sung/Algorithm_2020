#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> speed, process;
    
    // queue 로 옮기기
    for(int i=0; i<progresses.size(); i++){
        process.push(progresses[i]);
        speed.push(speeds[i]);
    }
    
    int day = 1;
    
    // 하나씩 큐로 비교하며 효율 100 을 넘었는지 본다.
    while(!process.empty()){
        int size= process.size();
        int finishCnt = 0;

        for(int i=0; i<size; i++){
            
            //
            if((process.front() + (speed.front() * day)) >= 100){
                finishCnt ++;
                process.pop();
                speed.pop();
            }
        }
        
        if(finishCnt != 0){
            answer.push_back(finishCnt);
        }
        day++;
    }
    return answer;
}

