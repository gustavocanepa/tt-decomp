/* compiler: ee-gcc2.9-991111 */
/* Unlink a registered group while interrupts are excluded. Returns the old
 * head when removing it, otherwise its predecessor, or null when absent.
 * The caller supplies a valid group; the original always reenables IRQs. */
struct Group { char unknown0[0x14]; struct Group *next; };
struct Pool { char unknown0[0x28]; struct Group *groups; };
extern struct Pool D_0078DC80;
extern int func_005038D8(void);
extern int func_00503928(void);
struct Group *func_004FE970(struct Group *target) {
    struct Group *group;
    func_005038D8();
    group = D_0078DC80.groups;
    if (group == target) {
        D_0078DC80.groups = group->next;
    } else {
        for (; group; group = group->next) {
            if (group->next == target) {
                group->next = target->next;
                break;
            }
        }
    }
    func_00503928();
    return group;
}
