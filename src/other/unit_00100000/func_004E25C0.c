/* libio (GNU iostream library, gcc 2000-10-03 snapshot): skip_ws.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
/* newlib-style isspace(): (D_00616778 + 1)[c] & _S with D_00616778 a const char array (D_00616778) */
extern const char D_00616778[];
extern int func_004E8180(void *fp);

int func_004E25C0(void *fp) {
    int c;
    while ((c = func_004E8180(fp)) != -1 && ((D_00616778 + 1)[c] & 8))
        ;
    return c;
}
