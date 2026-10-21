/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;

// ABI evidence establishes a 0xAE-byte record with two-byte alignment.
// The builder initializes the prefix described by length; the rest is unspecified.
struct PacketSnapshot {
    u16 length;
    u16 type;
    u8 unknown04[0xAA];
};

extern "C" void func_004C9CC0(PacketSnapshot *, unsigned int,
    const void *, const void *, const void *);

extern "C" PacketSnapshot func_004C9F68() {
    PacketSnapshot packet;
    func_004C9CC0(&packet, 0, 0, 0, 0);
    return packet;
}
