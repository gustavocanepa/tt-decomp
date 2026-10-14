typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Blk8 {
    s32 a;
    s32 b;
};

typedef void (*F2)(s32, s32);

extern "C" void *func_0047DAE8(s32, s32);
extern "C" void func_0047E640(void *, void *);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, s32, s32, s32);

extern char D_0056E950[];
extern char D_0056E660[];
extern char D_0042EDC8[];
extern char D_0076BDB8[];

extern "C" void func_0042F240(s32 arg0, void *arg1) {
    char *v;
    char *r;
    char *t;
    Blk8 p;
    F2 f;

    v = (char *)func_0047DAE8(0, arg0);
    if (v != 0) {
        t = *(char **)(v + 0xA8);
        r = (char *)GT4MC__FileGT4GameData__loadInstance(*(s32 *)(t + 4), (s32)D_0056E950, 0,
                                  (s32)(v + *(s16 *)t), (s32)D_0056E660, (s32)v);
        p.b = *(s32 *)((char *)arg1 + 4);
        p.a = (s32)D_0042EDC8;
        *(Blk8 *)(r + 0xC8) = p;
        *(s32 *)(r + 0x60) = 1;
        *(s32 *)(r + 0x74) = 0;
        p.a = 0;
        p.b = 0;
        *(Blk8 *)(r + 0x64) = p;
        *(Blk8 *)(r + 0x6C) = *(Blk8 *)arg1;
        func_0047E640((void *)D_0076BDB8, r);
    } else {
        f = *(F2 *)arg1;
        if (f != 0) {
            f(*(s32 *)((char *)arg1 + 4), 0);
        }
    }
}
