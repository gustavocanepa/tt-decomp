/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" void func_00454188(u128 *, const u128 *, const u128 *);
extern "C" void func_00454160(u128 *a, const u128 *b) {
    u128 t = *a;
    func_00454188(a, &t, b);
}
