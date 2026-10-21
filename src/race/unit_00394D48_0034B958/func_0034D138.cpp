typedef int s32;

extern "C" void func_00473178(s32 mode);
extern "C" void func_00473050();
extern "C" void func_00468B68(float shift);
extern "C" void ModelSet2__begin(void *obj, s32 arg1);
extern "C" void func_00473F10(float a, float b, float c, float d);
extern "C" void ModelSet2___render(void *obj, s32 arg1, s32 arg2);
extern "C" void ModelSet2__end(void *obj);
extern "C" void func_004730A8();

struct Vec4 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};

struct ObjInner {
    char pad[0x7C];
    s32 unk7C;
};

struct ObjA {
    char pad[0xAC];
    ObjInner *unkAC;
};

extern "C" void func_0034D138(ObjA *arg0, Vec4 *arg1) {
    if (arg0->unkAC != 0) {
        func_00473178(1);
        func_00473050();
        func_00468B68(0.005f);
        s32 s0 = arg0->unkAC->unk7C;
        ModelSet2__begin(arg0->unkAC, s0);
        func_00473F10(arg1->unk0, arg1->unk4, arg1->unk8, arg1->unkC);
        ModelSet2___render(arg0->unkAC, 0, s0);
        ModelSet2__end(arg0->unkAC);
        func_004730A8();
        func_00473178(0);
    }
}
