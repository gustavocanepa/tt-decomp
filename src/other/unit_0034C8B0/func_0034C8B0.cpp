typedef int s32;
typedef float f32;

extern f32 D_00584064;

extern "C" void func_0034D470(void *self, s32 on);

extern "C" void func_0034C8B0(void *self, s32 on) {
    if (on) {
        D_00584064 = 0.0f;
        return func_0034D470(self, on);
    }
    D_00584064 = 1.0f / 60.0f;
}
