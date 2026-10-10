struct Vec4 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};

extern Vec4 D_00769D08;

extern "C" void func_0041CA18(float fparg0, float fparg1, float fparg2, float fparg3) {
    D_00769D08.unk0 = fparg0;
    D_00769D08.unk4 = fparg1;
    D_00769D08.unk8 = fparg2;
    D_00769D08.unkC = fparg3;
}
