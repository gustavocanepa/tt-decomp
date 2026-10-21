/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;
struct RefCounter;
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);
extern "C" s64 func_004A5A30(void);

extern "C" void adhoc__GetMicroSecond(s32 *arg0) {
    s32 buf[4];
    s32 v;
    func_0029EA18(buf, (s32)((func_004A5A30() & 0xFFFFFFFFL) + (s64)(s32)0x80000001));
    if (arg0 != buf) {
        v = buf[0];
        if (v != 0) {
            func_002C0FE8((RefCounter *)v);
        }
        s32 old = *arg0;
        if (old != 0) {
            func_002C1050((RefCounter *)old);
        }
        *arg0 = v;
    }
    func_0029CEF0(buf, 2);
}
