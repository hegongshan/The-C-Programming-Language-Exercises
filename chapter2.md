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
    printf("signed char value in the range [%d, %d]\n", (char) ~((unsigned char) ~0 >> 1), (char)((unsigned char) ~0 >> 1));
    printf("unsigned char max = %u\n", (unsigned char) ~0);

    printf("signed short value in the range [%d, %d]\n", (short) ~((unsigned short) ~0 >> 1), (short)((unsigned short) ~0 >> 1));
    printf("unsigned short max = %u\n", (unsigned short) ~0);

    printf("signed int value in the range [%d, %d]\n", (int) ~((unsigned int) ~0 >> 1), (int)((unsigned int) ~0 >> 1));
    printf("unsigned int max = %u\n", (unsigned int) ~0);

    printf("signed long value in the range [%ld, %ld]\n", (long) ~((unsigned long) ~0 >> 1), (long)((unsigned long) ~0 >> 1));
    printf("unsigned long %lu\n", (unsigned long) ~0);

    return 0;
}
```

#### 练习2-2

在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句。

原始的for循环如下所示：

```c
for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
```

修改后：

```c
int i = 0;
while (i < lim - 1)
{
    if ((c = getchar()) == '\n')
        break;
    if (c == EOF)
        break;
    s[i++] = c;
}   
```

#### 练习2-3

编写函数htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀0x或0X）转换为与之等价的整型值。字符串中允许包含的数字包括：0-9、a-f以及A-F。

[exercise2-3.c](./code/exercise2-3.c)

```c
int htoi(char const s[])
{
    int i = 0;
    int n = 0;
    int base = 16;

    // 处理可选的前缀0x或者0X
    if (s[i] == '0') {
        i++;
        if (s[i] == 'x' || s[i] == 'X') {
            i++;
        }
    }
    
    // 参照K&R P33 atoi函数
    int valid = 1;
    while (valid && s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            n = base * n + s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            n = base * n + s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            n = base * n + s[i] - 'A' + 10;
        } else {
            valid = 0;
        }
        i++;
    }
    return n;
}
```

