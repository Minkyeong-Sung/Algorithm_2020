#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/*
 N개의 최소공배수 구하기
 
 */

// calculate GCD(최대공약수)
int gcd(int num1, int num2){
    
    if(num2 ==0){
        return num1;
    }
    else{
        return gcd(num2, num1 % num2);
    }
}


// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {

    int lcm = (arr[0] * arr[1] ) / gcd(arr[0], arr[1]);
    
    for(int i=2; i<arr_len; i++){
        lcm = lcm * arr[i] / gcd(lcm, arr[i]);
    }
    return lcm;
}


// 테스트용 
int main(){
    
    int arr[3]  ={2,3,4};
    printf("%d", solution(arr, 3));
    
    
}
