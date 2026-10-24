/* compiler: ee-gcc2.96-nogcse */
struct StreamHeader {
    int tag;
    unsigned int resolution;
};

struct Voice {
    char pad[0x1C];
};

struct Player {
    char pad0[0x60];
    int state;
    char pad1[4];
    Voice voices[16];
    char pad2[0x228 - 0x68 - 16 * 0x1C];
    int cursorA;
    int cursorB;
    int cursorC;
};

extern "C" {
void func_004C5D50(void *);
void func_004C5798(Player *, void *stream, void *context, float resolution);
void func_004C6828(void *);
void func_004C6A60(void *);

void func_004C6480(Player *p, void *context, char *stream)
{
    StreamHeader *header = (StreamHeader *)stream;
    p->cursorA = 0;
    p->cursorB = 0;
    p->cursorC = 0;
    for (int i = 15; i >= 0; i--)
        func_004C5D50(&p->voices[15 - i]);
    stream += 8;
    float resolution = (float)header->resolution;
    func_004C5798(p, stream, context, resolution);
    func_004C6828((char *)p + 0x234);
    func_004C6A60((char *)p + 0x24C);
    p->state = 2;
}
}
