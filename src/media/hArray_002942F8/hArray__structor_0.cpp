/* compiler: ee-gcc2.96-no-strict-aliasing */
struct D_00661688 {
    int f0;
    D_00661688() __asm__("func_002A7618");
    virtual ~D_00661688();
};

/* A standard-style allocator object: the default argument `Alloc()` of the vector constructor is
   a stack temporary passed by reference, which leaves an unused 16-byte slot in the frame. */
struct Alloc {
    Alloc() {}
    Alloc(const Alloc &) {}
};

struct Vector {
    Alloc a;
    int *start, *finish, *eos;
    Vector(const Alloc &al = Alloc()) : a(al), start(0), finish(0), eos(0) {}
};

struct D_005C38C8 : D_00661688 {
    int pad8[2];
    Vector items;
    int f60;
    D_005C38C8() __asm__("func_00294C60");
    virtual ~D_005C38C8();
};

D_005C38C8::D_005C38C8() : f60(0) {
}
