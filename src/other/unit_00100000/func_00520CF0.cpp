/* compiler: ee-gcc2.96-no-strict-aliasing */
struct D_00661688 {
    int f0;
    char pad4[0x48 - 4];
    short f48;
    short f4A;
    D_00661688() __asm__("func_0019B400");
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

struct D_005ACD40 : D_00661688 {
    Vector items;
    int f60;
    D_005ACD40() __asm__("func_00520CF0");
    virtual ~D_005ACD40();
};

D_005ACD40::D_005ACD40() : f60(0) {
}
