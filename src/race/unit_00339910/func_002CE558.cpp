/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short delta,index; void *fn; };
struct Self { char pad[0x64]; V *vt; char gap[0xD8C-0x68]; int cc8,ccc,cd0,cd4; };
extern "C" int func_0033C828(void *);
extern "C" void RaceBase__setVisual(void *, int);
typedef void (*Fn0)(void *);
typedef void (*Fn1)(void *, int);
extern "C" int func_002CE558(Self *self) {
    int result = 0;
    if (func_0033C828(self) == 1) {
        V *e = (V *)((char *)self->vt + 0x2D0);
        int saved = self->cd4;
        self->cd4 = 0;
        int cc8 = self->cc8;
        int cd0 = self->cd0;
        ((Fn0)e->fn)((char *)self + e->delta);
        V *f = (V *)((char *)self->vt + 0x130);
        ((Fn1)f->fn)((char *)self + f->delta, cc8);
        RaceBase__setVisual(self, cd0);
        self->cd4 = saved;
        result = 1;
    }
    return result;
}
