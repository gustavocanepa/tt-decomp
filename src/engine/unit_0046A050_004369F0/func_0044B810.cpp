/* compiler: ee-gcc2.96-nsa-nosched1 */
typedef int s32;

/* The base class, named after its constructor (func_00443F98); its vptr sits at 0x5C. */
struct func_00443F98 {
    char pad[0x5C];
    func_00443F98(s32 a, s32 b, s32 c, s32 d, s32 e);
    virtual ~func_00443F98();
};

struct List {
    s32 count;
    List *next;
    List *prev;
    void init() { prev = this; count = 0; next = this; }
};

/* Named after its vtable (0x00688AE0). */
struct D_005D9F38 : func_00443F98 {
    s32 m60, m64, m68, m6C, m70;
    List l74;
    List l80;
    s32 m8C;
    s32 pad90[2];
    s32 m98;
    D_005D9F38(s32 a, s32 b, s32 c, s32 d, s32 e);
    virtual ~D_005D9F38();
};

extern "C" void func_0044B890(D_005D9F38 *self, s32 c, List *l);

/* Compiled without sched1 (ee-gcc2.96-nsa-nosched1): the &l80 argument copy stays after the
 * list stores, so &l80 lives in $a2 itself. */
D_005D9F38::D_005D9F38(s32 a, s32 b, s32 c, s32 d, s32 e) : func_00443F98(a, b, c, d, e) {
    m60 = 0;
    m64 = 0;
    m68 = 0;
    m6C = 0;
    m70 = 0;
    l74.init();
    l80.init();
    m8C = 0;
    m98 = 0;
    func_0044B890(this, c, &l80);
}
