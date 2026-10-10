typedef int s32;

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

extern "C" void mpegif__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x408) = &D_005DB0C0;
    *(void **)((char *)arg0 + 0x3e4) = 0x0;
    func_004AEB30((char *)arg0 + 0x320);
    func_004A5668(*(void **)((char *)arg0 + 0x3cc));
    func_004BD550(*(void **)((char *)arg0 + 0x3e8));
    func_004A45D0(*(void **)((char *)arg0 + 0x3d4));
    func_004A45D0(*(void **)((char *)arg0 + 0x3d8));
    func_004A45D0(*(void **)((char *)arg0 + 0x3dc));
    if (*(void **)((char *)&D_0059BF60 + -0x3b58) == 0) {
        func_004CC7B8();
    }
    func_004FA830(*(void **)(&D_0059840C));
    *(void **)(&D_0059840C) = (void *)(-0x1);
    func_004FA830(*(void **)((char *)arg0 + 0x400));
    *(void **)((char *)arg0 + 0x400) = (void *)(-0x1);
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
