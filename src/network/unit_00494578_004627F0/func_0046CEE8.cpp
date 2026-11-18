/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned int u128 __attribute__((mode(TI)));
struct Obj { char pad0[0x18]; u32 f18; char pad1c[0x14]; u32 f30,f34,f38,f3c; char pad40[0x1bc]; u128 *cursor; char pad200[0x9b0]; u128 bb0,bc0; };
extern u128 D_0076E780[];
extern "C" void func_0046CEE8(Obj *o) {
 u128 *p=o->cursor-6;
 o->cursor=p;
 u32 addr=(u32)p&0x0fffffff;
 u32 size=0x259;
 u32 tag=0x30000006;
 u32 command=0x6c06c0c9;
 p[0]=D_0076E780[0];
 p[1]=D_0076E780[1];
 p[2]=D_0076E780[2];
 p[3]=D_0076E780[3];
 p[4]=o->bb0;
 p[5]=o->bc0;
 o->f3c=command;
 o->f18=size;
 o->f30=tag;
 o->f34=addr;
 o->f38=0;
}
