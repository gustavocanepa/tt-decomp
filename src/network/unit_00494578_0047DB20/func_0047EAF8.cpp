struct VEntry { short delta; short index; void (*fn)(void *); };
struct Conn {
    char pad[0x38]; void *owner;
    char pad2[0x80 - 0x3C]; int closed; int state;
    char pad3[0xA8 - 0x88]; char *vtbl;
};
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0047CED8(void *, Conn *);

extern "C" void func_0047EAF8(Conn *c)
{
    int notify = 0;
    func_004A4D68(c);
    if (!c->closed) {
        if (c->owner) {
            func_0047CED8(c->owner, c);
        } else {
            c->state = 4;
            notify = 1;
        }
    }
    func_004A4DD8(c);
    if (notify) {
        VEntry *e = (VEntry *)(c->vtbl + 0x48);
        e->fn((char *)c + e->delta);
    }
}
