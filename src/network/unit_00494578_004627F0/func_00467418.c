/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

/* Loaded animation data: every pointer is stored as an offset from the start of the file and is
   relocated by the load address once the file is in memory. */
struct Key { int time; u32 ptr; };
struct Track { char pad0[6]; u16 count; u32 p8; u32 keys; char pad10[0xF]; u8 f1F; };
struct Anim { u16 count; short pad; u32 tracks; };

void func_00466DF8(struct Track *t);

#define RELOC(x, base) do { (x) += (base); } while (0)
#define RELOC_NZ(x, base) do { if (x) (x) += (base); } while (0)
#define TRACK(a, i) ((struct Track *)((i) * sizeof(struct Track) + (a)->tracks))
#define KEY(t, j) ((struct Key *)((j) * sizeof(struct Key) + (t)->keys))

void func_00467418(struct Anim *a, int base) {
    int i, j;
    if (a->tracks) {
        RELOC(a->tracks, base);
        for (i = 0; i < a->count; i++) {
            struct Track *t = TRACK(a, i);
            RELOC_NZ(t->p8, base);
            if (t->keys) {
                RELOC(t->keys, base);
                for (j = 0; j < t->count; j++) {
                    struct Key *k = KEY(t, j);
                    RELOC_NZ(k->ptr, base);
                }
            }
            func_00466DF8((struct Track *)a->tracks + i);
            TRACK(a, i)->f1F = 0;
        }
    }
}
