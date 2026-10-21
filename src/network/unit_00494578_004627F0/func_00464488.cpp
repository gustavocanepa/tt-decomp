extern "C" void func_004640E0(void *out, float a, float b, float c, float d, float e);
struct P { int z0; int z4; int z8; int zc; float f10; float f14; float f18; float f1c; float f20; float f24; float f28; void *buf; int count; };
extern "C" void func_00464488(P *self, void *buf, int count) {
    int i;
    self->z0 = 0;
    self->z4 = 0;
    self->z8 = 0;
    self->zc = 0;
    self->f10 = 8.0f;
    self->f14 = 32.0f;
    self->f18 = 8.0f;
    self->f1c = 16.0f;
    self->f20 = 0.5f;
    self->f24 = 0.01f;
    self->f28 = 0.5f;
    self->buf = buf;
    self->count = count;
    for (i = count - 1; i >= 0; i--) {
        func_004640E0((char *)self->buf + (i << 5), self->f14, self->f18, self->f20, self->f24, self->f28);
    }
}
