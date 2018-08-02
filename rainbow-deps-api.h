#ifndef RAINBOW_DEPS_API_H_INCLUDED
#define RAINBOW_DEPS_API_H_INCLUDED

// SHA-256
void sha256(unsigned char *dgst, const unsigned char *msg, unsigned msglen);

// secure true randomness generator
void trng(void *out, unsigned numbytes);

// secure deterministic randomness generator (ref: Hash_DRBG / HMAC_DRBG / CTR_DRBG specified in NIST SP 800-90A)
#define LEN_PRNG_CTX 64
void prng_setup(void *prng_ctx, const void *seed, unsigned seedlen);
void prng_gen(void *prng_ctx, void *out, unsigned numbytes);

#endif // RAINBOW_DEPS_API_H_INCLUDED
