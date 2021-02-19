#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;


// 크로그래머스 : 크레인 인형뽑기 게임
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    // 움직이는 횟수만큼 탐색한다.
    for(int i=0; i<moves.size(); i++){
        
        int position = moves[i] - 1; // 0 부터 시작해야 하기때문
        for(int j=0; j< board.size(); j++){
            
            // 한행씩 아래로 이동해야하기 떄문에 j 로 이동한다.
            if(board[j][position] != 0){
                
                if(!st.empty()  && st.top() == board[j][position]){
                    st.pop();
                    answer += 2;
                }
                else{
                    st.push(board[j][position]);
                }
                board[j][position] = 0;
                break;
            }
        }
    }
    
    return answer;
}



int main(){
    
    
    return 0;
}
