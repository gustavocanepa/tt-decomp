/* compiler: ee-gcc2.96-no-strict-aliasing */
/* newlib 1.9.0 libc/reent (openr.c / execr.c pattern): a three-argument _xxx_r reentrant syscall
   wrapper with an int result; the file has no notice of its own (COPYING.NEWLIB section 9). */
struct _reent {
    int _errno;
};

extern int D_0061BA48; /* errno */
extern int func_004FAF18(int a, void *b, int c);

int func_004FA0C8(struct _reent *ptr, int a, void *b, int c) {
    int ret;

    D_0061BA48 = 0;
    if ((ret = func_004FAF18(a, b, c)) == -1 && D_0061BA48 != 0)
        ptr->_errno = D_0061BA48;
    return ret;
}
