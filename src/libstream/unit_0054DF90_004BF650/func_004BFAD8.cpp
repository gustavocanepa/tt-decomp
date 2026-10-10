inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Manager {
    Manager() __asm__("func_005738B8");
};

extern Manager *D_005987D8;
extern char D_00777300[];

extern "C" void func_004AC838(Manager *m, void *arg);

static inline Manager *instance() {
    if (D_005987D8 == 0)
        D_005987D8 = new (D_00777300) Manager;
    return D_005987D8;
}

extern "C" void func_004BFAD8(void *arg) {
    func_004AC838(instance(), arg);
}
