/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

struct VE2 { s16 delta; s16 index; void (*fn)(void *, s32, s32); };
struct VE0 { s16 delta; s16 index; void (*fn)(void *); };
struct VT { char pad[0x20]; VE0 e20; char pad2[0x10]; VE2 e38; VE2 e40; };
struct Base {
    char pad[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void update();
    virtual void v4();
    virtual void v5();
    virtual void position(s32, s32);
    virtual void size(s32, s32);
};
struct Sub : Base { f32 m18; char pad2[0x14]; };
struct Self {
    char pad0[1];
    u8 m1;
    u8 m2;
    char pad3;
    s16 m4;
    s16 m6;
    s16 m8;
    s16 mA;
    char padC[0xC];
    f32 m18;
    f32 m1C;
    Sub items[2];
};

extern "C" s32 func_0038F4A8(s32, s32, s32);

extern "C" void RaceABMonitor__update(Self *self) {
    Sub *a = &self->items[0];
    Sub *b = &self->items[1];
    Sub *p = a;
    s32 i = 1;
    s32 x, y;
    a->m18 = self->m18;
    b->m18 = self->m1C;
    x = func_0038F4A8(self->m4, self->m8, self->m1);
    y = func_0038F4A8(self->m6, self->mA, self->m2) + 4;
    ((Base *)&self->items[0])->position(x + self->m8 - 5, y);
    ((Base *)&self->items[1])->position(x + 1, y);
    ((Base *)&self->items[0])->size(4, 0x38);
    ((Base *)&self->items[1])->size(4, 0x38);
    for (i = 0; i < 2; i++) {
        ((Base *)&p[i])->update();
    }
}
