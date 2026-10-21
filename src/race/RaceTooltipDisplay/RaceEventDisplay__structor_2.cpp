/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32); };
struct ElemV { char pad[0x14]; char *vtbl; char pad2[0x150 - 0x18]; };

extern char D_005D0810[];
extern char D_005D1230[];
extern char D_005D1290[];

extern "C" void func_0038E308(void *, s32);
extern "C" void func_0050E1A8(void *) throw();

struct Base { char pad[0x14]; virtual ~Base(); };
struct Elem : Base { char rest[0x138]; virtual ~Elem(); };
struct Sub { char pad[0x50]; Elem elems[8]; ~Sub() { *(char **)(pad + 0x14) = D_005D1230; } };
static inline void destroy_sub(char *sub) {
    ((Sub *)sub)->~Sub();
    func_0038E308(sub, 0);
}
extern "C" void RaceEventDisplay__structor_2(char *self, s32 flags) {
    *(char **)(self + 0x14) = D_005D0810;
    destroy_sub(self + 0x18C);
    char *m = self + 0x3C;
    *(char **)(m + 0x14) = D_005D1290;
    func_0038E308(m, 0);
    func_0038E308(self, 0);
    if (flags & 1) return func_0050E1A8(self);
}
