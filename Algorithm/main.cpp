#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];
int data[101];

void divide(int l, int r){
    int p1, p2, p3;
    if(l<r){
        // divide
        int mid = (l + r)/2;
        
        divide(l, mid);
        divide(mid + 1, r);
        
        // merge
        // 비교한 값을 담기 위해 선언한 포인터
        p1 = l;
        p2 = mid+1;
        p3 = l;
        
        while(p1 <= mid &&  p2 <= r){
            if(arr[p1] < arr[p2]){
                data[p3++] = arr[p1++];
            }
            else{
                data[p3++] = arr[p2++];
            }
        }
        // 왼쪽 나머지
        while(p1 <= mid){
            data[p3++] = arr[p1++];
        }
        // 오른쪽 나머지
        while(p2<= r){
            data[p3++] = arr[p2++];
        }
        
        // 재 정렬 완료 된 배열
        for(int i = l ; i<= r; i++){
            arr[i] = data[i];
        }
    }
}

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    divide(1, n);
    
    for(int i=1; i<=n; i++){
        cout << arr[i];
    }
    
    return 0;
}
