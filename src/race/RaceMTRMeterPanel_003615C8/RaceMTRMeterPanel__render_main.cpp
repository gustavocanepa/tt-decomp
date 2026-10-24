/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Entry { short delta, index; void (*fn)(void *, void *); };
struct Sub { char pad[0x14]; Entry *vt; char rest[0x58]; };
struct Panel {
    char pad0[0xC];
    f32 fC;
    char pad10[8];
    s32 i18;
    void *p1C;
    Sub subs[4];
};
struct Pos { f32 x, y; };
extern f32 D_005F5928[];

extern "C" int func_00104838(char *);
extern "C" void func_00104868(void *, int);
extern "C" void func_00104C88(void *);
extern "C" void func_00104D10(s32 *);
extern "C" void RaceMTRMeterPanel__init_texset(Panel *) throw();
extern "C" void func_0038E838(void *, s32, s32, f32, f32, f32, f32);
extern "C" void func_0038EE10(f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_004702D8(s32, f32);
extern "C" void func_00470478(s32);
extern "C" void func_00472268(s32, s32);
extern "C" void func_00477E30(f32, f32, f32, f32);
extern "C" void func_00478C98(s32);

extern "C" void RaceMTRMeterPanel__render_main(Panel *self, void *arg) {
    char buf[0x40];
    if (self->i18 != 0) {
        Sub *s = self->subs;
        RaceMTRMeterPanel__init_texset(self);
        func_00478C98(5);
        func_00470478(0);
        func_0046F0F8(6);
        func_004702D8(0x44, 0.0f);
        func_00477E30(1.0f, 1.0f, 1.0f, self->fC);
        func_0038E838(self->p1C, 2, 1, 320.0f, 448.0f, 640.0f, 156.0f);
        s32 n = 3;
        func_00104838(buf);
        const f32 *pos = D_005F5928;
        do {
            Entry *e = s->vt + 6;
            e->fn((char *)s + e->delta, buf);
            s++;
            func_00104C88(arg);
            func_00104D10((s32 *)buf);
            func_00477E30(1.0f, 1.0f, 1.0f, self->fC);
            func_0046F0F8(6);
            func_004702D8(0x44, 0.0f);
            func_00472268(2, 1);
            func_00472268(3, 1);
            f32 x = pos[0];
            f32 y = pos[1];
            pos += 2;
            func_0038EE10(x, y, x + 128.0f, y + 128.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        } while (--n >= 0);
        func_00472268(2, 1);
        func_00472268(3, 1);
        func_00104868(buf, 2);
    }
}
