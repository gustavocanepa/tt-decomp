typedef int s32;

extern void *D_005CF580;
extern "C" void func_0040BC48(void *, s32);
extern "C" void func_00370300(void *, s32);
extern "C" void func_0050E1A8(void *);

extern "C" void func_00348CD0(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x134) = &D_005CF580;
    if ((char *)arg0 + 0x188 != 0) {
        char *p0 = (char *)arg0 + 0xB48;
        while ((char *)arg0 + 0x188 != p0) {
            p0 -= 0x1A0;
            func_0040BC48(p0, 0x2);
        }
    }
    func_00370300(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
