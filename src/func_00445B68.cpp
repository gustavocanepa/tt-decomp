struct Sub0047EE50 {
    char *base;
    int count;
};
struct Obj0047EE50 {
    int unk0;
    struct Sub0047EE50 sub;
};
extern "C" void func_00445CC0(char *arg0, void *arg1);

extern "C" void func_00445B68(struct Obj0047EE50 *arg0, void *arg1) {
    struct Sub0047EE50 *s = &arg0->sub;
    char *end = s->base + s->count * 20;
    char *p = s->base;

    while (p != end) {
        func_00445CC0(p, arg1);
        p += 20;
    }
}
