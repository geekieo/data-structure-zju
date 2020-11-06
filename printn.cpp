/*空间复杂度的影响*/
#include <stdio.h>

//循环
void PrintN(int N){
    int i;
    for(i=0; i<N; i++){
        printf("%d ", i);
    }
    return;
}

//递归
void PrintNRec(int N){
    if(N){
        PrintNRec(N-1);
        printf("%d ", N);
    }
    return;
}

int main(){
    int N;
    scanf("%d", &N);
    PrintN(N);
    PrintNRec(N);
}