/* compiler: ee-gcc2.96-no-strict-aliasing */
/* newlib 1.9.0 libc/reent (fstatr.c / statr.c / linkr.c pattern): a two-argument _xxx_r reentrant
   syscall wrapper; the file has no notice of its own (COPYING.NEWLIB section 9, THIRD_PARTY.md). */
struct _reent {
    int _errno;
};

extern int D_0061BA48; /* errno */
extern int func_004FAFD8(void *a, int b);

int func_004F5D08(struct _reent *ptr, void *a, int b) {
    int ret;

    D_0061BA48 = 0;
    if ((ret = func_004FAFD8(a, b)) == -1 && D_0061BA48 != 0)
        ptr->_errno = D_0061BA48;
    return ret;
}
