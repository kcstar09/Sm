#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BUCKET_SIZE 10
#define OUTPUT_RATE 1
struct LeakyBucket {
int bucket_level;
time_t last_packet_time;
};
void send_packet(struct LeakyBucket *bucket, int packet_size) {
time_t current_time = time(NULL);
double elapsed_time = difftime(current_time, bucket->last_packet_time);
bucket->last_packet_time = current_time;
bucket->bucket_level -= elapsed_time * OUTPUT_RATE;
if (bucket->bucket_level < 0) {
bucket->bucket_level = 0;
}
if (packet_size <= BUCKET_SIZE - bucket->bucket_level) {
bucket->bucket_level += packet_size;
printf("Packet sent. Bucket level: %d\n", bucket->bucket_level);
} else {
printf("Packet dropped. Bucket level: %d\n", bucket->bucket_level);
}
}
int main() {
struct LeakyBucket bucket;
bucket.bucket_level = 0;
bucket.last_packet_time = time(NULL);
// Sending packets
send_packet(&bucket, 5); // Packet sent. Bucket level: 5
send_packet(&bucket, 3); // Packet sent. Bucket level: 8
send_packet(&bucket, 6); // Packet dropped. Bucket level: 8
send_packet(&bucket, 2); // Packet sent. Bucket level: 10
send_packet(&bucket, 4); // Packet dropped. Bucket level: 10
return 0;
}