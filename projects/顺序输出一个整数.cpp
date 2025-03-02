#include <stdio.h>

void printDigits(int number) {


    int temp = number;


    int digits = 0;


    // 计算数字的位数


    while (temp != 0) {


        temp /= 10;


        digits++;


    }


    int divisor = 1;


    for (int i = 1; i < digits; i++) {


        divisor *= 10;


    }


    temp = number;


    for (int i = 0; i < digits; i++) {


        int digit = temp / divisor;


        printf("%d ", digit);


        temp %= divisor;


        divisor /= 10;


    }


}


int main() {


    int number = 12340;


    printDigits(number);


    return 0;


}
