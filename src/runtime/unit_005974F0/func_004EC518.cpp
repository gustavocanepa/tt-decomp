/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio overflow: writes one character into a FILE's output buffer, setting up the buffer on first use and flushing when it is full, unbuffered, or a newline on a line-buffered stream (glibc _IO_new_file_overflow). */
struct F {
    int flags; char *read_ptr; char *read_end; char *read_base;
    char *write_base; char *write_ptr; char *write_end; char *buf_base; char *buf_end;
};
extern "C" {
void func_004E5DA8(F *);
int func_004EC2C8(F *, char *, int) throw();
int *func_004F4F80(void);
}
int func_004EC518(F *f, int ch) {
    if (f->flags & 8) {
        f->flags |= 0x20;
        *func_004F4F80() = 9;
        return -1;
    }
    if ((f->flags & 0x800) == 0) {
        if (f->write_base == 0) {
            func_004E5DA8(f);
            f->read_end = f->read_ptr = f->read_base = f->buf_base;
        }
        if (f->read_ptr == f->buf_end)
            f->read_end = f->read_ptr = f->buf_base;
        f->write_ptr = f->read_ptr;
        f->write_base = f->write_ptr;
        f->write_end = f->buf_end;
        f->read_base = f->read_ptr = f->read_end;
        if (f->flags & 0x202) f->write_end = f->write_ptr;
        f->flags |= 0x800;
    }
    if (ch == -1) return func_004EC2C8(f, f->write_base, f->write_ptr - f->write_base);
    if (f->write_ptr == f->buf_end)
        if (func_004EC2C8(f, f->write_base, f->write_ptr - f->write_base) == -1) return -1;
    *f->write_ptr++ = ch;
    if ((f->flags & 2) || ((f->flags & 0x200) && ch == '\n'))
        if (func_004EC2C8(f, f->write_base, f->write_ptr - f->write_base) == -1) return -1;
    return (unsigned char)ch;
}
