typedef int s32;
typedef float f32;

extern "C" void func_00477E30(f32 a, f32 b, f32 c, f32 d);
extern "C" void func_004702D8(s32 id, f32 v);
extern "C" void func_0046F0F8(s32 id);
extern "C" void func_002D5E18(void *obj);

extern "C" void func_002D5D68(void *obj, f32 x, f32 y) {
    func_00477E30(0.0f, 0.0f, 0.0f, y);
    func_004702D8(0xA9, x);
    func_0046F0F8(6);
    func_002D5E18(obj);
}
