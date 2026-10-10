extern "C" void func_001028A0(unsigned char *dst, unsigned char *src);
extern "C" void func_00102BB0(unsigned char *dst, unsigned char *src);

extern "C" void func_00102F38(unsigned char *dst, unsigned char *src)
{
    for (int i = 0; i < 8; i++) {
        func_001028A0(dst + 0x100, src);
        func_00102BB0(dst + 0x101, src + 0x780);
        func_00102BB0(dst + 0x300, src + 0xF00);
        func_001028A0(dst + 0x301, src + 0x1680);
        src += 0x1E00;
        dst += 0x400;
    }
}
