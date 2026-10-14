/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct Node { Node *next; char *vt; };
struct List { s32 pad0; Node *head; };
struct Res { char pad[0x18]; s32 f18; };
extern Res *D_0058493C;
extern "C" int func_00467728(Res *);
extern "C" void func_0046AC48(s32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_004702D8(s32, float);
extern "C" void func_00470388(s32, s32);
extern "C" void func_00470478(s32);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_00478C98(s32);

extern "C" void func_003936E0(List *self) {
    if (self->head) {
        if (D_0058493C) {
            func_00467728(D_0058493C);
            func_0046AC48(D_0058493C->f18);
        }
        func_0046F0F8(5);
        func_0046F0F8(4);
        func_0046F0F8(6);
        func_0046F0F8(2);
        func_00478C98(0xF);
        func_00470478(0);
        func_00470388(6, 1);
        func_004702D8(0x68, 1.0f);
        for (Node *n = self->head; n; n = n->next) {
            VEntry *e = (VEntry *)(n->vt + 0x18);
            e->fn((char *)n + e->delta);
        }
        func_00473050();
        func_004751FC();
        func_004730A8();
        func_00470478(1);
        func_0046F0F8(0xF);
        func_00478C98(2);
    }
}
