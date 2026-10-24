extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);
extern "C" char D_005A0B88[];

struct Obj {
    char pad[0x2C28];
    void *head;
};

struct Node {
    char pad[0xC];
    void *next;
};

extern "C" void func_004C7260(Obj *arg0, Node *arg1) {
    void *lock = D_005A0B88;
    func_004A4930(lock);
    arg1->next = arg0->head;
    arg0->head = arg1;
    func_004A4970(lock);
}
