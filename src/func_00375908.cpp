/* compiler: ee-gcc2.96-nsa-nosib */
struct List { int count; int pad4; void **items; };
struct Obj { char pad[0x60]; List *list; };
extern "C" void func_003695A8(void *, int);
extern "C" void func_00375908(Obj *self, int index) {
    int n = self->list->count;
    if (index < n) {
        if (index >= 0) {
            func_003695A8(self->list->items[index], 1);
            return;
        }
        for (int i = 0; i < n; i++)
            func_003695A8(self->list->items[i], 1);
    }
}
