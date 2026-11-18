/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Lights { int pad; float dir[4][4]; };
extern "C" void func_00473A08(int, int, float *);
extern "C" void func_00521F20(Lights *self, unsigned int i, float x, float y, float z) {
    if (i < 4) {
        self->dir[i][0] = x;
        self->dir[i][1] = y;
        self->dir[i][2] = z;
        self->dir[i][3] = 0.0f;
    }
    func_00473A08(i + 0x65, 0xD, self->dir[i]);
}
