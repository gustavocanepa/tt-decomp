/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Ent { s32 a; s32 b; };
struct O {
    char pad0[0x64];
    s32 cnt;
    char pad1[0xA4 - 0x68];
    Ent e[1];
};
struct P { char pad[0x58]; s32 idx; };
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_004C18E0(O *self, P *p) {
    int i=p->idx;
    if (self->e[i].a != 0) {
        func_004F6678((void *)(i*8+(int)self+0xA4), 0, 8);
        self->cnt = self->cnt - 1;
    }
}
