/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VT { short adj; short pad2; int (*fn)(void *); };
struct Obj { VT *vt; };
struct Sentry { int pad0; int val; unsigned char *cur; char pad1[0x30 - 0xC - 0x10 + 0x10 - 0x10 - 0xC]; };
struct Sen { int pad0; int val; unsigned char *cur; char pad1[0x30 - 0xC - 0x20]; };
struct SI { int pad0; int val; unsigned char *cur; char pad2[0x14]; unsigned char flag; char pad3[0xF]; };
extern "C" void func_0047A9B8(SI *, int) throw();
extern "C" void func_0047AA68(SI *, Obj *, int) throw();
extern "C" void func_0047AAD0(SI *, int) throw();
extern "C" int func_0047ABF8(SI *, char *, int) throw();
extern "C" void func_0047AEB0(SI *, char *, int, int *) throw();
extern "C" void func_0047B3B0(void *) throw();
extern "C" void func_0047B3D8(void *, Obj *, int, int, int) throw();
extern "C" void func_0047B950(SI *, Obj *, int, char *);

extern "C" void *func_0047BAB8(void *arg0, Obj *arg1, int arg2, char *arg3) {
    char buf[4];
    SI si;
    int cnt;
    int s2, s3;
    if (arg2 == 1 && (arg3 == 0 || *arg3 == 0)) {
        s3 = 1;
    } else {
        func_0047B950(&si, arg1, arg2, arg3);
        s3 = si.val;
        if ((unsigned char)(si.flag & 1) == 0) {
            func_0047B3B0(arg0);
            goto done;
        }
    }
    {
    VT *vt = (VT *)((char *)arg1->vt + 0x18);
    buf[0] = s3 >> 24;
    buf[1] = s3 >> 16;
    buf[2] = s3 >> 8;
    buf[3] = s3;
    s2 = 0;
    int r = vt->fn((char *)arg1 + vt->adj);
    func_0047AA68(&si, arg1, r);
    while ((si.cur[0] | (si.cur[1] << 8)) == 1) {
        s2 = func_0047ABF8(&si, buf, 4);
        func_0047AAD0(&si, s2);
    }
    cnt = 0;
    func_0047AEB0(&si, buf, 4, &cnt);
    func_0047B3D8(arg0, arg1, s2, cnt, s3);
    func_0047A9B8(&si, 2);
    }
done:
    return arg0;
}
