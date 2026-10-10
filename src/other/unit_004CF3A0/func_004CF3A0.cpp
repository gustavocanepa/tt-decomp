typedef int s32;

struct Elem {
    s32 unk0;
    s32 unk4;
};

extern Elem D_005A0B68[];

extern "C" void func_004CF3A0(s32 arg0) {
    Elem *p = &D_005A0B68[arg0];
    p->unk0 = 0;
    p->unk4 = 0;
}
