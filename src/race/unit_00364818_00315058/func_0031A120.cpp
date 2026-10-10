extern "C" void *func_004F6678(void *p, int c, int n);
extern "C" void func_00319D00(void *self);
extern "C" void func_00319EC0(void *self, void *a, void *b);

struct Vec3 {
    float x, y, z;
};

extern "C" void func_0031A120(void *self) {
    Vec3 a;
    Vec3 b;
    Vec3 *pa = &a;
    Vec3 *pb = &b;
    func_004F6678(pa, 0, sizeof(Vec3));
    func_004F6678(pb, 0, sizeof(Vec3));
    func_00319D00(self);
    func_00319EC0(self, pa, pb);
}
