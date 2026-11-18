struct S { char pad[0x85C]; int idx; };
int func_004862D0(struct S *s) {
    char *e = (char *)s + s->idx * 0x41C;
    return *(int *)(e + 0x234);
}
