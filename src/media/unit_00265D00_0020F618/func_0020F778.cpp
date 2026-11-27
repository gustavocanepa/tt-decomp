/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Quad {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct mWidget {
    char pad_00[0xA8];
    struct Quad *unk90;
};

extern "C" void func_00205E20(void *arg0, s32 arg1, s32 arg2);

extern "C" void func_0020F778(struct mWidget *arg0, struct Quad *arg1) {
    f32 sp[2];

    if (arg0->unk90 != 0) {
        func_00205E20(arg0, (s32)sp, (s32)(sp + 1));
        if (0.0f < sp[0]) {
            arg0->unk90->unk0 = arg1->unk0 / sp[0];
            arg0->unk90->unk8 = arg1->unk8 / sp[0];
        } else {
            arg0->unk90->unk0 = 0.0f;
            arg0->unk90->unk8 = 1.0f;
        }
        if (0.0f < sp[1]) {
            arg0->unk90->unk4 = arg1->unk4 / sp[1];
            arg0->unk90->unkC = arg1->unkC / sp[1];
        } else {
            arg0->unk90->unk4 = 0.0f;
            arg0->unk90->unkC = 1.0f;
        }
    }
}
