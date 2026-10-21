/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char pad[0xCC]; s32 b8; s32 bc; s32 c0; s32 c4; };
extern "C" {
s32 func_003DA5C8(void) throw();
s32 func_003DABE8(Obj *, s32, s32, s32, s32, s32) throw();
s32 func_003DC290(Obj *, s32, s32, s32, s32, s32) throw();
s32 func_003DCD08(Obj *, s32, s32, s32, s32, s32) throw();
s32 func_003DD318(Obj *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    if (o->b8 != 0 && func_003DA5C8() != 1) return 0;
    if (o->bc != 0 && func_003DABE8(o, a1, a2, a3, a4, a5) != 1) return 0;
    if (o->c0 != 0 && func_003DC290(o, a1, a2, a3, a4, a5) != 1) return 0;
    if (o->c4 != 0 && func_003DCD08(o, a1, a2, a3, a4, a5) != 1) return 0;
    return 1;
}
}
