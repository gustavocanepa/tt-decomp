/* The base class, named after its constructor (func_001D7DA0), keeps its vptr at +4. The
   derived class (named after its vtable) holds at +0x28 a member object with an inline
   constructor, whose vptr store (+0x2C) comes before the derived class's own. */
struct func_001D7DA0 {
    char pad[0x4];
    func_001D7DA0();
    virtual ~func_001D7DA0();
};

struct D_005AE140 {
    char pad[0x4];
    D_005AE140() {}
    virtual ~D_005AE140();
};

struct D_005ADEB0 : func_001D7DA0 {
    char pad8[0x20];
    D_005AE140 member;
    D_005ADEB0();
    virtual ~D_005ADEB0();
};

D_005ADEB0::D_005ADEB0() {
}
