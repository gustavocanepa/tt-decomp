/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void func_004BB688(void);
int func_004BB6B8(void);
void func_004CBF30(char *dst, char *src, int bytes);

int func_004CBE80(char *dst, char *src, int total)
{
    func_004BB688();
    int rest = total % 0x300;
    int chunks = total / 0x300;
    if (chunks > 0) do {
        chunks--;
        func_004CBF30(dst, src, 0x300);
        dst += 0xC0000;
        src += 0x48000;
    } while (chunks != 0);
    if (rest)
        func_004CBF30(dst, src, rest);
    return func_004BB6B8();
}
}
