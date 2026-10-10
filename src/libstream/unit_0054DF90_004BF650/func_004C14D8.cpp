/* A 0x2280-byte object; its constructor is func_004C1730. */
struct func_004C1730 {
    char data[0x2280];
    func_004C1730();
};
extern "C" void func_004C1608(func_004C1730 *self);
extern "C" func_004C1730 *D_00598C0C;

extern "C" void func_004C14D8(void)
{
    if (!D_00598C0C) {
        D_00598C0C = new func_004C1730;
        func_004C1608(D_00598C0C);
    }
}
