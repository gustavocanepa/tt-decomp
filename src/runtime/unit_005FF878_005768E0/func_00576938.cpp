struct Buf { int flags; char *read_ptr; char *read_end; };
extern "C" int func_004E5B68(Buf *b); /* underflow */
/* streambuf::snextc: consume one character, then peek the following one (EOF = -1). */
extern "C" int func_00576938(Buf *b)
{
    if (b->read_ptr >= b->read_end && func_004E5B68(b) == -1) return -1;
    b->read_ptr++;
    return b->read_ptr >= b->read_end && func_004E5B68(b) == -1
        ? -1 : *(unsigned char *)b->read_ptr;
}
