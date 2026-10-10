struct Pool { char *base; int used; char *func_00575DA0; };

extern "C" int func_003921B8(Pool *self);

extern "C" void func_00392F18(Pool *self)
{
    self->used = 0;
    self->func_00575DA0 = self->base;
    int size = func_003921B8(self);
    char *p = self->func_00575DA0;
    for (int i = 0; i < 127; i++) {
        char *next = p + size;
        *(char **)p = next;
        p = next;
    }
    *(char **)p = 0;
}
