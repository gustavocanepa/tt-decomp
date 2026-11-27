#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_001803E8(void *);
extern "C" void func_00180390(void *, s32);
extern "C" void func_0029B380(void *, f32);
extern "C" void func_00299AB0(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

struct MPhotoRenderFace__get_imageWidth_v_s0 {
    char pad0[0x10];
    s32 unk10;
    char pad1[0x4];
    s32 unk18;
};

extern "C" void func_00181E18(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    f32 w;

    func_001803E8(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x100);
    func_00180390(buf0, 0x2);
    w = 0.0f;
    if (v_s0 != 0) {
        w = (f32)(((struct MPhotoRenderFace__get_imageWidth_v_s0 *)v_s0)->unk10 *
                  ((struct MPhotoRenderFace__get_imageWidth_v_s0 *)v_s0)->unk18);
    }
    func_0029B380(buf0, w);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_00299AB0(buf0, 0x2);
}
