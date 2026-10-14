typedef long long s64;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

extern "C" s32 func_003F9DC8(char *arg0, float arg1);
extern "C" s64 func_0040FB40(void *arg0);
extern "C" s64 func_004B6658();
extern "C" void func_004AF960(void *arg0, s64 arg1);
extern "C" void func_003F9BF8(char *arg0, s64 *arg1, s32 arg2);

struct Loc {
    u16 h;
    u8 b2;
    u8 b3;
};

struct Blk {
    char b[32];
} __attribute__((aligned(4)));

struct Rec {
    float f;
    u16 h;
    u8 b2;
    u8 b3;
    s64 q;
    Blk tail;
};

extern "C" s32 func_003F9F18(char *arg0, void *arg1, const Blk *arg2, float fparg0)
{
    s32 r = func_003F9DC8(arg0, fparg0);
    if (r < 0) {
        return 0;
    }
    {
        Rec rec;
        Loc loc;
        rec.f = fparg0;
        func_004AF960(&loc, func_004B6658());
        rec.h = loc.h;
        rec.b2 = loc.b2;
        rec.b3 = loc.b3;
        rec.q = func_0040FB40(arg1);
        rec.tail = *arg2;
        func_003F9BF8(arg0, (s64 *)&rec, r);
    }
    return 1;
}
