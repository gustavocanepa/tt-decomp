typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct File {
    char p0[0xC];
    s16 flags;              /* 0x0C */
    s16 file;               /* 0x0E */
    char p1[0xC];           /* 0x10-0x1B */
    struct File *cookie;    /* 0x1C */
    void (*f_read)(void);   /* 0x20 */
    void (*f_write)(void);  /* 0x24 */
    void (*f_seek)(void);   /* 0x28 */
    void (*f_close)(void);  /* 0x2C */
    char p2[0x24];          /* 0x30-0x53 */
    void *data;             /* 0x54 */
};

extern "C" s32 func_004FA010(void *ptr, const char *mode, s32 *optr);
extern "C" struct File *func_004F5380(void *ptr);
extern "C" s32 func_004F6738(void *ptr, const char *file, s32 oflags, s32 mode);
extern "C" void func_004F77E8(void);
extern "C" void func_004F7850(void);
extern "C" void func_004F78D0(void);
extern "C" void func_004F7938(void);
extern "C" void func_004F5858(struct File *fp, s32 buf, s32 mode);

extern "C" struct File *func_004F5548(void *ptr, const char *file, const char *mode) {
    s32 buf[4];
    s32 flags;
    struct File *fp;
    s32 r;
    s32 a4;

    flags = func_004FA010(ptr, mode, buf);
    if (flags == 0) {
        return 0;
    }
    fp = func_004F5380(ptr);
    if (fp == 0) {
        return 0;
    }
    r = func_004F6738(fp->data, file, buf[0], 0x1B6);
    a4 = flags & 0x100;
    if (r < 0) {
        fp->flags = 0;
        return 0;
    }
    fp->file = r;
    fp->f_read = func_004F77E8;
    fp->f_write = func_004F7850;
    fp->f_seek = func_004F78D0;
    fp->f_close = func_004F7938;
    fp->flags = flags;
    fp->cookie = fp;
    if (a4 != 0) {
        func_004F5858(fp, 0, 2);
    }
    return fp;
}
