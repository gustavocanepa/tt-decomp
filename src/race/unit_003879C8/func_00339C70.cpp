/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Item {
    const char *name;
    s32 pad4;
    s32 (*fn8)(void);
    s32 (*fnC)(void *, s32);
};
struct Node {
    Node *next;
    Item *item;
};
extern Node *D_00583EE4;
extern "C" s32 func_004A8268(const char *, const char *) throw();

extern "C" s32 func_00339C70(const char *arg0, void *arg1, s32 arg2) {
    Node *n = D_00583EE4;
    while (n != 0) {
        if (func_004A8268(arg0, n->item->name) == 0) {
            if (arg1 == 0) {
                return n->item->fn8();
            }
            return n->item->fnC(arg1, arg2);
        }
        n = n->next;
    }
    return 0;
}
