/* compiler: ee-gcc2.9-991111 */
/* Reads a 14-byte version string from a file once and caches it. */
extern char D_005A0BD0[];
extern const char D_00614708[];

int func_004FF970(const char *path, int mode);
int func_004FFFB8(int fd, void *buf, int size);
int func_004FFC00(int fd);

char *func_004DA8F0(void)
{
    int fd;

    if (D_005A0BD0[0] == 0) {
        fd = func_004FF970(D_00614708, 1);
        if (fd >= 0) {
            func_004FFFB8(fd, D_005A0BD0, 14);
            func_004FFC00(fd);
        }
    }
    return D_005A0BD0;
}
