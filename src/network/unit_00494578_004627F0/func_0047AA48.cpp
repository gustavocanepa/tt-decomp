typedef int s32;

extern char D_0076FC80;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_0047AA48(Obj *arg0) {
    arg0->unk4 = -1;
    arg0->unk0 = (s32)&D_0076FC80;
    arg0->unk8 = 0;
}
