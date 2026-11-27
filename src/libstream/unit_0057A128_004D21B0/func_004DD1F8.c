/* compiler: ee-gcc2.9-991111 */
/* Provisional per-channel response layout: copy a variable-length payload,
 * process its trailing metadata and return the length when status is nonzero. */
struct Descriptor { int present, width, byte_offset, bit_offset; };
struct Channel {
    int active, ready;
    char unknown8[12];
    struct Descriptor descriptors[40];
    char unknown294[0xA0];
};
struct Reply {
    unsigned char unknown0[2], length, unknown3;
    int status;
    char unknown8[20];
    unsigned char payload[1]; /* Variable-length tail in the RPC buffer. */
};
extern struct Channel D_007869D0[];
extern int func_004DD638(int);
extern struct Reply *func_004DD690(int);
extern void *func_004F64C4(void *, const void *, unsigned);
extern int func_004DD7C0(const unsigned char *, struct Descriptor *);
int func_004DD1F8(int channel, void *destination) {
    struct Reply *reply;
    int length;
    if(!D_007869D0[channel].active) return -1;
    if(!D_007869D0[channel].ready && func_004DD638(channel)<0) return -1;
    reply=func_004DD690(channel);
    length=reply->length;
    if(length && reply->payload) {
        func_004F64C4(destination,reply->payload,length);
        func_004DD7C0(reply->payload+reply->length,D_007869D0[channel].descriptors);
    }
    if(!reply->status) return -1;
    return reply->length;
}
