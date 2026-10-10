/* The base class, named after its constructor (func_00202968), keeps its vptr at +4. The
   derived class (named after its vtable) holds at +0x28 a member object with an inline
   constructor, whose vptr store (+0x2C) comes before the derived class's own. */
struct func_00202968 {
    char pad[0x4];
    func_00202968();
    virtual ~func_00202968();
};

struct D_005AC110 {
    char pad[0x4];
    D_005AC110() {}
    virtual ~D_005AC110();
};

struct D_005ABD98 : func_00202968 {
    char pad8[0x20];
    D_005AC110 member;
    D_005ABD98();
    virtual ~D_005ABD98();
};

D_005ABD98::D_005ABD98() {
}
