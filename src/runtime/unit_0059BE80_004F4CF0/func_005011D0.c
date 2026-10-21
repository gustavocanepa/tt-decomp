/* compiler: ee-gcc2.9-991111 */
/* Allocate a file-descriptor table slot, func_005AE360 the backend handle, and publish
 * its index under the table semaphore. Field names are provisional. */
struct Entry { int handle, occupied, unknown8, unknownC; };
extern int D_005A315C, D_005A3168;
extern struct Entry D_0078F200[];
extern int func_004FF348(int);
extern void func_004FF470(void);
extern void func_004FF378(void);
extern struct Entry *func_004FED50(void);
extern int func_00500A58(const char *, int);
extern int func_004FA860(int);
extern int func_004FA840(int);
int func_005011D0(const char *name) {
    int result;
    struct Entry *entry;
    func_004FF348(9);
    if(!D_005A315C) func_004FF470();
    func_004FF378();
    entry=func_004FED50();
    if(!entry) return -19;
    result=func_00500A58(name,9);
    if(result<0) {
        func_004FA860(D_005A3168);
        entry->occupied=0;
        func_004FA840(D_005A3168);
        return result;
    } else {
        func_004FA860(D_005A3168);
        entry->handle=result;
        result=entry-D_0078F200;
        func_004FA840(D_005A3168);
        return result;
    }
}
