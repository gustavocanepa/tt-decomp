/* Named after their constructors so that the constructor calls resolve. */
struct func_0036F588 {
    char data[0x6A0];
    func_0036F588();
};

struct func_0036F300 {
    char data[0x60];
    func_0036F300();
};

struct Slot : func_0036F588 {
    func_0036F300 sub;
};

/* No known name: named after its vtable (0x006792C0). */
struct Base {
    virtual ~Base();
};

struct D_005C9188 : Base {
    virtual ~D_005C9188();
    int pad4[3];
    Slot slots[2];
    int mE10;
    int mE14;
    D_005C9188();
};

D_005C9188::D_005C9188() {
    mE10 = 0;
    mE14 = 0;
}
