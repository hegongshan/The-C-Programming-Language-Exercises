### 第2章 类型、运算符与表达式

#### 练习2-1

编写一个程序以确定分别由signed和unsigned限定的char、short、int与long类型变量的取值范围。采用打印标准头文件中的相应值以及直接计算两种方式实现。后一种方法的实现较困难一些，因为要确定各种浮点类型的取值范围。

[exercise2-1.c](./code/exercise2-1.c)

```c
#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    // 1.使用标准头文件
    printf("signed char value in the range [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char max = %u\n", UCHAR_MAX);

    printf("signed short value in the range [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short max = %u\n", USHRT_MAX);

    printf("signed int value in the range [%d, %d]\n", INT_MIN, INT_MAX);
    printf("unsigned int max = %u\n", UINT_MAX);

    printf("signed long value in the range[%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned long %lu\n\n", ULONG_MAX);


    // 2.直接计算
    printf("signed char value in the range [%d, %d]\n", (char)~((unsigned char) ~0 >> 1), (char)((unsigned char) ~0 >> 1));
    printf("unsigned char max = %u\n", (unsigned char) ~0);

    printf("signed short value in the range [%d, %d]\n", (short)~((unsigned short) ~0 >> 1), (short)((unsigned short) ~0 >> 1));
    printf("unsigned short max = %u\n", (unsigned short) ~0);

    printf("signed int value in the range [%d, %d]\n", (int)~((unsigned int) ~0 >> 1), (int)((unsigned int) ~0 >> 1));
    printf("unsigned int max = %u\n", (unsigned int) ~0);

    printf("signed long value in the range [%ld, %ld]\n", (long)~((unsigned long) ~0 >> 1), (long)((unsigned long) ~0 >> 1));
    printf("unsigned long %lu\n", (unsigned long) ~0);

    return 0;
}
```

