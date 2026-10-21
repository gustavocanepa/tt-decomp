typedef int s32;
typedef float f32;

extern "C" void AutomaticFader__fadeout(void *self, f32 t);

extern "C" void func_003724E8(char *arg0) {
    char *p;
    s32 i;

    AutomaticFader__fadeout(arg0 + 0xCC, 0x1.000000p-2f);
    p = arg0 + 0x57C8;
    i = 4;
    do {
        char *temp_a0 = p;
        i = i - 1;
        p += 0x1C;
        AutomaticFader__fadeout(temp_a0, 0x1.000000p-2f);
    } while (i >= 0);
}
