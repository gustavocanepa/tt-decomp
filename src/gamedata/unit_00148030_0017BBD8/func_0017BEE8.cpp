/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Inner { char pad[0xB8]; s32 unk7C; };
extern "C" void func_0017BC58(void *, int) throw();
extern "C" void func_0017BCB0(void *, s32) throw();
extern "C" void func_001BE480(s32, s32, s32, s32);
extern "C" void func_00202788(void *, int);
extern "C" void func_002027E0(void *, s32);

extern "C" void func_0017BEE8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Inner *buf0[4];
    s32 buf1[4];
    if (arg2 >= 2) {
        func_0017BCB0(buf0, arg1);
        s32 *p = buf1;
        func_002027E0(p, arg3);
        buf0[0]->unk7C = *p;
        func_001BE480(arg0, arg1, arg2 - 1, arg3 + 4);
        func_00202788(p, 2);
        func_0017BC58(buf0, 2);
    }
}
