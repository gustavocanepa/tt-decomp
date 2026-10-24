#include "types.h"
struct Item { char pad[0x166]; char flag; char pad2[0x190 - 0x167]; };
struct Obj { char pad[8]; Item items[3]; char pad2[0x4E8 - 8 - 3 * 0x190]; char sub[1]; };
extern "C" void func_002E4588(void *, int);
extern "C" void func_002E4A68(void *);
extern "C" void func_00405700(unsigned char *);
extern "C" void func_004070B8(void *);
extern "C" int func_0040BE90(void *, s64);
extern "C" int func_004107B0(long, void *);
extern "C" int func_004108E0(void *);
extern "C" int func_00408750(Obj *o, long arg) {
    char buf[0x20];
    int i = 0;
    Item *it;
    int fl;
    int r;
    func_00405700((unsigned char *)o);
    func_004107B0(arg, buf);
    it = o->items;
    fl = func_004108E0(buf) != 0;
    do {
        r = func_0040BE90(it, arg);
        if (r == 0) return r;
        i++;
        it->flag = fl;
        it++;
    } while (i < 3);
    func_004070B8(o);
    func_002E4588(o->sub, fl);
    func_002E4A68(o->sub);
    return 1;
}
