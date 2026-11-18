/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x005949A8.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct File;
struct VTable { char pad[0x24]; int (*uflow)(File *); };
struct File {
    int flags;
    char *read_ptr, *read_end, *read_base;
    char pad10[0x14];
    char *save_base;
    char pad28[8];
    void *markers;
    char pad34[0x1C];
    VTable *vtable;
};
extern "C" int func_004E5898(File *) throw();
extern "C" void func_004E5828(File *) throw();
extern "C" int func_004E59B8(File *) throw();
extern "C" void func_004E5940(File *) throw();
extern "C" int func_004E5C38(File *fp) {
    if (fp->flags & 0x800)
        if (func_004E5898(fp) == -1) return -1;
    if (fp->read_ptr < fp->read_end)
        return *(unsigned char *)fp->read_ptr++;
    if (fp->flags & 0x100) {
        func_004E5828(fp);
        if (fp->read_ptr < fp->read_end)
            return *(unsigned char *)fp->read_ptr++;
    }
    if (fp->markers) {
        if (func_004E59B8(fp)) return -1;
    } else if (fp->save_base)
        func_004E5940(fp);
    return fp->vtable->uflow(fp);
}
