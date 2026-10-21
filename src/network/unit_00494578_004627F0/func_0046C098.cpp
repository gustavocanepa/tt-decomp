/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Append pending graphics state with a DMA header and VIF UNPACK command.
 * Two quadwords precede the payload emitted by the shared register writer. */
typedef unsigned int u32;
typedef unsigned long long u64;
struct Quad { u32 low, high; u64 registers; };
struct State { char unknown0[0x1F8]; Quad *cursor; };
extern "C" int func_00478FA8(State *, Quad *);
/* Keep the descriptor/control stores ordered when writing the DMA packet. */
#define WRITE_GIF_TAG(dst, value, registerValue) do { \
    Quad *q = (dst); u64 reg = (registerValue); u64 data = (value); \
    ((volatile u64 *)q)[1] = reg; *(volatile u64 *)q = data; \
} while (0)
extern "C" void func_0046C098(State *state, u32 destination) {
    Quad *packet = state->cursor;
    int count = func_00478FA8(state, packet + 2);
    packet->low = (count + 1) | 0x10000000;
    packet->high = 0;
    ((u32 *)packet)[2] = 0;
    ((u32 *)packet)[3] = ((count + 1) << 16) | 0x6C00C000 | destination;
    WRITE_GIF_TAG(packet + 1, (u64)(count | 0x8000) | 0x1000000000000000ULL, 0xE);
    state->cursor = (Quad *)((char *)packet + count * 16 + 0x20);
}
