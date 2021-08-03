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