/* compiler: ee-gcc2.96-nsa-as2004 */
struct Block {
    char pad0[0xC];
    unsigned int size;
    char payload[1];
} __attribute__((packed));

struct Ring {
    char pad0[0x3C];
    int generation;
};

extern "C" {
Block *func_004C2B68(Ring *);
void func_004C2C28(Ring *, Block *);
void *func_004F64C4(void *, const void *, unsigned int);

int func_004C2CA0(Ring *ring, char *buffer, int capacity)
{
    char *end = buffer + capacity;
    char *cursor = buffer;
    ring->generation++;
    Block *block;
    char *next;
    while ((block = func_004C2B68(ring)) != 0) {
        unsigned int size = block->size;
        next = cursor + size;
        if (next > end)
            break;
        func_004F64C4(cursor, block->payload, size);
        func_004C2C28(ring, block);
        cursor = next;
    }
    return cursor - buffer;
}
}
