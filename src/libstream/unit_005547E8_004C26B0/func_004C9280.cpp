/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { char d[0x80]; };
struct Obj { char pad[0x3F8]; int dirty; };
extern Blk D_00779E80;
extern Blk D_00779F00;
extern "C" void func_004F43F0(Blk *, int);
extern "C" void func_004C9280(Obj *o) {
    if (o->dirty != 0) {
        o->dirty = 0;
        func_004F43F0(&D_00779E80, 0x80);
        D_00779F00 = D_00779E80;
    }
}
