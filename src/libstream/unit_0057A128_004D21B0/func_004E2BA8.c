/* libio (GNU iostream library, gcc 2000-10-03 snapshot): operator>>(istream&, char*).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Buf {
    int fd;
    int tie;
    int width;
    char pad0C[4];
    long long flags;
    char pad18[2];
    unsigned char state;
};
struct Stream { struct Buf *buf; };

#define CTYPE_TABLE ((unsigned char *)0x616779)
extern void func_004E42B0(int tie);
extern int func_004E43E0(struct Stream *);
extern int func_004E5458(int, char);
extern int func_004E8180(int);

static inline int set_width(struct Buf *b, int nw) {
    int old = b->width;
    b->width = nw;
    return old;
}

struct Stream *func_004E2BA8(struct Stream *is, char *ptr) {
    char *p = ptr;
    int w = set_width(is->buf, 0);
    int ok;
    if (is->buf->state) {
        is->buf->state |= 2;
        ok = 0;
    } else {
        if (is->buf->tie) func_004E42B0(is->buf->tie);
        ok = ((int)(is->buf->flags & 1) == 0) ? 1 : func_004E43E0(is);
    }
    if (ok) {
        int fd = is->buf->fd;
        int ch;
        while ((ch = func_004E8180(fd)) != -1) {
            if ((CTYPE_TABLE[ch] & 8) || w == 1) {
                func_004E5458(fd, ch);
                goto done;
            }
            *p++ = ch;
            w--;
        }
        is->buf->state |= 1;
done:
        if (p == ptr) is->buf->state |= 2;
    }
    *p = 0;
    return is;
}
