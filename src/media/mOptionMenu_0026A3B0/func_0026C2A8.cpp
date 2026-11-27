/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float x, y, z; };
struct M {
    char pad0[0xE0]; void *c4; char padc8[0x34]; int fc; char pad100[8];
    float f108; float f10c; V v110; float f11c;
};
extern "C" void func_002063E0(void *, float *, float *, float *, float *);
extern "C" int func_0026AA90(void *) throw();
extern "C" int func_0026C100(void *, int) throw();
extern "C" int func_0026C1A0(void *, int) throw();
extern "C" void func_004AC580(void *, int);
extern "C" int func_004AC650(void *, int);
extern "C" int func_0026C2A8(M *self, int arg1) {
    if (self->c4 != 0 && self->fc != 0) {
        char *s1 = (char *)self + 0xF4;
        int s3 = *(int *)s1;
        int s4 = func_004AC650(s1, arg1);
        if (s4 != 0) {
            int v;
            if (arg1 > 0)
                v = func_0026C100(self, *(int *)s1);
            else
                v = func_0026C1A0(self, *(int *)s1);
            if (v >= 0) {
                func_004AC580(s1, v);
            } else {
                func_004AC580(s1, s3);
                s4 = 0;
            }
        }
        void *o = (void *)func_0026AA90(self);
        if (o != 0) {
            float a[4], b[4];
            func_002063E0(o, &a[0], &a[1], &a[2], &a[3]);
            if (a[1] < self->f108) {
                func_002063E0(self->c4, &b[0], &b[1], &b[2], &b[3]);
                V *p = &self->v110;
                p->z = b[1];
                p->y = p->x = 0.0f;
                self->f11c = b[1] + (self->f108 - a[1]);
            } else if (self->f10c < a[1] + a[3]) {
                func_002063E0(self->c4, &b[0], &b[1], &b[2], &b[3]);
                V *p = &self->v110;
                p->z = b[1];
                p->y = p->x = 0.0f;
                self->f11c = b[1] - ((a[1] + a[3]) - self->f10c);
            }
        }
        return s4;
    }
    return func_004AC650((char *)self + 0xF4, arg1);
}
