struct Vec3 {
    float x, y, z;
};

extern "C" void func_0046F0F8(int mode);
extern "C" void func_004702D8(int a, float b);
extern "C" void func_00477E30(float r, float g, float b, float a);
extern "C" void func_00475030(float x0, float y0, float z0, float x1, float y1, float z1);

extern "C" void func_0039B778(Vec3 *a, Vec3 *b) {
    func_0046F0F8(6);
    func_004702D8(0x44, 1.0f);
    func_00477E30(0.0f, 0.0f, 0.0f, 0x1.999998p-1f);
    func_00475030(a->x, a->y, a->z, b->x, b->y, b->z);
}
