/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
struct Chunk {
    int m0;
    unsigned cap;
    Chunk *next;
    unsigned used;
    char data[1];
} __attribute__((packed));
struct Stream { char pad[0x38]; int pending; };
extern "C" Chunk *func_004C2920(Stream *, unsigned, int);
extern "C" void func_004C2AD8(Stream *, Chunk *);
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" unsigned func_004C2D50(Stream *s, const char *src, unsigned len, int flags) {
    unsigned left = len;
    s->pending = s->pending + 1;
    Chunk *head = func_004C2920(s, len, flags);
    if (head != 0) {
        Chunk *c = head;
        do {
            unsigned n = c->cap;
            if (n >= left) n = (left < n) ? left : n;
            left -= n;
            func_004F64C4(c->data, src, n);
            c->used = n;
            c = c->next;
            src += n;
        } while (c != 0);
        func_004C2AD8(s, head);
        return len;
    }
    return (unsigned)head;
}
