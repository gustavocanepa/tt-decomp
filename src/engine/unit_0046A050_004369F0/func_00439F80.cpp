extern "C" void func_0043A180(void *arg0);
extern "C" void func_0046F0F8(int arg0, float arg1);
extern "C" void func_00477E30(float arg0, float arg1, float arg2, float arg3);
extern "C" void func_00478C98(int arg0);

struct func_00439F80_arg0 {
    int unk0;
    int unk4;
    char pad8[0x4];
    int unkC;
    char pad10[0x4];
    int unk14;
    char pad18[0xC];
    int unk24;
};

extern "C" void func_00439F80(void *arg0, float fparg0, float fparg1, float fparg2, float fparg3) {
    float var_f20;

    var_f20 = fparg3;
    if (((struct func_00439F80_arg0 *)arg0)->unk14 == 0) {
        func_0043A180(arg0);
    }
    if (((struct func_00439F80_arg0 *)arg0)->unkC != 0) {
        var_f20 = (float)((struct func_00439F80_arg0 *)arg0)->unk24 * 0.0078125f;
        func_00478C98(9);
    } else if (((struct func_00439F80_arg0 *)arg0)->unk0 != 0) {
        if (((struct func_00439F80_arg0 *)arg0)->unk4 == 0) {
            if ((int)(var_f20 * 128.0f) == 0x80) {
                var_f20 = 1.0f;
                func_0046F0F8(9, fparg0);
            } else {
                func_00478C98(9);
            }
        }
    }
    func_00477E30(fparg0, fparg1, fparg2, var_f20);
}
