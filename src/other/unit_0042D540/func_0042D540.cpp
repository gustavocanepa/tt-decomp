typedef float f32;

extern char D_0076A058[];

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" void func_0042D068(f32 v);

extern "C" void func_0042D540(f32 v) {
    func_004A4D68(D_0076A058);
    func_0042D068(v);
    func_004A4DD8(D_0076A058);
}
