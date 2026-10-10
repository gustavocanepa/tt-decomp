typedef int s32;

struct Obj {
    char pad0[0x4C];
    void *vtbl;
    s32 pad50;
    void *buf54;
    char pad58[0x19C - 0x58];
    void *buf154;
};

void func_0019B480(struct Obj *, s32);
void func_004A45D0(void *);
void func_0050E1A8(void *);

extern char D_005ACD40[];
extern char D_005AD0C8[];
extern char D_005AD350[];

void func_00521198(struct Obj *self, s32 flags) {
    self->vtbl = D_005AD350;
    if (self->buf154 != 0) {
        func_004A45D0(self->buf154);
    }
    self->vtbl = D_005ACD40;
    if (self->buf54 != 0) {
        func_004A45D0(self->buf54);
    }
    self->vtbl = D_005AD0C8;
    func_0019B480(self, 0);
    if (flags & 1) {
        func_0050E1A8(self);
    }
}
