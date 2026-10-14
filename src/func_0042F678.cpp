typedef unsigned short u16;
typedef int s32;

struct Buf {
    char pad0[8];
    u16 a;
    u16 b;
    char pad1[4];
};

struct Ser_0044D140 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
    virtual s32 v4();
};

extern "C" void *func_0042F638(void *arg0, void *arg1);

extern "C" s32 Serialize__Base__probe(Ser_0044D140 *self, void *arg1) {
    Buf buf;
    func_0042F638(&buf, arg1);
    u16 x = buf.b;
    if (x != self->v3()) {
        return 2;
    }
    u16 y = buf.a;
    return (y ^ self->v4()) != 0;
}
