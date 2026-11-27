/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x006151F8.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
/* libio ios::setf(fmtflags): returns the previous flags (that is why the load sits in $v0) */
struct S { char pad[0x10]; long long fl; };
extern "C" long long func_00576270(S *s, long long f) {
    long long old = s->fl;
    s->fl |= f;
    return old;
}
