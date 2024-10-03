#ifndef _LIBNFTNL_COMMON_H_
#define _LIBNFTNL_COMMON_H_

#include <stdint.h>

enum {
	NFT_PARSE_EBADINPUT	= 0,
	NFT_PARSE_EMISSINGNODE,
	NFT_PARSE_EBADTYPE,
};

enum nft_output_type {
	NFT_OUTPUT_DEFAULT	= 0,
	NFT_OUTPUT_XML,
	NFT_OUTPUT_JSON,
};

enum nft_output_flags {
	NFT_OF_EVENT_NEW	= (1 << 0),
	NFT_OF_EVENT_DEL	= (1 << 1),
	NFT_OF_EVENT_ANY	= (NFT_OF_EVENT_NEW | NFT_OF_EVENT_DEL),
};

enum nft_parse_type {
	NFT_PARSE_NONE		= 0,
	NFT_PARSE_XML,
	NFT_PARSE_JSON,
	NFT_PARSE_MAX,
};

struct nft_parse_err;

struct nlmsghdr *nft_nlmsg_build_hdr(char *buf, uint16_t cmd, uint16_t family,
				     uint16_t type, uint32_t seq);

struct nft_parse_err *nft_parse_err_alloc(void);
void nft_parse_err_free(struct nft_parse_err *);
int nft_parse_perror(const char *str, struct nft_parse_err *err);

int nft_batch_is_supported(void);
void nft_batch_begin(char *buf, uint32_t seq);
void nft_batch_end(char *buf, uint32_t seq);

#endif
