typedef int s32;
typedef unsigned char u8;

extern char D_005E8F48[];
extern char D_005E8F60[];
extern char D_005E8F68[];
extern char D_005E8F80[];
extern char D_005E8F98[];
extern char D_005E8FB0[];
extern char D_007643F0[];
extern char D_007647B8[];
extern char D_00764B80[];
extern char D_00764F48[];

extern "C" void HOutput__printf(void *arg0, const char *fmt, ...);
extern "C" void *func_002BD830(void);
extern "C" void func_002BDA00(s32 arg0, s32 arg1);

extern "C" void mManager__Report(s32 arg0) {
    HOutput__printf((void *)arg0, D_005E8F48);
    char *func_005AE388 = D_005E8F60;
    func_002BDA00(arg0, (s32)&D_007643F0);
    HOutput__printf((void *)arg0, func_005AE388);
    HOutput__printf((void *)arg0, D_005E8F68);
    func_002BDA00(arg0, (s32)&D_007647B8);
    HOutput__printf((void *)arg0, func_005AE388);
    HOutput__printf((void *)arg0, D_005E8F80);
    func_002BDA00(arg0, (s32)&D_00764B80);
    HOutput__printf((void *)arg0, func_005AE388);
    HOutput__printf((void *)arg0, D_005E8F98);
    func_002BDA00(arg0, (s32)&D_00764F48);
    HOutput__printf((void *)arg0, func_005AE388);
    HOutput__printf((void *)arg0, D_005E8FB0);
    func_002BDA00(arg0, (s32)func_002BD830());
    HOutput__printf((void *)arg0, func_005AE388);
}
