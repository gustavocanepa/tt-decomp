extern int func_001037E0(void *arg0, void *arg1);

// Address-only global; its actual link address is irrelevant for grading,
// only the lui/addiu opcode pattern matters.
extern int D_005A4B88;

struct S001043C0_Obj {
    int unk00;                     // 0x00 - type/tag pointer
    int unk04;                     // 0x04
    char pad08[0x4C - 0x08];       // padding up to 0x4C
    struct Block16 { int w[4]; } unk4C; // 0x4C, 16 bytes copied from arg1
};

void func_00103988(S001043C0_Obj *arg0, void *arg1)
{
    func_001037E0(arg0, arg1);
    arg0->unk00 = (int)&D_005A4B88;
    arg0->unk4C = *(S001043C0_Obj::Block16 *)arg1;
    arg0->unk04 = 0;
}
