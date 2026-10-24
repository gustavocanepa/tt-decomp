/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long long s64;
struct Info { u32 n; s32 pad; s32 *tbl; };
struct Mid { char pad[0x60]; Info *info; };
struct Obj { char pad0[0x6C]; Mid *mid; };
struct Car { char pad[0x160]; u8 a; u8 b; char pad2[3]; char flag; };
struct Spec;
extern "C" {
s64 func_0040CFE0(s64 *);
s32 func_0040DE88(void *);
s32 func_0040DEC8(void *);
void func_0040E4A0(void *, s64);
void func_004468F8b(void *, s64) __asm__("func_0040E4A0");
s32 func_0040F0F8(void *);
void func_00411E18(void *);
void func_00411E38(void *, s32);
s32 func_00411ED0(void *, s64);
s64 func_00412108(void *, s64, s32);
struct Mid2 { char pad[0x60]; Info *info; char pad2[4]; void *spec; };
struct Obj2 { char pad0[0x6C]; struct M3 *m; };
struct M3 { char pad[0x60]; Info *info; void *spec; };
static inline void change(Car *c, void *sp, s32 x, s32 y) {
    if (func_00411ED0(sp, func_0040CFE0((s64 *)c))) {
        s64 r = func_00412108(sp, 0x19, x);
        if (r != -1) func_0040E4A0(c, r);
        r = func_00412108(sp, 0x1A, y);
        if (r != -1) func_0040E4A0(c, r);
    }
}
void func_0036DF90(Obj *self) {
    char sp[0x20];
    s32 w = -1;
    s32 i;
    Mid *mid = self->mid;
    s32 t = func_0040F0F8(*(void **)((char *)mid + 0x70));
    switch (t) {
    case 2: w = 0xB; break;
    case 3: w = 0xC; break;
    }
    func_00411E18(sp);
    i = 0;
    do {
        Car *c = (Car *)(mid->info->tbl[i] + 0xFD8);
        s32 a, b, x, y;
        if (c->flag) {
            a = c->a;
            b = c->b;
        } else {
            a = func_0040DE88(c);
            b = func_0040DEC8(c);
        }
        if (w == -1) {
            x = a;
            y = b;
        } else {
            x = y = w;
        }
        if (a != x || b != y || c->flag) {
            c->flag = 0;
            change(c, sp, x, y);
        }
        i++;
    } while (i <= 0);
    func_00411E38(sp, 2);
}
}
