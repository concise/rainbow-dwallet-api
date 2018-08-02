#ifndef RAINBOW_API_H_INCLUDED
#define RAINBOW_API_H_INCLUDED

#define RAINBOW_LEN_DGST 32         // number of bytes in a message digest
#define RAINBOW_LEN_SIG 64          // number of bytes in a digital signature
#define RAINBOW_LEN_SEED 32         // number of bytes in an account secret seed
#define RAINBOW_LEN_PRV 8192        // number of bytes in an account private key

#define RAINBOW_LEN_PUB 163840      // number of bytes in an account public key
#define RAINBOW_LEN_PUBCHUNK 4096   // number of bytes in a public key chunk
#define RAINBOW_NUM_PUBCHUNKS 40    // number of chunks in a public key

// the working buffer byte lengths of for corresponding subroutines
#define RAINBOW_LEN_CTX_SEED2PRV 10000
#define RAINBOW_LEN_CTX_SIGN 99999
#define RAINBOW_LEN_CTX_PRV2PUBCHUNK 99999

// secret seed => private key
// depends on external modules for: CSPRNG
// takes at most 1 MCU second
void rainbow_seed2prv(void *ctx, unsigned char *prv, const unsigned char *seed);

// private key, chunk id => a chunk of public key (only 4096 bytes)
// no external dependencies
// takes at most 10 MCU seconds (about 7 MCU minutes for full public key)
void rainbow_prv2pubchunk(void *ctx, unsigned char *pubchunk, const unsigned char *prv, unsigned chunkid);

// private key, message digest => digital signature
// depends on external modules for: TRNG, SHA256
// takes at most 5 MCU seconds
void rainbow_sign(void *ctx, unsigned char *sig, const unsigned char *prv, const unsigned char *dgst);

#endif // RAINBOW_API_H_INCLUDED
