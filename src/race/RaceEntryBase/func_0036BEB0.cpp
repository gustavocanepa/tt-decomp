/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short idx; void (*fn)(void *, int); };
struct Car { char p[0x55B8]; char *vt; };
struct S { unsigned n; int pad; Car **arr; char p[0x10]; Car *car; };

static inline void destroy(Car *c) {
    VE *e = (VE *)(c->vt + 8);
    e->fn((char *)c + e->delta, 3);
}

extern "C" void func_0036BEB0(S *self) {
    if (self->arr != 0) {
        unsigned i;
        for (i = 0; i < self->n; ) {
            Car *c = self->arr[i];
            i++;
            if (c != 0)
                destroy(c);
        }
    }
    if (self->car != 0) {
        destroy(self->car);
        self->car = 0;
    }
    self->n = 0;
}
