/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned int u32;

struct PacketHeader {
    u16 length;
    u16 type;
};
struct PacketBuffer {
    PacketHeader header;
    u16 data[0x55];
};
struct Packet;
struct PacketEdits;
struct WordListBlock;
struct BitsetBlock;
struct SizedBlock;

extern "C" void *func_004C9C50(PacketBuffer *);
extern "C" void func_0055F250(PacketBuffer *destination, u32 type, const WordListBlock *words,
                               const BitsetBlock *bits, const SizedBlock *sized);

struct PacketSource {
    virtual ~PacketSource();
    virtual PacketBuffer packet();
};


struct PacketCache {
    PacketSource *source;
    char pad4[0x10];
    PacketBuffer packet;
    void *body;
    void *end;
};

extern "C" void MenuControl__virtual_01(PacketCache *self) {
    if (self->source != 0) {
        self->packet = self->source->packet();
        self->body = (char *)&self->packet + 4;
        self->end = func_004C9C50(&self->packet);
    }
}
