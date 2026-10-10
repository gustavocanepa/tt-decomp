struct Vec3 {
    float x, y, z;
};

struct Obj {
    char pad[8];
    float x;
    float y;
};

extern "C" void func_004158D0(Obj *, Vec3 *, Vec3 *);

extern "C" void func_00415A10(Obj *self, float x, float y, float z) {
    Vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    func_004158D0(self, &v, &v);
    self->x = v.x;
    self->y = v.y;
}
