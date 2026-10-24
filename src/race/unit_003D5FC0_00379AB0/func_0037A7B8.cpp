/* compiler: ee-gcc2.96-no-strict-aliasing */
struct List { char pad[0x90]; int count; };
struct Obj { char pad[0x10]; List list; char pad2[0xF4 - 0x10 - sizeof(List)]; int index; };
extern "C" int func_003C80A8(List *, int);
extern "C" int func_0037A7B8(Obj *self) {
    int i = self->index;
    int n = self->list.count;
    List *l = &self->list;
    if (i >= n) return -1;
    return func_003C80A8(l, i);
}
