struct Vec4 {
    float x, y, z, w;
};

extern "C" void func_00213EA8(void *self, float *x, float *y, float *z, float *w);

extern "C" void func_00214008(void *self, Vec4 *a, Vec4 *b) {
    func_00213EA8(self, &a->x, &a->y, &a->z, &a->w);
    func_00213EA8(self, &b->x, &b->y, &b->z, &b->w);
}
