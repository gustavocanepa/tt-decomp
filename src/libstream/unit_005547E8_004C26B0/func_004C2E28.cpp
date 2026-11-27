/* compiler: ee-gcc2.96-nogcse-as2004 */
/* Writes size bytes into a stream as a chain of chunks: allocates the chain (flushing chunks
   until one is free), fills each chunk up to its capacity, then queues the chain. The copied
   length goes through size before advancing src, which keeps retail's register roles. */
typedef unsigned int u32;
struct Chunk { int x0; u32 len; Chunk *next; u32 used; char data[1]; } __attribute__((packed));
extern "C" Chunk *func_004C2920(void *, u32, int);
extern "C" Chunk *func_004C2B68(void *);
extern "C" void func_004C2C28(void *, Chunk *);
extern "C" void func_004C2AD8(void *, Chunk *);
extern "C" void *func_004F64C4(void *, const void *, u32);
extern "C" void func_004C2E28(void *s, const char *src, u32 size) {
    u32 rem = size;
    Chunk *head, *c;
    while ((head = func_004C2920(s, size, 1)) == 0) {
        c = func_004C2B68(s);
        if (c) func_004C2C28(s, c);
    }
    c = head;
    do {
        u32 len = c->len;
        if (len >= rem) len = rem < len ? rem : len;
        rem -= len;
        func_004F64C4(c->data, src, len);
        c->used = len;
        c = c->next;
        size = len;
        src += size;
    } while (c);
    func_004C2AD8(s, head);
}
