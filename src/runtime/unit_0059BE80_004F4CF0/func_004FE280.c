/* compiler: ee-gcc2.9-991111 */
/* Reply to a bind request with the matching registered server. Failed sends
 * schedule an alarm retry using the same reply packet. Header references
 * remain opaque 32-bit wire values; layouts and callback types provisional. */
struct Owner { char unknown0[0x28]; void *groups; };
struct Server { unsigned id; char unknown4[4]; void *buffer; };
struct Reply {
    char unknown0[0x14];
    unsigned request_id;
    char unknown18[4];
    unsigned client_address;
    unsigned command;
    void *server;
    void *buffer;
    char unknown2C[20];
};
typedef unsigned long long (*TimerCallback)(int, unsigned long long,
    unsigned long long, void *);
extern struct Reply *func_004FDE38(struct Owner *);
extern struct Server *func_004FE1F0(unsigned, struct Owner *);
extern int func_004FD970(unsigned, void *, int, void *, void *, int);
extern unsigned long long func_004FE240(int, unsigned long long,
    unsigned long long, void *);
extern int func_00505698(unsigned long long, TimerCallback, void *);
void func_004FE280(struct Reply *request, struct Owner *owner) {
    struct Reply *reply = func_004FDE38(owner);
    struct Server *server;
    unsigned original = request->request_id;
    unsigned client = request->client_address;
    reply->request_id = original;
    reply->client_address = client;
    reply->command = 0x80000009;
    server = func_004FE1F0(request->command, owner);
    if (!server) {
        reply->server = 0;
        reply->buffer = 0;
    } else {
        reply->server = server;
        reply->buffer = server->buffer;
    }
    if (!func_004FD970(0x80000008, reply, 64, 0, 0, 0))
        func_00505698(0x800, func_004FE240, reply);
}
