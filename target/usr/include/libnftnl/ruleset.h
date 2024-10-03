#ifndef _LIBNFTNL_RULESET_H_
#define _LIBNFTNL_RULESET_H_

#include <stdio.h>

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

#include <libnftnl/common.h>

#ifdef __cplusplus
extern "C" {
#endif

struct nft_ruleset;

struct nft_ruleset *nft_ruleset_alloc(void);
void nft_ruleset_free(struct nft_ruleset *r);

enum {
	NFT_RULESET_ATTR_TABLELIST = 0,
	NFT_RULESET_ATTR_CHAINLIST,
	NFT_RULESET_ATTR_SETLIST,
	NFT_RULESET_ATTR_RULELIST,
};

bool nft_ruleset_attr_is_set(const struct nft_ruleset *r, uint16_t attr);
void nft_ruleset_attr_unset(struct nft_ruleset *r, uint16_t attr);
void nft_ruleset_attr_set(struct nft_ruleset *r, uint16_t attr, void *data);
void *nft_ruleset_attr_get(const struct nft_ruleset *r, uint16_t attr);

int nft_ruleset_parse(struct nft_ruleset *rs, enum nft_parse_type type,
		      const char *data, struct nft_parse_err *err);
int nft_ruleset_parse_file(struct nft_ruleset *rs, enum nft_parse_type type,
			   FILE *fp, struct nft_parse_err *err);
int nft_ruleset_snprintf(char *buf, size_t size, const struct nft_ruleset *rs, uint32_t type, uint32_t flags);
int nft_ruleset_fprintf(FILE *fp, const struct nft_ruleset *rs, uint32_t type, uint32_t flags);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _LIBNFTNL_RULESET_H_ */
