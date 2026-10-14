/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
/* A derived-class constructor: the base constructor is out of line, then a const member is
   initialised (the store to a const field is what keeps the epilogue loads behind it). */
struct Base {
    s32 a;
    Base(s32 v) throw() __asm__("func_003BDB30");
};
struct Derived : Base {
    const s32 b;
    Derived(s32 v) __asm__("func_003BDB88");
};
Derived::Derived(s32 v) : Base(v), b(v) {
}
