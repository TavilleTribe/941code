#include <stdio.h>


//原码：是最简单的机器数表示法，用最高位表示符号位，其他位存放该数的二进制的绝对值。
//反码：正数的反码和原码一致；负数的反码就是它的原码除符号位外，按位取反。
//补码：正数的原码、反码、补码都一致；负数的补码等于反码+1。

//& 与 两个位都为1时，结果才为1
//| 或 两个位都为0时，结果才为0
//^ 异或 两个位相同为0，相异为1
//~ 取反 0变为1，1变为0
//<< 左移 各二进位全部左移若干位，高位丢弃，低位补0(与右移反过来，使原数乘以2的n次方) 
//>> 右移 各二进位全部右移若干位，高位补0或符号位补齐(规律为：源操作数 / 2的N次方（N取决于移动的位数） = 移动后的结果(只取整数部分)) 
int main() {
	int i = -1;
	printf("%d",~i+1);
}

