struct VE2 { short delta; short index; int (*fn)(void *, void *); };
struct VE1 { short delta; short index; int (*fn)(void *); };
struct A { char p[0x4C]; char *tbl; };
struct B { char *tbl; };
extern "C" int func_0019B850(A *a, B *b) {
    char buf[0x50];
    int bad = 0;
    VE2 *e = (VE2 *)(a->tbl + 0x78);
    e->fn((char *)a + e->delta, buf);
    VE2 *e2 = (VE2 *)(b->tbl + 0x98);
    int r = e2->fn((char *)b + e2->delta, buf);
    VE1 *e3 = (VE1 *)(b->tbl + 0x28);
    if (e3->fn((char *)b + e3->delta) != 0 || r < 0) bad = 1;
    return bad == 0 ? r : -1;
}
