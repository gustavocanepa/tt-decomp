/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Row { u8 pad[0x10]; u8 type; u8 pad2[0xF]; };
struct Spec { char pad[0xA8]; unsigned key; };
extern "C" int func_0040B940(void *, int, int, Row *);
extern char D_00585A30[];

static inline bool getRow(unsigned long k, Row *r) {
    return func_0040B940(D_00585A30, (int)k, 0x22, r) != 0;
}

extern "C" int func_0040F0F8(Spec *self) {
    Row r;
    unsigned long k = self->key;
    if (getRow(k, &r)) return r.type;
    return -1;
}
