struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Obj { char pad[8]; VEntry *vtbl; };
extern "C" void func_00473050();
extern "C" void func_004730A8();
extern "C" float func_0041CEF8(void *);

extern "C" float func_00345F68(Obj *arg0, float value) {
    func_00473050();
    VEntry *entry = &arg0->vtbl[41];
    entry->fn((char *)arg0 + entry->delta, value);
    float result = func_0041CEF8((char *)arg0 + 0x18);
    func_004730A8();
    return result;
}
