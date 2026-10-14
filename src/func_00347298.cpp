typedef int s32;
typedef unsigned char u8;

extern char D_00794E60[];
extern "C" void *func_004F6678(void *, s32, s32);

extern "C" void func_00347298(s32 arg0) {
    char *p = D_00794E60;
    func_004F6678(p, 0, 0xB);
    if (arg0 & 1) {
        p[0x0] = 1;
    }
    if (arg0 & 2) {
        p[0x1] = 1;
    }
    if (arg0 & 4) {
        p[0x2] = 1;
    }
    if (arg0 & 8) {
        p[0x3] = 1;
    }
    if (arg0 & 0x10) {
        p[0x7] = 1;
    }
    if (arg0 & 0x20) {
        p[0x4] = 1;
    }
    if (arg0 & 0x40) {
        p[0x8] = 1;
    }
    if (arg0 & 0x80) {
        p[0x9] = 1;
    }
    if (arg0 & 0x100) {
        p[0xA] = 1;
    }
    if (arg0 & 0x200) {
        p[0x5] = 1;
    }
    if (arg0 & 0x400) {
        p[0x6] = 1;
    }
}
