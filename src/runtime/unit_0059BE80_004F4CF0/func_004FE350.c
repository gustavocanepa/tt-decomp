/* compiler: ee-gcc2.9-991111 */
/* Bind an RPC client using a pooled 64-byte command packet. Blocking mode
 * owns a temporary semaphore until completion; asynchronous mode returns
 * after submission. Packet fields and names are provisional. */
struct Client;
struct Packet {
    char unknown0[16];
    unsigned flags;
    struct Packet *self;
    int generation;
    struct Client *client;
    unsigned server_id;
    char unknown24[28];
};
struct Client {
    struct Packet *packet;
    int generation;
    int semaphore;
    char unknownC[4];
    int command;
    char unknown14[16];
    void *server;
};
struct Pool;
struct Semaphore { int current, maximum, initial, waiters; unsigned attributes; const char *tag; };
extern struct Pool D_0078DC80;
extern char D_00617918[];
extern struct Packet *func_004FDD70(struct Pool *);
extern void func_004FDE18(struct Packet *);
extern int func_004FA820(struct Semaphore *);
extern int func_004FA830(int);
extern int func_004FA860(int);
extern int func_004FD930(unsigned, void *, int, void *, void *, int);
int func_004FE350(struct Client *client, unsigned server_id, int mode) {
    struct Packet *packet;
    struct Semaphore semaphore;
    client->command = 0;
    client->server = 0;
    packet = func_004FDD70(&D_0078DC80);
    if (!packet) return -1;
    client->packet = packet;
    client->generation = packet->generation;
    packet->server_id = server_id;
    packet->self = packet;
    packet->client = client;
    if (!(mode & 1)) {
        semaphore.maximum = 1;
        semaphore.tag = D_00617918;
        semaphore.initial = 0;
        client->semaphore = func_004FA820(&semaphore);
        if (client->semaphore < 0) {
            func_004FDE18(packet);
            return -3;
        }
        if (!func_004FD930(0x80000009, packet, 64, 0, 0, 0)) {
            func_004FDE18(packet);
            func_004FA830(client->semaphore);
            return -2;
        }
        func_004FA860(client->semaphore);
        func_004FA830(client->semaphore);
        return 0;
    }
    client->semaphore = -1;
    if (!func_004FD930(0x80000009, packet, 64, 0, 0, 0)) {
        func_004FDE18(packet);
        return -2;
    }
    return 0;
}
