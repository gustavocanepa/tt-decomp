typedef unsigned char u8;

struct Obj {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

extern "C" void func_00369150(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk1 = 0;
    arg0->unk2 = 1;
    arg0->unk3 = 1;
    arg0->unk4 = 1;
    arg0->unk5 = 2;
    arg0->unk6 = 0;
    arg0->unk7 = 0;
}
