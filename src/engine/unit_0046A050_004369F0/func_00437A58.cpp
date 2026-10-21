typedef int s32;
typedef short s16;
struct S0 { s32 unk0; char pad4[8]; s16 unkC; };
struct Src { char pad[0xA4]; s32 unk9C; };
extern "C" s32 func_004369F0(void *, s32);
extern "C" s32 func_00436EB0(void *, s32);
extern "C" void func_00437A58(S0 *arg0, Src *arg1) {
    arg0->unk0 = (s32)arg1;
    func_00436EB0(arg0, arg1->unk9C);
    arg0->unkC = 1;
    if (func_004369F0(arg0, 3) == 0 || func_004369F0(arg0, 4) == 0) {
        arg0->unkC = 0;
    }
}
