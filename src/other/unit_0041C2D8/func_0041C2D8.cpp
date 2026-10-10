struct Vec4 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};

extern Vec4 D_00769CF0;

extern "C" void func_0041C2D8(float fparg0, float fparg1, float fparg2, float fparg3) {
    D_00769CF0.unk0 = fparg0;
    D_00769CF0.unk4 = fparg1;
    D_00769CF0.unk8 = fparg2;
    D_00769CF0.unkC = fparg3;
}
