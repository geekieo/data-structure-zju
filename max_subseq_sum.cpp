/*
返回数列中和最大的子数列。
只要子数列和为正，加入左右子数列的就能使和增长。子数列和为负就丢弃。
*/
#include <stdio.h>

struct Result{int max_sum; int head; int tail;};

Result max_subseq_sum(int seq[], int length) {
    int now_sum = 0;
    int max_sum = 0;
    int prehead = -1;
    int tail = 0;
    for(int i = 0; i < length; i++){
        now_sum += seq[i];
        if (now_sum > max_sum){
            max_sum = now_sum;
            tail = i;
        }else if (now_sum < 0){
            now_sum = 0;    
            prehead = i;    //舍弃到此为止的子数列
        }
    }
    int head = prehead + 1;
    Result result ={max_sum, head,tail};
    return result;
}

int main(){
    int list[] = {-1, 4,-3, 5,-2,-1, 2, 6,-2}; //数列无零，有零需考虑边界
    int length = 8;
    Result result = max_subseq_sum(list,length);
    printf("max_sum:%d, head:%d, tail:%d\n",result.max_sum,result.head,result.tail);
}