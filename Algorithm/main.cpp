#include <string>
#include <algorithm>
#include<iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T, N, M;
    
    string numberType[10] = {"0001101", "0011001", "0010011", "0111101",
        "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"};
    
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d", &N,  &M);
        int arr[N][M] ;
        string answer = "";
        int flag= 0;
        // input
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                scanf("%1d", &arr[i][j]);
            }
        }
        for(int i = 0; i<N; i++){
            for(int j=M-1; j>0; j--){
                
                if(arr[i][j] != 1) continue;
                
                // 1일 때, 7개 자리수에 대한 유형을 파악한다. ( 뒤에서 부터)
                
                // 여기서 56개를 7개씩 끊어서 검사해야한다.
                for(int num = j; num > j-56; num-= 7){
            
                    string type ="";
                    for(int k=num; k > num-7; k--){
                        type += to_string(arr[i][k]);
                    }
                    reverse(type.begin(),  type.end());
                
                    for(int l = 0; l<10; l++){
                        if(numberType[l] == type){
                            answer += to_string(l);
                            break;
                        }
                    }
                }
                reverse(answer.begin(), answer.end());
                flag = 1;
                break;
            }
            
            if(flag == 1){
                break;
            }
        }

        if(flag == 1){
            int num1=0, num2= 0;
            int tmpResult = 0;

            for(int i=0; i<answer.size(); i++){
                
                if(i%2 ==0){
                    num1+=  (answer[i]-'0');
                }
                else{
                    num2+= (answer[i]-'0');
                }
            }
            tmpResult = num1 + num2;
            num1 = num1 * 3;
            num1 += num2;
            
            int tmp = num1;
            
            // 잘못된 코드
            if(tmp % 10 !=0){
                cout <<"#" << test_case << " 0\n";
            }
            else{
                cout <<"#" << test_case << " " <<  tmpResult <<"\n";
            }
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
