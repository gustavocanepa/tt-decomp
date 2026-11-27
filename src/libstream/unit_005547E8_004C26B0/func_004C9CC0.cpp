/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct PacketHeader {
    u16 length;
    u16 type;
};

struct WordListBlock {
    u8 unknown00[2];
    u16 itemCount;
};

struct BitsetBlock {
    u8 unknown00[4];
    u8 bitCount;
};

struct SizedBlock {
    u16 length;
};

extern "C" void *func_004F64C4(void *, const void *, unsigned int);
extern "C" void *func_004F6678(void *, int, unsigned int);

extern "C" void func_004C9CC0(PacketHeader *destination, u32 type,
                               const WordListBlock *words,
                               const BitsetBlock *bits,
                               const SizedBlock *sized) {
    // These 16-bit lengths describe blocks; copy sizes and cursor movement
    // remain full width. The caller must provide a destination sized for them.
    u8 *cursor = (u8 *)destination + 4;

    if (words == 0) {
        *(u16 *)(cursor + 2) = 0;
        *(u16 *)cursor = 4;
        cursor += 4;
    } else {
        int length = 4 + 2 * words->itemCount;
        func_004F64C4(cursor, words, length);
        *(u16 *)cursor = (u16)length;
        cursor += length;
    }

    if (bits == 0) {
        *(u16 *)(cursor + 2) = 0;
        cursor[4] = 0;
        *(u16 *)cursor = 6;
        cursor += 6;
    } else {
        int bitCount = bits->bitCount;
        int byteCount = (bitCount + 7) >> 3;
        int copyLength = byteCount + 5;
        int paddedLength = (byteCount + 6) & 0x7E;
        func_004F6678(cursor, 0, paddedLength);
        func_004F64C4(cursor, bits, copyLength);
        *(u16 *)cursor = (u16)paddedLength;
        cursor += paddedLength;
    }

    if (sized == 0) {
        *(u16 *)cursor = 2;
        cursor += 2;
    } else {
        int paddedLength = (sized->length + 1) & -2;
        func_004F6678(cursor, 0, paddedLength);
        func_004F64C4(cursor, sized, sized->length);
        *(u16 *)cursor = (u16)paddedLength;
        cursor += paddedLength;
    }

    destination->length = (u16)(cursor - (u8 *)destination);
    destination->type = type;
}
