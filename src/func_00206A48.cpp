extern "C" int func_0020DC50(void *self);
extern "C" void func_00205E20(void *self, float *x, float *y);
extern "C" void func_00206998(void *self, float x, float y);

extern "C" void func_00206A48(void *self) {
    if (func_0020DC50(self)) {
        float x, y;
        func_00205E20(self, &x, &y);
        func_00206998(self, x, y);
    }
}
