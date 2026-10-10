/* __is_pointer (gcc/cp/tinfo2.cc, old ABI): dynamic_cast<const __pointer_type_info *>(t) != 0,
   with the __dynamic_cast call (func_0050DB48) spelled out. */
struct VEntry { short delta; short index; void *pfn; };
struct Obj { int pad; struct VEntry *vptr; };

extern char func_00578000[];
extern char func_00577AB8[];
void *func_0050DB48(void *from, void *to, int require_public, void *address, void *sub, void *subptr);

int func_0050D9A8(struct Obj *t)
{
    void *pt = 0;
    if (t)
        pt = func_0050DB48(t->vptr[0].pfn, func_00578000, 0, (char *)t + t->vptr[0].delta, func_00577AB8, t);
    return pt != 0;
}
