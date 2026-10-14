/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int zero; float x, y; int z, a, b, c; float d, e; };
extern "C" void func_003787F8(Obj *self) {
    self->zero = 0;
    self->x = self->y = 0.0f;
    self->z = 0;
    self->a = -1;
    self->b = -1;
    self->c = -1;
    self->d = -1.0f;
    self->e = self->x;
}
