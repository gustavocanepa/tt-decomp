#include "types.h"

extern void *D_0059840C;
extern void *D_0059BF60;
extern void *D_005A07FC;
extern void *D_005DB0C0;
extern "C" void func_004AEB30(void *);
extern "C" void func_004A5668(void *);
extern "C" void func_004BD550(void *);
extern "C" void func_004A45D0(void *);
extern "C" void func_004CC7B8(void);
extern "C" void func_004FA830(void *);
extern "C" void func_004F4C30(void *, s32);
extern "C" void func_004AE9F0(void *, s32);
extern "C" void func_0050E1A8(void *);

struct mpegif__structor_1_arg0 {
    char pad0[0x3CC];
    void *unk3CC;
    char pad3D0[0x4];
    void *unk3D4;
    void *unk3D8;
    void *unk3DC;
    char pad3E0[0x4];
    void *unk3E4;
    void *unk3E8;
    char pad3EC[0x14];
    void *unk400;
    char pad404[0x4];
    void *unk408;
};

extern "C" void mpegif__structor_1(void *arg0, s32 arg1) {
    ((struct mpegif__structor_1_arg0 *)arg0)->unk408 = &D_005DB0C0;
    ((struct mpegif__structor_1_arg0 *)arg0)->unk3E4 = 0x0;
    func_004AEB30((char *)arg0 + 0x320);
    func_004A5668(((struct mpegif__structor_1_arg0 *)arg0)->unk3CC);
    func_004BD550(((struct mpegif__structor_1_arg0 *)arg0)->unk3E8);
    func_004A45D0(((struct mpegif__structor_1_arg0 *)arg0)->unk3D4);
    func_004A45D0(((struct mpegif__structor_1_arg0 *)arg0)->unk3D8);
    func_004A45D0(((struct mpegif__structor_1_arg0 *)arg0)->unk3DC);
    if (*(void **)((char *)&D_0059BF60 + -0x3b58) == 0) {
        func_004CC7B8();
    }
    func_004FA830(*(void **)(&D_0059840C));
    *(void **)(&D_0059840C) = (void *)(-0x1);
    func_004FA830(((struct mpegif__structor_1_arg0 *)arg0)->unk400);
    ((struct mpegif__structor_1_arg0 *)arg0)->unk400 = (void *)(-0x1);
    func_004FA830(*(void **)(&D_005A07FC));
    *(void **)(&D_005A07FC) = (void *)(-0x1);
    func_004F4C30((char *)arg0 + 0x380, 0x2);
    func_004AE9F0((char *)arg0 + 0x350, 0x2);
    func_004AE9F0((char *)arg0 + 0x320, 0x2);
    func_004AE9F0((char *)arg0 + 0x2f0, 0x2);
    func_004AE9F0((char *)arg0 + 0x2c0, 0x2);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
