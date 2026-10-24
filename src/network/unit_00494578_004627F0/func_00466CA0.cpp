/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned long long u64;
struct Entry { u64 low:37; u64 value:14; u64 kind:4; u64 gap:1; u64 last:5; u64 high:3; char pad[32]; };
struct List { int count; u32 *data[1]; };
struct Obj { char pad[16]; unsigned short offset; char pad12[6]; Entry *entries; char pad1c[4]; List *list; };
extern "C" void func_00466CA0(Obj *o, int index) {
    u32 *p = (u32 *)o->list;
    if (p && index >= 0) {
        int n = *p++;
        if (index >= n) return;
        p = ((u32 **)p)[index];
        n = *p++;
        n &= 65535;
        u64 off = o->offset;
        while (--n != -1) {
                u32 v = *p++;
                o->entries[v >> 23].kind = (v >> 19) & 15;
                o->entries[v >> 23].value = (u64)((v >> 5) & 16383) + off;
                o->entries[v >> 23].last = v & 31;
        }
    }
}
