#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;


// F = G*m1*m2/(d*d), G는 양의 상수 값
int main(){
    int test_case;
    int T, N;
    double result = 0;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        double x[N], m[N];

        // input x-position
        for(int i=0; i<N; i++){
            cin >> x[i];
        }
        // input x-weight
        for(int i=0; i<N; i++){
            cin >> m[i];
        }
        // 이분 탐색
        cout.precision(10);
        cout <<"#" << test_case ;

        double left, right;
        for(int i=0; i< N-1; i++){
            
            left = x[i];
            right = x[i+1];
            double result = 0;
            
            for(int j= 0; j<50; j++){
                double sum = 0;
                double mid = (left + right)/2.0;
                
                // F = G*m1*m2/(d*d), G는 양의 상수 값
                // left
                for(int k=0; k<= i; k++){
                    sum += (m[k] / ((mid - x[k])*(mid - x[k])));
                }
                for(int k = i+1; k<N; k++){
                    sum -= ( m[k] / ((mid - x[k])* (mid - x[k])));
                }
                
                if(sum > 0){
                    // 오른쪽 값이 더 크기때문에, 왼쪽기준을 오른쪽으로 옮겨준다.
                    left = mid;
                }
                else{
                    // 0 이 되면 균형점 ,
                    right = mid;
                    result = mid;
                }
            }
            // 소수점 아래 10자리까지 출력.
            printf(" %.10lf", result);
        }
        cout <<'\n';
            
    }
    return 0;
}
