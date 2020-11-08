#include <stdio.h>

/* 复杂度分析
最坏:S(n) = n; T(n) = log2(n);
最好:S(n) = n; T(n) = 1;
*/
int binary_search(int list[], int head, int tail, int target){
    while (head < tail){
        int mid = (int)(tail - head)/2 + head;
        if(list[mid] == target){
            return mid;
        }
        if(list[mid] > target){
            tail = mid;
        }
        else{
            head = mid;
        }
    }
    return -1;
}

int main(){
    int list[] = {0,1,2,3,4,5,6,7,8,9};
    int head = 0;
    int tail = 10;
    int target =3;
    int index = binary_search(list, head, tail, target);
    printf("%d索引是%d \n", target, index);
    return 0;
}