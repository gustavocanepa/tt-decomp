typedef unsigned char u8;

struct C { char pad[0xC]; u8 unkC; char pad2[3]; u8 unk10; };
struct B { char pad[0x2C]; C *unk14; };

extern B *D_00586EF4;

extern "C" u8 func_00416090(void) {
    return D_00586EF4->unk14->unk10;
}
