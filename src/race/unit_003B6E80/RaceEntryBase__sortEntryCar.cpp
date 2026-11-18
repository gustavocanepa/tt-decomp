/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Obj;

struct Node {
    f32 key;
    Node *prev;
    Node *next;
    char pad0[0xC];
    Obj *obj;
};

struct List {
    u32 count;
    s32 pad4;
    Node **arr;
    Node *head;
    Node *tail;
};

extern "C" f32 func_002E5E40(Obj *, f32);
extern "C" f32 func_002E5EA0(Obj *, f32);
extern "C" f32 func_002E5ED0(Obj *, f32);

static inline float sqrt_s(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void RaceEntryBase__sortEntryCar(List *list, f32 x, f32 y, f32 z) {
    u32 i = 0;
    list->head = 0;
    list->tail = 0;
    if (list->count != 0) {
        do {
            Node *node = list->arr[i];
            Obj *o = node->obj;
            f32 dx = func_002E5E40(o, 0.0f) - x;
            f32 dy = func_002E5EA0(o, 0.0f) - y;
            f32 dz = func_002E5ED0(o, 0.0f) - z;
            f32 d = sqrt_s(dx * dx + dy * dy + dz * dz);
            Node *prev = 0;
            Node *cur;
            node->key = d;
            for (cur = list->head; cur != 0; cur = cur->next) {
                if (d < cur->key) break;
                prev = cur;
            }
            if (prev != 0) prev->next = node;
            else list->head = node;
            if (cur != 0) cur->prev = node;
            else list->tail = node;
            node->prev = prev;
            i++;
            node->next = cur;
        } while (i < list->count);
    }
}
