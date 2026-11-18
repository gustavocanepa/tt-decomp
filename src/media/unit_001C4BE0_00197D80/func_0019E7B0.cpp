/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Obj { char pad0[0x48]; u16 flags; char pad4A[0x178-0x4A]; unsigned time; };
extern "C" void GranTurismo4__GetTimeString(unsigned, char *, unsigned);
extern "C" void func_0019E7B0(Obj *self, char *out, unsigned cap) {
    u16 flag = self->flags & 1;
    if ((flag & 0xFFFF) != 0) return GranTurismo4__GetTimeString(self->time, out, cap);
    *out = 0;
}
