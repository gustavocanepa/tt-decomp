/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta,index; int (*fn)(void *); };
struct Source { VEntry *vt; };
struct Ref { int a,b; unsigned char *data; int d; };
struct Input { Source *source; int id,index,mode; unsigned char empty; };
extern "C" void func_0047B0F8(void *) throw();
extern "C" int func_0047AA68(Ref *, Source *, int) throw();
extern "C" void func_0047B160(void *, int, unsigned char *) throw();
extern "C" void func_0047A9B8(Ref *, int) throw();
extern "C" void *func_0047B6D0(void *self, Input *input) {
    if (input->empty) func_0047B0F8(self);
    else {
        Source *source = input->source;
        VEntry *e = source->vt + 2;
        int n = e->fn((char *)source + e->delta);
        Ref ref;
        func_0047AA68(&ref, input->source, input->id);
        n -= input->index * 8;
        n -= 4;
        unsigned char *p = ref.data + n;
        func_0047B160(self, input->mode, ref.data + (p[0] | (p[1] << 8)));
        func_0047A9B8(&ref, 2);
    }
    return self;
}
