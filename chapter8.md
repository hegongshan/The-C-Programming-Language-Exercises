### Unix系统接口

#### 练习8-1

用read、write、open和close系统调用代替标准库中功能等价的函数，重写第7章的cat程序，并通过实验比较两个版本的相对执行速度。

第7章的cat程序如下所示：

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];

    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

/* 将文件ifp复制到文件ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}
```

实现代码如下：

[exercise8-1.c](./code/exercise8-1.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

void filecopy(int, int);
void error(char *, ...);

int main(int argc, char *argv[])
{
    int fd;

    if (argc == 1) {
        filecopy(0, 1);
    } else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY, 0)) < 0) {
                error("cat: can't open %s\n", *argv);
                exit(1);
            } else {
                filecopy(fd, 1);
                close(fd);
            }
        }
    }

    exit(0);
}

/* 将文件ifd复制到文件ofd */
void filecopy(int ifd, int ofd)
{
    char buf[2048];
    int n;
    while ((n = read(ifd, buf, sizeof(buf))) > 0) {
        if(write(ofd, buf, n) != n) {
            error("cat: write error");
        }
    }
}

/* 打印一个出错信息，然后终止 */
void error(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}
```

