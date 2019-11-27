#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ptrace.h>

void error(char *fmt, ...);
void filecopy(int, int);

int main(int argc, const char *argv[])
{
    int ifp;
    int ofp;

    ptrace(PTRACE_TRACEME);
    if (argc < 3 || argc > 3)
        error("usage: copy [FILE1] [FILE2]");
    else
	while (--argc > 1) {
	    if ((ifp = open(*++argv, O_RDONLY)) == -1)
                error("copy: cannot open %s", *argv);
            if ((ofp = creat(*++argv, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR)) == -1)
                if (unlink(*argv) == -1)
                    error("copy: cannot overwrite %s", *argv);
            filecopy(ifp, ofp);
        }
    exit(0);
}

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

void filecopy(int ifp, int ofp)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifp, buf, BUFSIZ)) > 0)
	if (write(ofp, buf, n) != n)
            error("copy: write error");
}
