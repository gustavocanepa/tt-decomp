struct Buf {
    int fd;
    char pad4[0x1A - 4];
    unsigned char state;
};

struct Stream {
    struct Buf *buf;
};

extern int func_004E7B20(int fd, int off, int whence);

struct Stream *func_004E41B8(struct Stream *s, int off) {
    if (func_004E7B20(s->buf->fd, off, 2) == -1) {
        s->buf->state |= 4;
    }
    return s;
}
