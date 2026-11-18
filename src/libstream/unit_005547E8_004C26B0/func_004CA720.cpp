/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

struct PacketHeader {
    u16 length;
    u16 type;
};

/* A list of 16-bit values; a packet's first block. */
struct WordListBlock {
    u16 length;
    u16 itemCount;
    s16 items[31];
};

/* A bit set; a packet's second block. */
struct BitsetBlock {
    u16 length;
    u16 flags;
    u8 bitCount;
    u8 bits[31];
};

struct SizedBlock {
    u16 length;
};

/* A packet as stored: header, then the word list, the bit set and a sized block. */
struct Packet {
    PacketHeader header;
    WordListBlock words;
};

/* The packet built by func_004C9CC0, returned by value. */
struct PacketBuffer {
    PacketHeader header;
    u16 data[0x55];
};

/* How a word operation reads its operand: the operand is a signed field of
   signBit + 1 bits when signBit < 16, and is then mapped through the segment
   list starting at curve. */
struct OperandFormat {
    s16 signBit;
    s16 curve;
};

/* One piece of a piecewise-linear map from [x0, x1] onto [y0, y1]; a piece of
   four zeros ends a list. */
struct Segment {
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
};

/* Edits to apply to a packet. Each operation word holds the kind in bits 0-3
   and its operands in the bytes above; a zero kind ends a list. */
struct PacketEdits {
    const u32 *wordOps;
    const u32 *bitOps;
    const OperandFormat *formats;
    const Segment *segments;
};

extern "C" void *func_004C9C60(const Packet *packet);
extern "C" void *func_004C9C98(const Packet *packet);
extern "C" void func_004C9CC0(PacketBuffer *destination, u32 type,
                              const WordListBlock *words,
                              const BitsetBlock *bits,
                              const SizedBlock *sized);
extern "C" void *func_004F6678(void *, int, unsigned int);

/* Returns a copy of packet with edits applied to its word list and bit set. */
extern "C" PacketBuffer func_004CA720(const Packet *packet, const PacketEdits *edits)
{
    PacketBuffer result;
    WordListBlock words;
    BitsetBlock bits;
    const WordListBlock *input = &packet->words;
    const WordListBlock *wordSource = input;
    const BitsetBlock *bitSource;

    const u32 *wordOps = edits->wordOps;
    if (wordOps != 0) {
        const OperandFormat *formats = edits->formats;
        const Segment *segments = edits->segments;
        int i;
        int kind;
        int from;
        int to;
        int format;

        wordSource = &words;
        func_004F6678(&words, 0, sizeof(words));
        for (i = 0;; i++) {
            u32 w = wordOps[i];
            kind = w & 0xF;
            from = (w >> 4) & 0xFF;
            to = (w >> 12) & 0xFF;
            format = (w >> 20) & 0xFF;
            if (kind == 0)
                break;
            const OperandFormat *f = &formats[format];
            int value = 0;
            if (kind == 4)
                value = words.items[to];
            else if (from < input->itemCount)
                value = input->items[from];
            int signBit = f->signBit;
            if ((u32)signBit < 16)
                value = (value << (31 - signBit)) >> (31 - signBit);

            int mapped = 0;
            const Segment *s;
            for (s = &segments[f->curve];; s++) {
                int x0 = s->x0;
                int x1 = s->x1;
                int y0 = s->y0;
                int y1 = s->y1;
                if ((x0 | x1 | y0 | y1) == 0)
                    break;
                if (value < x0)
                    continue;
                if (x1 < value)
                    continue;
                mapped = value;
                if (x0 != y0 || x1 != y1) {
                    mapped = y0;
                    if (y0 != y1)
                        mapped = ((value - x0) * (y1 - y0) + ((x1 - x0) >> 1)) / (x1 - x0) + y0;                }            }

            switch (kind) {
            case 1:
            case 4:
                words.items[to] = mapped;
                break;
            case 2:
                words.items[to] += mapped;
                break;
            case 3:
                words.items[to] -= mapped;
                break;
            }
            if (to >= words.itemCount)
                words.itemCount = to + 1;
        }
    }

    const u32 *bitOps = edits->bitOps;
    bitSource = (const BitsetBlock *)func_004C9C60(packet);
    const BitsetBlock *original = bitSource;
    if (bitOps != 0) {
        int i;
        int kind;
        int from;
        int to;

        bitSource = &bits;
        func_004F6678(&bits, 0, sizeof(bits));
        bits.flags = original->flags;
        for (i = 0;; i++) {
            const u32 *o = bitOps + i;
            u32 w = *o;
            kind = w & 0xF;
            from = (w >> 8) & 0xFF;
            to = (w >> 16) & 0xFF;
            if (kind == 0)
                break;
            const u8 *operandBits = original->bits;
            if (kind >= 7) {
                operandBits = bits.bits;
                kind -= 6;
            }
            int operand = operandBits[from >> 3] >> (from & 7);
            int byte = bits.bits[to >> 3];
            int bit = byte >> (to & 7);
            int mask = 1 << (to & 7);            switch (kind) {
            case 1: bit &= operand; break;
            case 2: bit |= operand; break;
            case 3: bit ^= operand; break;
            case 4: bit &= ~operand; break;
            case 5: bit |= ~operand; break;
            case 6: bit ^= ~operand; break;
            }
            /* store the low bit of the result into the destination bit */
            byte |= mask;
            bit &= 1;
            if (bit == 0)
                byte -= mask;
            bits.bits[to >> 3] = byte;            if (to >= bits.bitCount)
                bits.bitCount = to + 1;
        }
    }

    u32 type = packet->header.type;
    func_004C9CC0(&result, type, wordSource, bitSource,
                  (const SizedBlock *)func_004C9C98(packet));
    return result;
}
