#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int alpha[26] ;
int calculation(vector<string> &vt, vector<char> &letter, vector<int> &mapping){
    
    int m = letter.size();
    int sum = 0;
    
    for(int i=0; i< m; i++ ){
        alpha[ letter[i] - 65]  = mapping[i];
    }
    
    for(string s : vt){
        
        int now=0;
        for(char x : s){
            now = now * 10 +  alpha[x-65] ;
        }
        
        sum += now;
    }
    
    return sum;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<string> vt(n);
    vector<char> letter;
    
    for(int i=0; i<n; i++){
        cin >> vt[i];
        
        for(char x : vt[i]){
            letter.push_back(x);
        }
    }
    
    sort(letter.begin(), letter.end());
    letter.erase( unique(letter.begin(), letter.end()), letter.end());
    
    int m = letter.size();
    vector<int> mapping;
    
    // 몇개의 숫자까지 돌아볼지 확인할 것
    for(int i=9; i> 9-m; i--){
        mapping.push_back(i);
    }
    
    // 다음 순열 사용을 위해 정렬 한다.
    sort(mapping.begin(), mapping.end());
    
    int answer = 0;
    
    do {
        //
        int tmp = calculation(vt, letter, mapping);
        
        if(answer < tmp){
            answer = tmp;
        }
        
    } while ( next_permutation(mapping.begin(), mapping.end()));
    
    cout << answer;
    
    
    return 0;
}
