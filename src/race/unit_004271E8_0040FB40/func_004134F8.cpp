typedef struct { char b[16]; } Block16;

void *func_004134F8(void *arg0, void *arg1) {
    char *d = (char *)arg0;

    *(Block16 *)d = *(Block16 *)arg1;
    return d;
}
