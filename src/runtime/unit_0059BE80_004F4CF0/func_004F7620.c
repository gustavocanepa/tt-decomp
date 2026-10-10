/* compiler: ee-gcc2.96-no-strict-aliasing */
/* newlib 1.9.0 libc/reent (closer.c / unlinkr.c pattern): a one-argument _xxx_r reentrant
   syscall wrapper; the file has no notice of its own (COPYING.NEWLIB section 9, THIRD_PARTY.md). */
struct _reent {
    int _errno;
};

extern int D_0061BA48; /* errno */
extern int func_004FAF20(int fd);

int func_004F7620(struct _reent *ptr, int fd) {
    int ret;

    D_0061BA48 = 0;
    if ((ret = func_004FAF20(fd)) == -1 && D_0061BA48 != 0)
        ptr->_errno = D_0061BA48;
    return ret;
}
