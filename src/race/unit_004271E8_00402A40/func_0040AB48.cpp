/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Src { char pad[0x10]; float f10; float f14; float f18; float f1C; float f20; };
struct Dst { char pad[0x12]; short s12; short s14; short s16; short s18; char pad2[0x26]; short s40; };

extern "C" void func_0040AB48(void *unused, Dst *d, Src *s) {
    unsigned a = (unsigned)s->f14;
    d->s16 = a;
    unsigned b = (unsigned)s->f10;
    d->s18 = b;
    unsigned c = (unsigned)s->f18;
    d->s12 = c;
    unsigned e = (unsigned)s->f1C;
    d->s14 = e;
    d->s40 = (int)(s->f20 * 10000.0f);
}
