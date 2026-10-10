/* The base class, named after its constructor (func_001B8120), keeps its vptr at +4. The
   derived class (named after its vtable) holds at +0x28 a member object with an inline
   constructor, whose vptr store (+0x2C) comes before the derived class's own. */
struct func_001B8120 {
    char pad[0x4];
    func_001B8120();
    virtual ~func_001B8120();
};

struct D_005B7348 {
    char pad[0x4];
    D_005B7348() {}
    virtual ~D_005B7348();
};

struct D_005B6F90 : func_001B8120 {
    char pad8[0x20];
    D_005B7348 member;
    D_005B6F90();
    virtual ~D_005B6F90();
};

D_005B6F90::D_005B6F90() {
}
