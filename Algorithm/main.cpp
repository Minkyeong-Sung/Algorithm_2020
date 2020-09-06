#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/*
 프로그래머스 : 소수 만들기
 */


int ans = 0;
bool prime[5000] ;


// Check is Prime.
void isPrime(int result){
 
    if(prime[result] == false){
        ans += 1;
    }
}

// Calculate nC3 result
void combination(int nums[], int index, int r, int result, size_t n){
    
    if(r == 0){
        printf("result : %d\n", result);
        isPrime(result);
        return;
    }
    
    if(index > n) return;
    
    combination(nums, index + 1, r-1, result + nums[index], n);
    combination(nums, index +1, r, result, n);
}


// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    
    memset(prime, false, sizeof(prime));
    
    for(int i=2; i< 5000; i++){
        if(prime[i]== false){
            for(int j= i*2; j< 5000; j+= i){
                prime[j] = true;
            }
        }
    }
    
    // combination
    combination(nums, 0, 3, 0, nums_len-1);

    return ans;
}


// temp main source
int main(){
    
    
    int nums[5] = {1,2,7,6,4};
    
    solution(nums, 4);
    
    printf("%d", ans);
}
