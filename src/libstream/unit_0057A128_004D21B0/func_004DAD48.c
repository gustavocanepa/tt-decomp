/* compiler: ee-gcc2.9-991111 */
struct Date { unsigned char pad[5], day, month, year; };
void func_004DAD48(struct Date *d) {
    char days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    d->day++;
    if (!(((volatile struct Date *)d)->year & 3)) days[1] = 29;
    if (days[d->month - 1] < d->day) {
        d->day = 1;
        if (++d->month == 13) {
            if (d->year == 99) d->year = 0;
            else d->year++;
            d->month = 1;
        }
    }
}
