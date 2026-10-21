struct FILE { unsigned char *p; int r; };
struct Buf { char pad[0x58]; FILE *fp; };
extern "C" int func_004F75C0(FILE *fp) throw();
extern "C" unsigned int func_004F5738(char *buf, unsigned int size, unsigned int n, FILE *fp) throw();

extern "C" unsigned long stdiobuf__virtual_12(Buf *self, char *buf, long n) {
    if (n == 1) {
        FILE *fp = self->fp;
        int c;
        if (--fp->r < 0)
            c = func_004F75C0(fp);
        else
            c = *fp->p++;
        if (c == -1)
            return 0;
        *buf = c;
        return 1;
    }
    return func_004F5738(buf, 1, n, self->fp);
}
