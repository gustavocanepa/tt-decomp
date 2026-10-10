typedef int s32;

extern s32 D_00579744;

extern "C" void func_004A45D0(s32 arg0);

extern "C" void func_00108168(void) {
    s32 temp_v1 = D_00579744;
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
        D_00579744 = 0;
    }
}
