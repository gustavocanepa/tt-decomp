/* compiler: ee-gcc2.9-991111 */
struct N { char p[8]; struct N *next; struct N *links; char q[6]; unsigned short flags; };
extern struct N *D_0077A028;
int func_004D5580(struct N *, struct N *);
int func_004D5840(struct N *, struct N *);
/* Preserve the full SDK callee-saved registers. Repeating the first
   attribute is required by this compiler's attribute processing. */
int func_004D57B8(struct N *)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));
int func_004D57B8(struct N *arg) {
    struct N *p = D_0077A028;
    while (p) {
        if (!(p->flags & 1) && func_004D5580(p, arg)) {
            func_004D5840(arg, p);
            arg->links = p->links;
            p->links = arg;
            return 1;
        }
        p = p->next;
    }
    return 0;
}
