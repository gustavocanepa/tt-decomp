/* The base class, named after its constructor (func_001B4540), keeps its vptr at +4. The
   derived class (named after its vtable) holds at +0x28 a member object with an inline
   constructor, whose vptr store (+0x2C) comes before the derived class's own. */
struct func_001B4540 {
    char pad[0x4];
    func_001B4540();
    virtual ~func_001B4540();
};

struct D_005BED00 {
    char pad[0x4];
    D_005BED00() {}
    virtual ~D_005BED00();
};

struct D_005BE948 : func_001B4540 {
    char pad8[0x20];
    D_005BED00 member;
    D_005BE948();
    virtual ~D_005BE948();
};

D_005BE948::D_005BE948() {
}
