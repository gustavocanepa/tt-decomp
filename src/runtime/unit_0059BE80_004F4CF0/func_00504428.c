/* compiler: ee-gcc2.9-991111 */
int func_005038D8(void);
void func_00503928(void);
void func_005041C8(unsigned int);
int func_00504A30(void);
void func_00504538(int);

int func_00504428(void)
{
    int s = func_005038D8();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (v & 0x80) {
        if (s) func_00503928();
        return 1;
    }
    func_005041C8((v & ~0xC00) | 0x80);
    func_00504538(func_00504A30());
    if (s) func_00503928();
    return 0;
}
