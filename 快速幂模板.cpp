#include <stdio.h>

long long fastPower(long long a,long long n,long long mod) {
    long long result = 1;
    //记住，快速幂一般都有这步缩小运算结果的计算，因为可能数会很大
	//再加上本题的 a的b次方求模p 这种题要切记，在原数无论求模多少次，结果依旧不受影响 
    a %= mod; 
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % mod;
            //奇数一定会做两次这个操作，循环一开始那次和最后一次循环那次。相当于将比偶数多乘了一次a 
            //缩小规模 
        }
        a  = (a * a) % mod;
        //缩小规模 
        n >>= 1;
    }
    return result % mod;
}

int main() {
    long long a,n,mod;
    scanf("%lld %lld %lld",&a,&n,&mod);
    printf("%lld",fastPower(a,n,mod));
}
