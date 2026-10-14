/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct RefCounter;
struct P20 { char pad[0x20]; s32 unk20; };
extern "C" void func_00151A90(void *, int);
extern "C" void func_001563C8(void *, s32);
extern "C" void func_001564E0(void *, int) throw();
extern "C" s32 func_00156538(void *, s32) throw();
extern "C" s32 func_00198B00(s32, s32);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029CF48(void *, s32);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_002C0FE8(RefCounter *);
extern "C" void func_002C1050(RefCounter *);

extern "C" void MMemoryCardManager__getFile(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 b0[4];
    P20 *b1[4];
    s32 b2[4];
    if (arg2 > 0) {
        func_0029CF48(b0, arg3);
        P20 **p1 = b1;
        func_00156538(p1, arg1);
        s32 s0 = (*p1)->unk20;
        s32 v = func_00198B00(s0, func_0029E9F0(b0[0]));
        if (v != 0) {
            s32 *p2 = b2;
            func_001563C8(p2, v);
            if (arg0 != p2) {
                s32 n = *p2;
                if (n != 0) {
                    func_002C0FE8((RefCounter *)n);
                }
                s32 old = *arg0;
                if (old != 0) {
                    func_002C1050((RefCounter *)old);
                }
                *arg0 = n;
            }
            func_00151A90(p2, 2);
        }
        func_001564E0(p1, 2);
        func_0029CEF0(b0, 2);
    }
}
