/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Raw { void *set; void *obj; };
struct Pred { void *set; void *obj;
    Pred(void *s, void *o) : set(s), obj(o) {}
    Pred(const Pred &p) { *(Raw *)this = *(const Raw *)&p; }
};
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0052EFD0(void *, Pred);
static inline void remove_if(void *list, Pred pr) { func_0052EFD0(list, pr); }
extern "C" void func_001FEF08(char *self, void *obj) {
    void *lock = self + 0x11C;
    func_004A4D68(lock);
    Pred pr(self, obj);
    remove_if(self + 0x10, pr);
    func_004A4DD8(lock);
}
