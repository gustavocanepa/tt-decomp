/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req { u8 type; char pad[3]; s32 m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern "C" s32 func_004D6538(Req *, s32);
extern "C" s32 func_004D9E40(s32);
extern "C" s32 func_004FD2D0(const char *, ...);
extern char D_00613C38[];

extern "C" s32 func_004D6130(s32 a, s32 b, s32 c, s32 d) {
    Req r;
    s32 x = func_004D9E40((s32)__builtin_return_address(0));
    if (x >= 0 && a == x) {
        func_004FD2D0(D_00613C38);
        while (1)
            ;
    }
    r.type = 7;
    r.m4 = a;
    r.mC = 0;
    r.m20 = b;
    r.m24 = c;
    r.m28 = d;
    return func_004D6538(&r, 1);
}
