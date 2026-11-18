int func_003015D8(char *t) {
    char *q = t + 0x104;
    unsigned short a = *(unsigned short *)(q + 0x4D8);
    unsigned short b = *(unsigned short *)(q + 0x4DA);
    if ((a & 0x100) != 0 && (unsigned)(b - 0x5A) < 0x22C) return 1;
    return 0;
}
