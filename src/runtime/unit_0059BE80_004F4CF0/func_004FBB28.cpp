/* compiler: ee-gcc2.9-991111 */
/* Byte ring buffer header (data follows at +0x10): advance the func_005AE268 cursor, wrapping at the end. */
struct RingBuffer {
	int capacity;
	int count;
	char *readPos;
	char *writePos;
	char data[1];
};

extern "C" void func_004FBB28(RingBuffer *rb)
{
	rb->count++;
	rb->writePos++;
	if (rb->writePos == (char *)rb + (rb->capacity + 0x10))
		rb->writePos = rb->data;
}
