/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

/* The base class, named after its copy constructor (func_002A7650) so that
   __13func_0030A6B0RC13func_0030A6B0 resolves. The vptr sits after its 4 bytes of data. */
struct func_002A7650 {
    s32 m0;
    func_002A7650(const func_002A7650 &);
    virtual ~func_002A7650();
};

/* No known name: named after its vtable (0x00673D60) so that _vt$10D_00673D60 resolves.
   A real C++ copy constructor gives the original's register homes and scheduling. */
struct D_005C4390 : func_002A7650 {
    s32 m8;
    s32 mC;
    f32 m10;
    D_005C4390(const D_005C4390 &o);
    virtual ~D_005C4390();
};

D_005C4390::D_005C4390(const D_005C4390 &o) : func_002A7650(o), m10(o.m10) {
}
