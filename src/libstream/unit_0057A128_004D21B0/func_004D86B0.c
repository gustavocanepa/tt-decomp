/* compiler: ee-gcc2.9-991111 */
struct S { char pad[0x24]; int f24; };
void func_004D9D80(int);
void func_004D9E00(struct S *);
void func_004D86B0(struct S *, int) __attribute__((register_precision(s0, 128)));
void func_004D86B0(struct S *p, int flags) {
    if (!(flags & 0x20)) func_004D9D80(p->f24);
    func_004D9E00(p);
}
