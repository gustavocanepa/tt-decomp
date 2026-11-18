/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" int func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0042C640();
extern "C" void func_0042C7E8(const char *);
extern char D_00600AA0[], D_00600AA8[], D_00769FC8[];
struct Shared { int a,refs; };
extern Shared D_00769FF8;
static inline int acquire(const char *arg0, int first) {
    void *mutex = D_00769FC8;
    func_004A4D68(mutex);
    if (++D_00769FF8.refs==first) {
        func_0042C640();
        func_0042C7E8(arg0);
    }
    func_004A4DD8(mutex);
    return -1;
}
extern "C" int func_0042BA40(const char *arg0) {
    if (func_004A8268(arg0,D_00600AA0)==0) return -2;
    if (func_004A8268(arg0,D_00600AA8)==0) return -3;
    return acquire(arg0,1);
}
