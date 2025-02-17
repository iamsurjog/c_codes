#include <stdio.h>

long karatsuba(long x, long y);
long power(int n);

int main(){
    long x;
    long y;
    scanf("%ld %ld", &x, &y);
    long result = karatsuba(x, y);
}

long power(int n){
    long result = 1;
    for(int i = 0; i<n; i++){
        result*=10;
    }
    return result;
}

long karatsuba(long x, long y){
    int size = 0;
    if(x<10 || y<10){
        return x*y;
    }
    long temp_x = x;
    long temp_y = y;
    while(temp_x>0 || temp_y>0){
        size++;
        temp_x /= 10;
        temp_y /= 10;
    }
    // if(size == 1){
    //     return x*y;
    // }
    int half = size/2 + size%2;
    long divisor = power(half);
    
    // x = ab
    long a = x/divisor;
    long b = x%divisor;
    
    // y = cd
    long c = y/divisor;
    long d = y%divisor;
    
    long ac = karatsuba(a, c);
    long bd = karatsuba(b, d);
    long mid = karatsuba((a+b), (c+d)) - ac - bd;
    long result = ac * power(size) + mid*divisor + bd;
    return result;
}