/* compiler: ee-gcc2.96-as2004 */
/* The base class, named after its constructor (RaceDisplayObjectBase__structor_0); its vptr sits after 0x14 bytes. */
struct RaceDisplayObjectBase__structor_0 {
    char pad[0x14];
    RaceDisplayObjectBase__structor_0();
    virtual ~RaceDisplayObjectBase__structor_0();
};

/* A member object, named after its constructor. */
struct func_0035E778 {
    func_0035E778();
    int m0;
};

/* Named after its vtable (0x0067E448) so that _vt$10D_0067E448 resolves. */
struct D_005C9130 : RaceDisplayObjectBase__structor_0 {
    int m18;
    int slots[6];
    char pad[0xC];
    int m40;
    int m44;
    func_0035E778 m48;
    D_005C9130();
    virtual ~D_005C9130();
};

D_005C9130::D_005C9130()
{
    m18 = 0;
    for (int i = 5; i >= 0; i--)
        slots[i] = 0;
    m40 = 0;
    m44 = 0;
}
