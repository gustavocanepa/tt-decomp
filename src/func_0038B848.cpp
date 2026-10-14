typedef int s32;
typedef float f32;

extern "C" void func_00473178(s32 arg0);
extern "C" void func_004752F8(void *arg0);

struct Obj003994C0 {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

extern "C" void func_0038B848(struct Obj003994C0 *arg0) {
    f32 buf[16];

    func_00473178(1);
    func_004752F8(buf);
    func_00473178(0);
    arg0->unk14 = buf[14] / (buf[10] + 1.0f);
    arg0->unkC = arg0->unk4 * 0.5f * buf[5];
    arg0->unk18 = buf[14] / (buf[10] - 1.0f);
}
