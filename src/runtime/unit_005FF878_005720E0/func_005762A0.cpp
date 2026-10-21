/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x005762a0.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct S { char pad[0x10]; long long fl; };
extern "C" long long func_005762A0(S *s, long long f) {
    long long old = s->fl;
    s->fl = old & ~f;
    return old;
}
