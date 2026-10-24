/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Parser { char pad0[0xC]; const signed char *cursor; char pad10[0x20]; u32 handler; };
int func_004D8868(struct Parser *, u32, u32, const signed char *);

extern char D_00613B80[];

/* The tag words are compared after XOR with this key, so the keyword strings do not appear in
   the binary. */
#define KEY 0x72E7C42FU

/* Parses a keyword at the parser's cursor: skips blanks, packs the next four characters into a
   word (big-endian), and dispatches on the obfuscated value. Returns 0 or 1 for an accepted
   keyword followed by a digit (installing the handler D_00613B80), 2 or the callee's error for a
   two-digit form handled by func_004D8868, and 0x81050006 / 0x81050013 for malformed input. */
int func_004D75A0(struct Parser *ps) {
    const signed char *p;
    int result;
    u32 word;
    u32 hi;
    p = ps->cursor;
    do {
        word = *p++;
    } while (word == ' ');
    result = 0;
    word = (word << 8) | *p++;
    word = (word << 8) | *p++;
    word = (word << 8) | *p;
    word ^= KEY;
    hi = word >> 8;
    if (hi != 0x88A9) {
        if (hi + 0xFFE07B0C < 2) {
            u32 tag = word ^ KEY;
            u32 b = (tag & 0xFF) - '0';
            u32 a = ((tag >> 8) & 0xFF) - '0';
            if (a < 3 && b < 11) {
                if (b == 10) {
                    b = 0;
                    p++;
                } else {
                    p += 2;
                }
                result = func_004D8868(ps, a, b, p);
                return result < 0 ? result : 2;
            }
            return 0x81050006;
        }
        if (hi == 0x281B7) {
            result = 1;
        } else {
            p++;
            if (!(word == 0x1A88B75B
                || (word == 0x1183B640 && *p++ == 'm')
                || (word == 0x1393A246 && *p++ == 'l' && *p++ == 'e')))
                return 0x81050013;
        }
    }
    if ((u32)(*p - '0') < 11) {
        ps->handler = (u32)D_00613B80;
        return result;
    }
    return 0x81050006;
}
