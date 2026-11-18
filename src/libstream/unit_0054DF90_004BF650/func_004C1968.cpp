/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot { int first; int second; };
struct Obj { char pad0[0x64]; int count; int pad68; Slot slots[1]; };
struct Arg { char pad0[0x58]; int index; };
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_004C1968(Obj *o, Arg *a) {
    int index = a->index;
    if (o->slots[index].first != 0) {
        func_004F6678((void *)(index * 8 + (int)o + 0x6C), 0, 8);
        o->count--;
    }
}
