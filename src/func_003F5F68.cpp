typedef int s32;
typedef signed char s8;
extern "C" void func_004A6500(int, int, ...);
extern "C" s32 func_004A8368(const char *);
extern "C" void func_004F8588(void *, void *, s32) throw();
extern char D_005F96A0[];

extern "C" void func_003F5F68(s32 value, s8 *buf, s32 size) {
    s8 tmp[0x80];
    func_004A6500((int)buf, (int)D_005F96A0, value);
    s32 n = func_004A8368((const char *)buf);
    s32 pos = 0x3E;
    s32 idx = n - 1;
    tmp[0x3F] = 0;
    s32 i = 0;
    if (n > 0) {
        do {
            i++;
            s32 ch = buf[idx--];
            tmp[pos--] = ch;
            if (i % 3 == 0 && i < n)
                tmp[pos--] = ',';
        } while (i < n);
    }
    func_004F8588(buf, tmp + pos + 1, size);
}
