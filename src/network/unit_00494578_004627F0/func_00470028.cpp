/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
struct Obj { char pad0[0x170]; u16 dst0; u8 dst2, dst3; char pad1[0x1d8-0x174]; u64 flags; char pad2[0x260-0x1e0]; u16 src0; u8 src2,src3; };
extern "C" void func_00470028(Obj *p) {
    u64 flags = p->flags | 0x10001;
    u16 a = p->src0 >> 5;
    u8 b = p->src2;
    u8 c = p->src3;
    p->dst0 = a;
    p->dst2 = b;
    p->dst3 = c;
    p->flags = flags;
}
