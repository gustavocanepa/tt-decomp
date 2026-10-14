/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef float f32; typedef unsigned short u16;

struct Rec { char pad0[6]; u16 h6; };
struct Tab { char pad0[0x1C]; char *p1C; };
struct Mid { char pad0[0xCC]; Tab *pCC; };
struct Root { char pad0[4]; Mid *p4; };
struct Obj {
    Root *root;
    char pad4[0xBC - 4];
    s32 iBC;
    f32 fC0, fC4, fC8;
};

extern "C" f32 func_00317438(f32);
extern "C" f32 func_003174F8(f32, f32);
extern "C" s32 func_00319860(void *, f32);
extern "C" void func_003AA3E8(void *, void *, s32, s32);

extern "C" s32 func_00319888(Obj *self, s32 *flag, f32 *width, s32 a3, s32 idx, f32 ang) {
    f32 sp[4];
    s32 ok = 1;
    Rec *rec = (Rec *)(self->root->p4->pCC->p1C + (idx << 6));
    *flag = 0;
    func_003AA3E8(sp, self->root, a3, idx);
    if (ang < sp[0] && func_00319860(sp, ang) == 0) {
        ang += 360.0f;
    }
    if (sp[0] < ang && func_00319860(sp, ang) == 0) {
        ang -= 360.0f;
    }
    if (func_00319860(sp, ang) == 0) {
        f32 t = func_00317438(sp[0]);
        ang = t + func_003174F8(func_00317438(ang), t);
    }
    if (ang - *width * 0.5f < sp[1]) {
        *width = 2.0f * (ang - sp[1]);
        *flag = 1;
    }
    if (sp[2] < ang + *width * 0.5f) {
        *width = 2.0f * (sp[2] - ang);
        *flag = 1;
    }
    if (ang <= sp[1]) ok = 0;
    if (sp[2] <= ang) ok = 0;
    if (*width < 0.001f) ok = 0;
    if (ok == 0) *width = 0.001f;
    s32 h = rec->h6;
    self->iBC = h >= 2;
    self->fC8 = sp[2];
    self->fC4 = sp[1];
    self->fC0 = sp[0];
    return ok;
}
