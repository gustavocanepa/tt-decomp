typedef int s32;

extern "C" void func_004A5668(s32 arg0);
extern "C" void func_004A5880(s32 arg0);

extern s32 D_0057ABEC;

extern "C" void func_001C5BB8(void) {
    func_004A5668(D_0057ABEC);
    func_004A5880(D_0057ABEC);
    D_0057ABEC = 0;
}
