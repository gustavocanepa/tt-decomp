#include "types.h"

struct VEntryR {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

static inline s32 vcall150(char *o) {
    VEntryR *e = (VEntryR *)(*(char **)o + 0x178);
    return e->fn(o + e->delta);
}

extern char D_005F42F8[];
extern char D_005F4300[];
extern char D_005F4310[];
extern char D_005F4320[];

extern "C" s32 DisplayRText__getRTextStr(s32 arg0);
extern "C" s32 func_00376CC8(char *arg0, s8 arg1);
extern "C" void func_004A6500(char *arg0, char *arg1, s32 arg2);
extern "C" void RaceMessageDisplay__setFont(char *arg0, s32 arg1, s32 arg2);
extern "C" void RaceMessageDisplay__setMessage(char *arg0, char *arg1, f32 f12, f32 f13);

extern "C" void func_003515D0(char *self) {
    char buf[0x80];
    char *s0;
    char *s1;
    s32 s3;
    s32 s2;
    s32 r;
    s32 w1;
    s32 w2;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;

    if (vcall150(self) != 0) {
        s3 = DisplayRText__getRTextStr((s32)D_005F4310);
        s2 = DisplayRText__getRTextStr((s32)D_005F4320);
        if (s3 != 0) {
            if (s2 != 0) {
                s0 = self + 0x263C;
                f20 = 0x1.999998p-4f;
                r = func_00376CC8(*(char **)(self + 4), *(s8 *)(self + 0x2F));
                s1 = self + 0x278C;
                func_004A6500(buf, (char *)s2, r);
                f21 = 0x1.333332p-2f;
                RaceMessageDisplay__setFont(s0, (s32)D_005F42F8, 1);
                w1 = 0x80C8C8C8;
                f22 = 0x1.599998p+1f;
                f23 = 0x1p+0f;
                *(s32 *)(s0 + 0x20) = w1;
                *(f32 *)(s0 + 0x18) = f20;
                *(f32 *)(s0 + 0x1C) = f21;
                RaceMessageDisplay__setMessage(s0, (char *)s3, f22, f23);
                RaceMessageDisplay__setFont(s1, (s32)D_005F4300, 1);
                w2 = 0x800086E6;
                *(f32 *)(s1 + 0x18) = f20;
                *(s32 *)(s1 + 0x20) = w2;
                *(f32 *)(s1 + 0x1C) = f21;
                RaceMessageDisplay__setMessage(s1, buf, f22, f23);
            }
        }
    }
}
