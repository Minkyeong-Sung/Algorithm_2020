#include <iostream>

using namespace std;

int main(){
    
    string inputA, inputB;
    cin >>inputA >> inputB;
    
    int arrA[53];
    
    memset(arrA, 0, sizeof(arrA));
    
    for(int i=0; i<inputA.size(); i++){
        // 대문자 A(65)-Z(90)
        if(inputA[i] >= 65 && inputA[i] <= 90){
            arrA[inputA[i] - 64] ++;
        }
        // 소문자 a(97)-z(102)
        else{
            arrA[inputA[i] - 70] ++;
        }
    }
    
    // 모든 문자열 구성이 같다면, 해당 배열의 총 합은 0으로 수렴.
    for(int i=0; i<inputB.size(); i++){
        // 대문자 A(65)-Z(90)
        if(inputB[i] >= 65 && inputB[i] <= 90){
            arrA[inputB[i] - 64] --;
        }
        // 소문자 a(97)-z(102)
        else{
            arrA[inputB[i] - 70] --;
        }
    }
    
    for(int i=0; i< 53; i++){
        if(arrA[i] != 0){
            cout << "NO\n";
            exit(0); // 시스템 종료
        }
    }
    
    cout <<"YES\n";
    
    
    return 0;
}
