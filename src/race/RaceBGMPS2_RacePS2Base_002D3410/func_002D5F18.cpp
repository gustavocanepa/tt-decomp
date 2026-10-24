/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short delta,index; char *(*fn)(void *, int); };
struct Self { char pad[0x64]; V *vt; };
struct Car { char pad[0x564]; unsigned char index; };
struct Arg { char pad[0x18]; Car *car; };
extern "C" int Pitmen__isNotRenderOthersPeriod(void *, int);
extern "C" int func_002D5F18(Self *self, Arg *arg) {
    V *e = (V *)((char *)self->vt + 0xD0);
    unsigned char i = arg->car->index;
    char *o = e->fn((char *)self + e->delta, 0);
    void *pit = (char *)self + 0x36C0;
    if (*(int *)((char *)self + i*4 + 0x36FC) != 0) return 0;
    int size = 0x1B4;
    int period = Pitmen__isNotRenderOthersPeriod(pit, *(short *)(o + *(int *)(o+0xA4C)*size + 0x1C));
    if (period != 0 && *(short *)(o + *(int *)(o+0xA4C)*size + 0x1C) != i) return 0;
    return 1;
}
