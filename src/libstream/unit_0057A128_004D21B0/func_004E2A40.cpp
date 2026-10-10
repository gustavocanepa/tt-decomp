/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): istream::seekg.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef unsigned char u8;

struct Buf;

struct State {
    Buf *buf;
    char pad[0x16];
    u8 flags;
};

struct Stream {
    State *state;
};

extern "C" int func_004E7A80(Buf *, int, int, int);

extern "C" Stream *func_004E2A40(Stream *s, int a, int b) {
    if (func_004E7A80(s->state->buf, a, b, 1) == -1)
        s->state->flags |= 4;
    return s;
}
