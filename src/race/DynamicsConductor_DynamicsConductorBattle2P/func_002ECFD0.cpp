/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad[0x138];
    short slots[10];
    char pad2[10];
    unsigned char enabled;
    unsigned char level;
};
extern "C" void func_002F8C40(Obj *, int, short *, int);
extern "C" int func_002ECFD0(Obj *o) {
    if (!o->enabled) return 0;
    if (!o->level) return 0;
    int n;
    if (o->level == 255) n = 255;
    else n = o->level * 10;
    short empty = -1;
    for (int i = 9; i >= 0; i--) o->slots[i] = empty;
    func_002F8C40(o, n, o->slots, 0);
    return 1;
}
