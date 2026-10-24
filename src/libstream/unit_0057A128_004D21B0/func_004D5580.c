/* compiler: ee-gcc2.9-991111 */
struct Library {
    char pad[0x10];
    const char *name;
    unsigned short version;
};
extern int func_004A8268(const char *, const char *);

/* The repeated s0 attribute works around the compiler overwriting the first
   register_precision entry when processing the next one. Preserve both full
   128-bit callee-saved registers. */
int func_004D5580(struct Library *a, struct Library *b)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));

int func_004D5580(struct Library *a, struct Library *b) {
    if (func_004A8268(a->name, b->name))
        return 0;
    if ((a->version >> 8) != (b->version >> 8))
        return 0;
    return a->version >= b->version;
}
