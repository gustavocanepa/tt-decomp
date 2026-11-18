/* compiler: ee-gcc2.9-991111 */
/* Provisional resource-list views, shared with the validator at 00585F20.
 * A resource can be removed only when all its children are flagged ready. */
struct Resource {
    unsigned magic0, magic1;
    struct Resource *next, *child;
    char unknown10[6];
    unsigned short flags;
    char unknown18[8];
    void (*notify)(int, struct Resource *);
};
struct ResourceLists {
    struct Resource *active;
    char unknown4[0x10];
    struct Resource *free_children;
};
extern struct ResourceLists D_0077A028;
extern int func_004D4B58(struct Resource *, int *);
extern int func_005038D8(void);
extern int func_00503928(void);
extern int func_004D57B8(struct Resource *);
extern void func_004D55E0(struct Resource *);
extern void func_004FAAA0(int);
int func_004D4A18(struct Resource *resource) {
    int flagged;
    int total=func_004D4B58(resource,&flagged);
    int interrupts;
    struct Resource *child, *next;
    struct Resource **link;
    if(total<0) return total;
    if(total!=flagged) return 0x81059038;
    interrupts=func_005038D8();
    child=resource->child;
    for(link=&D_0077A028.active; *link && *link!=resource; link=&(*link)->next) {}
    *link=resource->next;
    resource->next=0;
    resource->child=0;
    while(child) {
        next=child->child;
        if(!func_004D57B8(child)) {
            func_004D55E0(child);
            child->flags |= 4;
            child->child=D_0077A028.free_children;
            D_0077A028.free_children=child;
        }
        child=next;
    }
    func_004FAAA0(2);
    if(interrupts) func_00503928();
    resource->notify(1,resource);
    return 0;
}
