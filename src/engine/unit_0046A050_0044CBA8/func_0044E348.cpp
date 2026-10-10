struct Vec4 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};

extern "C" void func_004A6328(float *, float *, float);

extern "C" void func_0044E348(Vec4 *v, float angle) {
    float a, b;
    func_004A6328(&a, &b, angle * 0.5f);
    v->unk0 = 0.0f;
    v->unk4 = a;
    v->unk8 = 0.0f;
    v->unkC = b;
}
