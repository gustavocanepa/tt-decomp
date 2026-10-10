/* compiler: ee-gcc2.96-no-strict-aliasing */
/* newlib 1.9.0 libc/reent/readr.c or writer.c (_read_r / _write_r, `long ret` = 64-bit long in this
   build); the file has no notice of its own (COPYING.NEWLIB section 9, THIRD_PARTY.md). */
struct _reent {
    int _errno;
};

extern int D_0061BA48; /* errno */
extern int func_004FAE68(int fd, void *buf, unsigned int cnt);

long func_004FA128(struct _reent *ptr, int fd, void *buf, unsigned int cnt) {
    long ret;

    D_0061BA48 = 0;
    if ((ret = func_004FAE68(fd, buf, cnt)) == -1 && D_0061BA48 != 0)
        ptr->_errno = D_0061BA48;
    return ret;
}
