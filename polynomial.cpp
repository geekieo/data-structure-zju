/*
多项式的两种计算方式
体现时间复杂度的影响
f(x) = a0 + a1*x^1 + a2*x^2 + a3*x^3 +...+ am*x^m + an*x^n
其中，m = n-1
*/
#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;
#define MAXN 50 /*被测函数多项式系数最大下标*/
#define MAXK 1e7 /*被测函数最大重复调用次数*/

/*直接各项累加，越往后项的次幂越大
param n 多项式最高次幂，多项式长度为n+1
param a[] 多项式系数
param x 多项式未知数x
*/
double f1(int n, double a[], double x){
    int i;
    double p = a[0];
    for( i = 1; i <=n; i++ ){
        p += (a[i] * pow(x,i)); //每次运行i-1次乘法,总共(n^2+n)/2次乘法
    }                           //T(n)=C1*n^2+C2*n
    return p;
}

/*多项式采用合并同类项，大大降低乘法次数，从而降低时间复杂度
f(x) = a0 + x*(a1 + x*(a2 + x*(a3 + x*(...am+(x*an)))))
param n 多项式最高次幂，多项式长度为n+1
param a[] 多项式系数
param x 多项式未知数x
*/
double f2(int n, double a[], double x){
    int i;
    double p = a[n]; //
    for (i = n; i> 0; i--){
        p = a[i-1] + x*p;   //每次运行1次乘法,总共n次乘法
    }                       //T(n)=C*n
    return p;
}

void cal_duration(int n, double a[], double x, double (*f)(int, double[], double),char funcname[64]){
    start = clock();
    /*重复运行充分多次，放大运算时间，防止时间太短不显示。每次运算时间可取平均。*/
    for (int i =0; i<MAXK; i++)
        (*f)(n, a, x);
    stop = clock();
    duration =((double)(stop-start))/CLOCKS_PER_SEC;
    printf("%s ticks = %f\n",funcname, (double)(stop-start));
    printf("duration = %6.2e\n", duration);
}

int main(){
    int i;
    double a[MAXN] = {1.0}; /*多项式系数*/
    for(i=0; i<MAXN; i++) a[i]=(double)i;
    cal_duration(MAXN-1, a, 1.1, f1,"f1");
    cal_duration(MAXN-1, a, 1.1, f2,"f2");
}
/* output
f1 ticks = 8410276.000000
duration = 8.41e+00
f2 ticks = 1362730.000000
duration = 1.36e+00
*/