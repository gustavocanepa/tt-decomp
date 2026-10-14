struct Elem { char pad[0x10]; };
struct Array {
    Elem *data; int count;
    int size() const { return count; }
    Elem &operator[](int i) { return data[i]; }
};
struct Obj { char pad[0xB0]; Array items; };
extern "C" void func_0043FD90(Elem *e, int arg);
extern "C" void func_0043AD60(Obj *o, int arg) {
    for (int i = 0; i < o->items.size(); i++)
        func_0043FD90(&o->items[i], arg);
}
