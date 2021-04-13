#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int n, i, j, pos;
    cin >> n;
    
    vector<int> input(n+1), output(n+1);
    for( i=1; i<= n; i++){
        cin >> input[i];
    }
    
    for( i = n; i> 0 ; i--){
        pos = i;
        // input배열의 크기만큼 앞으로 한칸씩 당기기
        for( j= 1; j<= input[i]; j++){
            output[pos]= output[pos+1];
            pos++;
        }
        output[pos] = i;
    }
    
    for(i=1; i<= n; i++){
        cout << output[i] << ' ' ;
    }
    
    return 0;
}
