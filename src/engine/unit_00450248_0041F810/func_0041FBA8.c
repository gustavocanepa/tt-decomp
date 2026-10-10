struct E { int a; int b; };
int func_0041FBA8(struct E *p) {
    struct E *q = p;
    while (q->a != 0) q++;
    return q - p;
}
