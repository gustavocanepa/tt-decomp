/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short pad; void (*fn)(void *, int); };
struct Self { char pad[0x64]; char *vt; };
extern char D_005A0B88[];
extern "C" void func_004A4930(void *);
extern "C" void func_004A4970(void *);
extern "C" void func_004C6970(Self *self, int arg) {
    int *state = (int *)((char *)self + 0x234);
    func_004A4930(D_005A0B88);
    *state = 0;
    VEntry *e = (VEntry *)(*(char **)((char *)self + 0x64) + 0x18);
    e->fn((char *)self + e->delta, arg);
    func_004A4970(D_005A0B88);
}
