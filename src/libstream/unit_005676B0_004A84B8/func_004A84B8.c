extern signed char D_0060C110[13];

int func_005038D8(void);
int func_004FB300(int id);

void func_004A84B8(void)
{
    int i;
    int state = func_005038D8();

    for (i = 0; i < 13; i++)
        func_004FB300(D_0060C110[i]);
    if (state)
        __asm__ volatile("ei");
}
