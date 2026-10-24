/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char p[0x694]; volatile int a, b; };
extern "C" void func_00198FD0(S *);
extern "C" void func_004A4D68(S *);
extern "C" void func_004A4DD8(S *);
extern "C" void func_004A58A0(int);
extern "C" void func_00198F38(S *s) {
    for (;; func_004A58A0(0x3E80)) {
    func_004A4D68(s);
    if (s->b != 5) {
        s->a = s->b;
        s->b = 5;
    }
    func_004A4DD8(s);
    if (s->a == 0) {
        func_00198FD0(s);
        continue;
    }
    if (s->a == 4) break;
    }
}
