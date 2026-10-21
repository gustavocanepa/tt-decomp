/* compiler: ee-gcc2.9-991111 */
struct Packet { unsigned int size; void *dest; int cid; int opt; };
struct Dma { void *src; void *dest; int size; int attr; };
extern void *D_0078C260;
extern void func_004FDAF8(void *, int);
extern int func_004FABE0(void *, int);
extern int func_004FABF0(void *, int);
int func_004FD7F8(int cid, int mode, struct Packet *packet, int psize, void *src, void *dest, int dsize) {
    volatile struct Dma dma[2];
    int n;
    if ((unsigned int)(psize - 16) >= 97) return 0;
    n = 0;
    if (dsize > 0) {
        packet->size = *(unsigned char *)packet | (dsize << 8);
        ((struct Dma *)dma)[0].src = src;
        ((struct Dma *)dma)[0].dest = dest;
        ((struct Dma *)dma)[0].size = dsize;
        packet->dest = dest;
        ((struct Dma *)dma)[0].attr = 0;
        n = 1;
        if (mode & 4) func_004FDAF8(src, dsize);
    } else {
        packet->dest = 0;
        packet->size = *(unsigned char *)packet;
    }
    dma[n].src = packet;
    dma[n].dest = D_0078C260;
    dma[n].size = psize;
    packet->cid = cid;
    *(unsigned char *)packet = psize;
    dma[n].attr = 0x44;
    n++;
    func_004FDAF8(packet, psize);
    if (mode & 1) return func_004FABF0(dma, n);
    return func_004FABE0(dma, n);
}
