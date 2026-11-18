/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x005762d8.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct S { void *buffer; char pad[0x16]; unsigned char state; };
extern "C" void func_005762D8(S *s, int f) {
    s->state = s->buffer ? f : f | 4;
}
