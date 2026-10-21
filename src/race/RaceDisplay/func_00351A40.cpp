typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Msg {
    char pad0[0x18];
    f32 f18;
    f32 f1C;
    u32 color;
};

struct List { char pad[8]; char **items; };
struct Info { char pad[0x60]; List *list; };

struct Self {
    char pad0[4];
    Info *info;
    char pad8[0x2F - 8];
    signed char id2F;
    char pad30[0x1130 - 0x30];
    char m1170[0x263C - 0x1130];
    Msg m267C;
    char pad2698[0x278C - 0x263C - sizeof(Msg)];
    Msg m27CC;
};

extern char D_005F42F8[];
extern char D_005F4378[];
extern f32 D_005F4388;

extern "C" void func_00351CB0(Self *, s32, f32);
extern "C" void func_00359148(void *, f32);
extern "C" void RaceMessageDisplay__setMessage(void *, const char *, f32, f32);
extern "C" void RaceMessageDisplay__setFont(void *, const char *, s32);
extern "C" void RaceDisplayObjectBase__setLocation(void *, s32, s32);
extern "C" void RaceDisplayUtil__timeToString(char *, s32);

extern "C" void func_00351A40(Self *self, s32 arg1) {
    char buf[0x80];
    Msg *m1 = &self->m267C;
    Msg *m2 = &self->m27CC;
    char *s4 = self->info->list->items[self->id2F];
    RaceMessageDisplay__setFont(m1, D_005F42F8, 1);
    m1->color = 0x80C8C8C8;
    m1->f18 = 0.15f;
    m1->f1C = 0.15f;
    RaceDisplayObjectBase__setLocation(m1, 0x140, 0xC8);
    RaceMessageDisplay__setMessage(m1, s4 + 0x5464, 8.0f, 0.0f);
    RaceDisplayUtil__timeToString(buf, arg1);
    RaceMessageDisplay__setFont(m2, D_005F4378, 1);
    m2->color = 0x80C8C8C8;
    m2->f18 = 0.15f;
    m2->f1C = 0.15f;
    RaceDisplayObjectBase__setLocation(m2, 0x140, 0x10E);
    RaceMessageDisplay__setMessage(m2, buf, 8.0f, 0.0f);
    func_00351CB0(self, 0, 1.0f);
    func_00359148(self->m1170, D_005F4388);
}
