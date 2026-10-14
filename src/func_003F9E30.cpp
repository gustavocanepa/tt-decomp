typedef int s32;
typedef long s64;
typedef unsigned char u8;
typedef unsigned short u16;
struct B32 { char x[32]; };
struct Rec { s32 a; u16 b; u8 c; u8 d; s64 e; B32 data; };
struct Tmp { u16 h; u8 c; u8 d; };
extern "C" int func_003F9D48(void *, void *);
extern "C" s64 func_004B6658(void);
extern "C" void func_004AF960(void *, s64);
extern "C" s64 func_0040FB40(s32);
extern "C" void func_003F9BF8(void *, Rec *, int);

extern "C" s32 func_003F9E30(void *list, s32 key, s32 arg2, B32 *src) {
    int idx = func_003F9D48(list, (void *)key);
    if (idx < 0) return 0;
    Rec r;
    Tmp t;
    r.a = key;
    func_004AF960(&t, func_004B6658());
    r.b = t.h;
    r.c = t.c;
    r.d = t.d;
    r.e = func_0040FB40(arg2);
    r.data = *src;
    func_003F9BF8(list, &r, idx);
    return 1;
}
