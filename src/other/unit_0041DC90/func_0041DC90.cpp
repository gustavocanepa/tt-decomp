struct Vec3 {
    float x, y, z;
};

struct Vec4 {
    float x, y, z, w;
};

extern "C" void func_00475850(void *, Vec4 *);

extern "C" void func_0041DC90(void *self, Vec3 *p) {
    Vec4 v;
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    v.w = 1.0f;
    func_00475850(self, &v);
}
