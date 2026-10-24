/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004BB350(void);
extern "C" void func_004CC668(unsigned int);

extern "C" void func_004CC130(void)
{
    func_004BB350();
    unsigned int low = *(volatile unsigned int *)0x10002020 & 0x7F;
    return func_004CC668(((low + 7) & 0xF8) - low);
}
