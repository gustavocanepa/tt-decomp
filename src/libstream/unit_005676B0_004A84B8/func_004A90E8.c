extern int func_00502C68(int a, int b, int c, int *out);
extern void func_004A59F0(void);

int func_004A90E8(int a, int b, int c)
{
    int out;
    while (func_00502C68(a, b, c, &out) < 0)
        func_004A59F0();
    return out;
}
