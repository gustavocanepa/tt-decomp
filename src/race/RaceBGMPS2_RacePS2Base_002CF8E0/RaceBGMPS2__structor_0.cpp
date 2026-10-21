#include "types.h"

struct Obj {
    char pad0[4];
    void *vt;
    void *f8;
    void *fC;
    void *f10;
    s32 f14;
    char pad18[0x18];
    s32 f30;
    s32 f34;
};

extern char D_005C9098[];
extern "C" void func_002D02A0(void);
extern "C" void func_002D02A8(void);
extern "C" void func_0042B608(void);
extern "C" void func_002CFA98(void *, float);
extern "C" void func_002CFED8(void *, float);
extern "C" s32 RaceBGMBase__structor_0(void *);
extern "C" void GranTurismo4__BGMPlayList__setDefault(void *, s32);
extern "C" void func_0042B7C0(void *);

extern "C" void RaceBGMPS2__structor_0(Obj *arg0) {
    RaceBGMBase__structor_0(arg0);
    arg0->vt = D_005C9098;
    GranTurismo4__BGMPlayList__setDefault((char *)arg0 + 0x1C8, 0);
    GranTurismo4__BGMPlayList__setDefault((char *)arg0 + 0x9D8, 0);
    arg0->f8 = (void *)func_002D02A0;
    arg0->f10 = (void *)func_002D02A8;
    arg0->fC = (void *)func_0042B608;
    arg0->f14 = 0;
    func_0042B7C0((char *)arg0 + 0x18);
    arg0->f30 = 0;
    arg0->f34 = 0;
    float one = 1.0f;
    func_002CFA98(arg0, one);
    return func_002CFED8(arg0, one);
}
