/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xAC]; int x; };
struct Node { char pad[0x38]; Obj *owner; char pad3c[12]; int handle; };
extern "C" void func_00481508(void *);
extern "C" Node *func_00481598();
extern "C" int func_004816B0(int);
extern "C" int func_004816D0(int);
extern "C" void func_004816F0(int);
extern "C" void func_0047CB90(void *, void *);
extern "C" int func_0047E208(int, const char *);
extern "C" void func_0047E3E8(int, int);
extern "C" int func_004A8368(const char *) throw();
extern "C" Node *func_00481050(Obj *arg0, const char *arg1, Node *arg2) {
    Node *node = arg2;
    if (node) {
        func_00481508(node);
        node->owner = arg0;
    } else {
        node = func_00481598();
        if (!node) return node;
        node->owner = arg0;
    }
    int h = func_004816B0(func_004A8368(arg1) + 2);
    node->handle = h;
    int p = func_004816D0(h);
    func_0047E3E8(p, func_0047E208(arg0->x, arg1));
    func_004816F0(h);
    func_0047CB90(arg0, node);
    return node;
}
