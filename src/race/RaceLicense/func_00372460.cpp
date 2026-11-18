extern "C" void func_00356828(char *arg0);

extern "C" void func_00372460(char *arg0)
{
    int *var_a0;
    int *var_v1;
    int var_a1;
    int mask;

    func_00356828(arg0);
    mask = -0x100;
    var_a0 = (int *)(arg0 + 0x560C);
    var_v1 = (int *)(arg0 + 0x54BC);
    var_a1 = 2;
    do {
        var_a1 -= 1;
        *var_v1 &= mask;
        var_v1 = (int *)((char *)var_v1 + 0x70);
        *var_a0 &= mask;
        var_a0 = (int *)((char *)var_a0 + 0x94);
    } while (var_a1 >= 0);

    int *q = (int *)(arg0 + 0x5854);
    *q &= ~0xFF;
    int *r = (int *)(arg0 + 0x58EC);
    *r &= ~0xFF;
}
