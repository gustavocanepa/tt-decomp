/* compiler: ee-gcc2.9-991111 */
typedef struct { unsigned char a, b, c, hour; } Clock;
void func_004DAD48(Clock *);

void func_004DAEA8(Clock *c) {
    c->hour++;
    if (c->hour == 24) {
        c->hour = 0;
        func_004DAD48(c);
    }
}
