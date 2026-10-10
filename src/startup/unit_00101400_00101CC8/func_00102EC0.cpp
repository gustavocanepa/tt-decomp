struct Block { char d[0x780]; };
extern "C" void func_001028A0(unsigned char *dst, Block *src);
extern "C" void func_00102BB0(unsigned char *dst, Block *src);

extern "C" void func_00102EC0(unsigned char *dst, Block *src)
{
    for (int i = 0; i < 8; i++) {
        func_001028A0(dst, src);
        func_00102BB0(dst + 1, src + 1);
        func_00102BB0(dst + 0x200, src + 2);
        func_001028A0(dst + 0x201, src + 3);
        dst += 0x400;
        src += 4;
    }
}
