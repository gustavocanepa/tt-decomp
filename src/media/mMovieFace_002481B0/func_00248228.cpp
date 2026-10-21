/* compiler: ee-gcc2.96-nsa-nosib */
extern "C" int func_00481970(void);

struct func_00248228_arg0 {
    char pad0[0x1A4];
    int unk164;
};

extern "C" int func_00248228(void *arg0) {
    struct func_00248228_arg0 *self = (struct func_00248228_arg0 *)arg0;
    int v = func_00481970();
    if (v == 0) {
        return v;
    }
    int flag = 0;
    int a = self->unk164;
    if (a == 0 || a == 6 || a == 7 || a == 7) {
        flag = 1;
    }
    return flag;
}
