extern char D_005A0B88[];

extern "C" void func_004A4930(void *m);
extern "C" void func_004A4970(void *m);

struct Obj {
    char pad[0xA4];
    int nextId;
};

extern "C" int func_004C6FE0(Obj *o) {
    func_004A4930(D_005A0B88);
    int id = o->nextId;
    int next = id + 1;
    if (next == 0x7FFFFFFF)
        next = 0;
    o->nextId = next;
    func_004A4970(D_005A0B88);
    return id;
}
