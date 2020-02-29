//
// Created by sugus chan on 2020-02-23.
//
//1.00000
//-2147483648
#include <iostream>
double pow(double x, long long int n ) {
    if (n == 0) { return 1; }//注意终止条件！！
    if (n == 1) { return x; }
    //可以把pow这种运算提前！ 如果不进行分半运算就仍然是相当于n个x相乘了！
    if (n % 2 == 0) {
        double half = pow(x, n / 2);
        return half * half;
    } else {
        double half = pow(x, (n - 1) / 2);
        return x * half * half;
    }
}
double myPow(double x, int n) {
    double X =x;
    long long N = n;//非常有用的
    if(n<0){
        X = 1/x ;
        N = -N ;//interesting : [-21474...8,+21474...7] in the neg end
    }
    return pow(X , N);
}

int main(){
    double x ;
    int n ;
    std::cin >> x ;
    std::cin >> n ;
    std::cout << myPow(x,n);
    return 0 ;
}