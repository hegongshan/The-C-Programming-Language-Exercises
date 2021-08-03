### 练习4-14

定义宏swap(t, x, y)以交换t类型的两个参数。（使用程序块结构会对你有所帮助。）

[代码文件](./code/exercise4-14.c)

```c
#include <stdio.h>

#define swap(t, x, y) {t temp = x; x = y; y = temp;}

int main()
{
    int a = 20;
    int b = 10;
    printf("before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("after swap: a = %d, b = %d\n", a, b);
    return 0;
}
```

