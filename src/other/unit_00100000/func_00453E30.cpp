struct Vec4 {
    float x, y, z, w;
};

extern "C" void func_00453D20(Vec4 *, void *, Vec4 *);

extern "C" void func_00453E30(Vec4 *self, void *arg) {
    Vec4 t;
    func_00453D20(&t, arg, self);
    self->x = t.x;
    self->y = t.y;
    self->z = t.z;
    self->w = t.w;
}
