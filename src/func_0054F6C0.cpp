struct Node {
    Node *unk0;
    void *unk4;
};
struct Obj {
    char pad0[4];
    Node *unk4;
};

extern "C" void func_002B1578(void *, int);
extern "C" void func_002BDA70(void *, int, int);

extern "C" void func_0054F6C0(Obj *arg0) {
    Node *v0 = arg0->unk4;
    Node *s1 = v0->unk0;
    if (s1 != v0) {
        do {
            Node *s0 = s1;
            s1 = s1->unk0;
            func_002B1578((char *)s0 + 8, 2);
            func_002BDA70(s0, 0xC, 4);
            v0 = arg0->unk4;
            s0 = s1;
        } while (s1 != v0);
    }
    v0->unk0 = v0;
    v0 = arg0->unk4;
    v0->unk4 = v0;
}
