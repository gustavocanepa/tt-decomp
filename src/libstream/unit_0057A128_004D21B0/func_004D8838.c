/* compiler: ee-gcc2.9-991111 */
struct State { char pad[16]; int library; };
extern struct State D_00782940;
int func_004D8838(int choice) {
    if (choice < 3) {
        if (choice >= 0) {
            struct State *s = &D_00782940;
            int old = s->library;
            s->library = choice;
            return old;
        }
    }
    return 0x81050016;
}
