#include "types.h"

struct Obj {
    char pad0[0x24];
    s32 f24;
};

extern char D_005F7700[];
extern char D_005F7738[];

extern "C" void RaceDisplayObjectBase__selectTexture(Obj *arg0, s32 arg1);
extern "C" void func_00391890(Obj *arg0, f32 fparg0, f32 fparg1);

extern "C" void RaceOnboardSpeedmeter__setSpeedScale(Obj *arg0, s32 arg1, f32 fparg0) {
    f32 f20 = 0.0f;

    if (arg1 != 0) {
        s32 n = 0;
        s32 off = 0;
        s32 base = (s32)D_005F7700;
        s32 b4 = base + 4;
        s32 b8 = base + 8;
        for (;;) {
            if (fparg0 <= *(f32 *)(off + base)) {
                n++;
                {
                    s32 a = *(s32 *)(off + b8);
                    f20 = *(f32 *)(off + b4);
                    RaceDisplayObjectBase__selectTexture(arg0, a);
                }
                break;
            }
            n++;
            off += 12;
            if (n >= 3)
                break;
        }
    } else {
        s32 n = 0;
        char *p = D_005F7738;
        for (;;) {
            if (fparg0 <= *(f32 *)p) {
                n++;
                {
                    s32 a = *(s32 *)(p + 8);
                    f20 = *(f32 *)(p + 4);
                    RaceDisplayObjectBase__selectTexture(arg0, a);
                }
                break;
            }
            n++;
            p += 12;
            if (n >= 4)
                break;
        }
    }

    func_00391890(arg0, 0.0f, f20);
    arg0->f24 = 0;
}
