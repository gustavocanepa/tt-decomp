/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x004e4328.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef struct Buf Buf;
typedef struct Stream Stream;
struct Buf { int flags; char *read_ptr; char *read_end; };
struct Stream { Buf *buf; Stream *tie; char pad[0x12]; unsigned char state; };
extern "C" int func_004E25C0(void *) throw();
extern "C" void *func_004E42B0(void *);
extern "C" int func_004E5458(void *, int);
extern "C" Stream **func_004E4328(Stream **self) {
    Stream *s = *self;
    int ok;
    if (__builtin_expect(s->state, 0)) {
        s->state = s->state | 2;
        ok = 0;
    } else {
        Stream *tie = s->tie;
        if (tie != 0) {
            Buf *buf = s->buf;
            if (buf->read_end == buf->read_ptr) func_004E42B0(tie);
        }
        ok = 1;
    }
    if (ok != 0) {
        int c = func_004E25C0((*self)->buf);
        if (c == -1) {
            Stream *s = *self;
            s->state = s->state | 1;
        } else {
            func_004E5458((*self)->buf, (signed char)c);
        }
    }
    return self;
}
