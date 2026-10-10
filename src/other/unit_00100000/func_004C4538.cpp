extern "C" char D_005A0B88[];
extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);

struct Obj {
    int f0;
    int value;
};

extern "C" void func_004C4538(Obj *o, int value) {
    void *lock = D_005A0B88;
    func_004A4930(lock);
    o->value = value;
    func_004A4970(lock);
}
