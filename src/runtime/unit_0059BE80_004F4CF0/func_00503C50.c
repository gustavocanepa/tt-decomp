/* compiler: ee-gcc2.9-991111 */
extern void func_004FA8D0(unsigned int *status);
extern void func_004FA8C0(unsigned int *status);

int func_00503C50(void)
{
    unsigned int st[2];

    func_004FA8D0(&st[0]);
    st[1] = (st[0] & ~0xE000) | 0x2000;
    func_004FA8C0(&st[1]);
    func_004FA8D0(&st[1]);
    func_004FA8C0(&st[0]);
    return ((st[1] >> 13) & 7) == 0;
}
