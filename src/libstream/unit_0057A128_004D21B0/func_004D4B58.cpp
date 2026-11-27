/* compiler: ee-gcc2.9-991111 */
typedef unsigned short u16;
struct Obj {
    unsigned magic0;
    unsigned magic1;
    struct Obj *next;
    struct Obj *child;
    char pad10[6];
    u16 flags;
};
extern Obj *D_0077A028;
extern "C" int func_004D4B58(Obj *o, int *flaggedOut) {
    Obj **link;
    Obj *c;
    int total;
    int flagged;
    if (o == 0 || o->magic0 != 0x4C785265 || o->magic1 != 0x41004269) return 0x81059039;
    for (link = &D_0077A028; *link != 0 && *link != o; link = &(*link)->next) {
    }
    if (*link != o) return 0x81059037;
    total = 0;
    flagged = 0;
    for (c = o->child; c != 0; c = c->child) {
        if (c->flags & 8) flagged++;
        total++;
    }
    if (flaggedOut != 0) *flaggedOut = flagged;
    return total;
}
