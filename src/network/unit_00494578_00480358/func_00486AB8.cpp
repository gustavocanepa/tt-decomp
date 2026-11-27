extern unsigned short D_006061F8, D_00606200, D_00606208;
extern unsigned short D_006061B0[], D_006061D0[], D_006061E0[], D_006061F0[];

extern "C" int func_00486AB8(int a0) {
    if ((unsigned int)(a0 - 0x61) < 0x1A) {
        return D_006061F8 + a0 - 0x61;
    }
    if ((unsigned int)(a0 - 0x41) < 0x1A) {
        return D_00606200 + a0 - 0x41;
    }
    if ((unsigned int)(a0 - 0x30) < 0xA) {
        return D_00606208 + a0 - 0x30;
    }
    if ((unsigned int)(a0 - 0x21) < 0xF) {
        return D_006061B0[a0 - 0x21];
    }
    if ((unsigned int)(a0 - 0x3A) < 7) {
        return D_006061D0[a0 - 0x3A];
    }
    if ((unsigned int)(a0 - 0x5B) < 6) {
        return D_006061E0[a0 - 0x5B];
    }
    if ((unsigned int)(a0 - 0x7B) < 4) {
        return D_006061F0[a0 - 0x7B];
    }
    return 0;
}
