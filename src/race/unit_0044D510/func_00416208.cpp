/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef float f32;

struct Cam { char pad[0x28]; f32 f28; char pad2[0x48 - 0x2C]; f32 f48; };
struct Self {
    char pad[0x14];
    void *f14;
    char pad2[0x5C - 0x18];
    void *f5C;
    char pad3[0x80 - 0x60];
    Cam *f80;
};
struct E { s16 delta; s16 index; void (*fn)(void *, f32); };
struct Obj { E *vtbl; };

extern "C" s32 ModelSet2__begin(void *, void *);
extern "C" void ModelSet2__end(void *);
extern "C" void ModelSet2__render(void *, void *);
extern "C" int ModelSet2___render(void *, int, void *);
extern "C" void func_0046F0F8(s32);
extern "C" void func_00470E60(s32);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_00475248(void);
extern "C" void func_00475730(f32);
extern "C" void func_00475758(f32);
extern "C" void func_00478C98(s32);

extern "C" void func_00416208(Self *self, Obj *obj, u16 *list) {
    func_0046F0F8(5);
    func_00478C98(4);
    func_00470E60(3);
    func_00473050();
    {
        E *e = (E *)((char *)obj->vtbl + 0x18);
        e->fn((char *)obj + e->delta, 0.0f);
    }
    func_00473050();
    func_00475248();
    func_00475730(self->f80->f48);
    func_00475758(self->f80->f28);
    ModelSet2__render(self->f5C, 0);
    func_004730A8();
    func_00470E60(2);
    if (list != 0) {
        s32 i = *list;
        u16 *p = list + 1;
        ModelSet2__begin(self->f14, 0);
        i = (i + 0xFFFF) & 0xFFFF;
        while (i != 0xFFFF) {
            u16 a = *p;
            p++;
            ModelSet2___render(self->f14, a, 0);
            i = (i + 0xFFFF) & 0xFFFF;
        }
        ModelSet2__end(self->f14);
    } else {
        ModelSet2__render(self->f14, 0);
    }
    func_004730A8();
}
