#ifndef RAINBOW_PUBKEY_REORDER_API_H_INCLUDED
#define RAINBOW_PUBKEY_REORDER_API_H_INCLUDED

#define RAINBOW_LEN_PUB 163840
#define RAINBOW_LEN_PUBCHUNK 4096
#define RAINBOW_NUM_PUBCHUNKS 40

// public key chunks => public key (in the standard serialization format)
// no external dependencies
void rainbow_pub_reorder(unsigned char *pub, const unsigned char *pubchunks);

#endif // RAINBOW_PUBKEY_REORDER_API_H_INCLUDED
