typedef int s32;
typedef short s16;
typedef float f32;

struct Node {
    Node *next;
    void **vtbl;
};

struct Obj {
    char pad0[4];
    Node *head;
};

struct VEntry_003C2780 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self, s32 arg1, f32 f);
};

extern "C" void ParticleManager__remove(Obj *arg0, Node *arg1, void **arg2);

extern "C" void ParticleManager__Update(Obj *arg0, s32 arg1, f32 fparg0) {
    Node *prev = 0;
    Node *n = arg0->head;
    while (n != 0) {
        Node *next = n->next;
        VEntry_003C2780 *e = (VEntry_003C2780 *)((char *)n->vtbl + 0x10);
        if (e->fn((char *)n + e->delta, arg1, fparg0) == 0) {
            ParticleManager__remove(arg0, n, (void **)prev);
        } else {
            prev = n;
        }
        n = next;
    }
}
