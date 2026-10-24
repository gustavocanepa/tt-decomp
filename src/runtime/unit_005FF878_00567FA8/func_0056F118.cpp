/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct O { char pad[0x10]; char c10[0x98]; s32 *uA8; };
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004AC8B8(void *, void *);
extern "C" s32 func_0056F118(O *o) {
    char *lock = o->c10;
    s32 r = 0;
    func_004A4D68(lock);
    s32 **slot = &o->uA8;
    s32 *p = *slot;
    if (p != 0) {
        func_004AC8B8(slot, p);
        r = *p;
    }
    func_004A4DD8(lock);
    return r;
}
