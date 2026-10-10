/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::sgetc() out of line, the code of _IO_peekc_unlocked (byte-identical to peekc.c's func_005768E0).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Buf { int flags; char *read_ptr; char *read_end; };
extern "C" int func_004E5B68(Buf *b); /* underflow */

/* streambuf::sgetc: the next character without consuming it, or EOF. */
extern "C" int func_005768E0(Buf *b)
{
    return b->read_ptr >= b->read_end && func_004E5B68(b) == -1
        ? -1 : *(unsigned char *)b->read_ptr;
}
