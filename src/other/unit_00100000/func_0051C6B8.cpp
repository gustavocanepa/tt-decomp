typedef int s32;
typedef float f32;

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" Vec4 *func_004A4D68(Vec4 *arg0, Vec4 *arg1);

extern "C" void func_0051C6B8(void *arg0, Vec4 *arg1) {
    func_004A4D68((Vec4 *)((char *)arg0 + 0x124), arg1);
}
