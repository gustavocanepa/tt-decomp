struct Obj {
    char pad0[0x10];
    char *unk10;
};

struct Sub {
    char pad0[0x540];
    unsigned char unk520;
    char pad1;
    unsigned char unk522;
};

extern "C" int func_00314F38(Obj *self);
extern "C" int func_0039F070(char *arg0);
extern "C" void func_002FEF38(char *arg0, int arg1, signed char arg2);
extern "C" void func_00314618(Obj *arg0, int arg1);

extern "C" void func_002F6860(Obj *arg0) {
    int temp_v0;
    int temp_v1;
    Sub *temp_s0;

    temp_v0 = func_00314F38(arg0);
    temp_s0 = (Sub *)((char *)arg0 + 0x104);
    if (temp_v0 == -1) {
        return;
    }
    if (temp_s0->unk522 != 0) {
        if (temp_v0 == 0 || temp_s0->unk520 == 0) {
            temp_s0->unk522 = 2;
        } else {
            if (func_0039F070(arg0->unk10 + 0x240) == 0) {
                temp_s0->unk522 = 3;
            }
            temp_v1 = temp_s0->unk520;
            if (temp_v1 < temp_v0) {
                func_002FEF38((char *)arg0, 0, 1);
            } else if (temp_v0 < temp_v1) {
                func_002FEF38((char *)arg0, 0, -1);
            }
        }
    }
    return func_00314618(arg0, temp_v0);
}
