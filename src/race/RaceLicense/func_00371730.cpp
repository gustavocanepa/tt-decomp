typedef int s32;

struct Sub { s32 m0; };
struct Self { char pad[0x3A8C0]; Sub sub; };
extern "C" void *func_003C8690(Sub *);
extern "C" void func_00388F30(void *);

extern "C" void func_00371730(Self *self) {
    Sub *p = &self->sub;
    if (p->m0 != 0) {
        func_00388F30(func_003C8690(p));
    }
}
