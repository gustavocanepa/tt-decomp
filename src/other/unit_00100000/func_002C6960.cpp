typedef int s32;

extern "C" void func_002E3DD8(void *arg0, const char *arg1, s32 arg2);
extern "C" void func_0043A7E8(s32 arg0);
extern "C" void func_002E39A0(s32 arg0);
extern "C" void func_00439930(void *arg0);
extern "C" void func_0043AD60(s32 arg0, void *arg1);

struct Obj {
    char pad0[0xC];
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct Local1 {
    char pad[0x10];
    s32 unk10;
};

struct Local2 {
    char data[0x30];
};

extern "C" void func_002C6960(Obj *arg0, s32 arg1) {
    Local1 local1;
    Local2 local2;

    arg0->unk8 = arg1;
    if (arg0->unk0 == 0 && arg0->unk4 == 0) {
        func_002E3DD8(&local1, "racemonitor.strb", 1);
        arg0->unk0 = local1.unk10;
        func_0043A7E8(arg0->unk0);
        func_002E39A0(arg0->unk0);
        func_00439930(&local2);
        func_0043AD60(arg0->unk0, &local2);
    }
}
