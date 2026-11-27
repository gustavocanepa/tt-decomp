/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef float f32; typedef unsigned short u16;

struct Rec { char pad0[6]; u16 h6; char pad8[0x10]; f32 f18, f1C; };
struct Tab { char pad0[0x1C]; char *p1C; };
struct Mid { char pad0[0xCC]; Tab *pCC; };
struct Root { char pad0[4]; Mid *p4; };
struct Obj {
    Root *root;
    char pad4[0x44];
    f32 f48[4];
    f32 f58[2];
    f32 f60[3];
    f32 f6C, f70, f74;
    char pad78[0x84 - 0x78];
    s32 i84;
    f32 f88[2];
    char pad90[0xCC - 0x90];
    f32 fCC;
};

extern "C" f32 func_00317438(f32) throw();
extern "C" f32 func_00317630(f32, f32);
extern "C" f32 func_00317E40(void *) throw();
extern "C" void func_00319760(Obj *, void *, s32) throw();
extern "C" void func_00319A68(Obj *, f32 *, f32 *, void *, s32) throw();
extern "C" void func_00378858(void *, f32 *);

extern "C" void func_00319BB0(Obj *self, s32 idx, f32 *pos, s32 flag) {
    f32 sp0;
    f32 sp10[2];
    f32 *p60 = self->f60;
    f32 *p8 = (f32 *)((char *)pos + 8);
    sp0 = func_00317E40(self->f48);
    Tab *tab = self->root->p4->pCC;
    f32 x = pos[0];
    f32 z = *p8;
    self->f60[0] = x;
    self->f60[1] = 100.0f;
    self->f60[2] = z;
    self->i84 = -1;
    func_00319760(self, p60, idx);
    sp10[0] = pos[0];
    sp10[1] = *p8;
    func_00378858(self->f88, sp10);
    Rec *rec = (Rec *)(tab->p1C + (idx << 6));
    if (rec->h6 != 0 || flag != 0) {
        f32 pz;
        f32 dx = rec->f18 - pos[0];
        pz = *p8;
        f32 dy = rec->f1C - pz;
        f32 d = func_00317630(dx, dy);
        f32 v = func_00317438(d + 90.0f);
        f32 *ang = &self->f6C;
        *ang = v;
        self->f70 = 0;
        self->f74 = 0;
    }
    func_00319A68(self, &sp0, &self->f6C, p60, idx);
    self->fCC = sp0;
}
