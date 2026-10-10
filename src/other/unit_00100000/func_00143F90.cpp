typedef int s32;

extern "C" void *func_00141FF0(void *);
extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_003F8068(s32, s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_00141F98(void *, s32);

extern "C" void func_00143F90(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    if (arg2 > 0) {
        func_00141FF0(buf0);
        p_s1 = buf1;
        func_0029CF48(p_s1, arg3);
        v_s0 = *(s32 *)((char *)buf0[0] + 0x10) + 0x1D0;
        func_003F8068(v_s0, func_0029E9F0(*p_s1));
        func_0029CEF0(p_s1, 0x2);
        func_00141F98(buf0, 0x2);
    }
}
