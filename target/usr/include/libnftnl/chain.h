#ifndef _LIBNFTNL_CHAIN_H_
#define _LIBNFTNL_CHAIN_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#include <libnftnl/common.h>

#ifdef __cplusplus
extern "C" {
#endif

struct nft_chain;

struct nft_chain *nft_chain_alloc(void);
void nft_chain_free(struct nft_chain *);

enum {
	NFT_CHAIN_ATTR_NAME	= 0,
	NFT_CHAIN_ATTR_FAMILY,
	NFT_CHAIN_ATTR_TABLE,
	NFT_CHAIN_ATTR_HOOKNUM,
	NFT_CHAIN_ATTR_PRIO	= 4,
	NFT_CHAIN_ATTR_POLICY,
	NFT_CHAIN_ATTR_USE,
	NFT_CHAIN_ATTR_BYTES,
	NFT_CHAIN_ATTR_PACKETS	= 8,
	NFT_CHAIN_ATTR_HANDLE,
	NFT_CHAIN_ATTR_TYPE,
	__NFT_CHAIN_ATTR_MAX
};
#define NFT_CHAIN_ATTR_MAX (__NFT_CHAIN_ATTR_MAX - 1)

bool nft_chain_attr_is_set(const struct nft_chain *c, uint16_t attr);
void nft_chain_attr_unset(struct nft_chain *c, uint16_t attr);
void nft_chain_attr_set(struct nft_chain *t, uint16_t attr, const void *data);
void nft_chain_attr_set_data(struct nft_chain *t, uint16_t attr,
			     const void *data, uint32_t data_len);
void nft_chain_attr_set_u8(struct nft_chain *t, uint16_t attr, uint8_t data);
void nft_chain_attr_set_u32(struct nft_chain *t, uint16_t attr, uint32_t data);
void nft_chain_attr_set_s32(struct nft_chain *t, uint16_t attr, int32_t data);
void nft_chain_attr_set_u64(struct nft_chain *t, uint16_t attr, uint64_t data);
void nft_chain_attr_set_str(struct nft_chain *t, uint16_t attr, const char *str);

const void *nft_chain_attr_get(struct nft_chain *c, uint16_t attr);
const void *nft_chain_attr_get_data(struct nft_chain *c, uint16_t attr,
				    uint32_t *data_len);
const char *nft_chain_attr_get_str(struct nft_chain *c, uint16_t attr);
uint8_t nft_chain_attr_get_u8(struct nft_chain *c, uint16_t attr);
uint32_t nft_chain_attr_get_u32(struct nft_chain *c, uint16_t attr);
int32_t nft_chain_attr_get_s32(struct nft_chain *c, uint16_t attr);
uint64_t nft_chain_attr_get_u64(struct nft_chain *c, uint16_t attr);

struct nlmsghdr;

void nft_chain_nlmsg_build_payload(struct nlmsghdr *nlh, const struct nft_chain *t);

int nft_chain_parse(struct nft_chain *c, enum nft_parse_type type,
		    const char *data, struct nft_parse_err *err);
int nft_chain_parse_file(struct nft_chain *c, enum nft_parse_type type,
			 FILE *fp, struct nft_parse_err *err);
int nft_chain_snprintf(char *buf, size_t size, struct nft_chain *t, uint32_t type, uint32_t flags);
int nft_chain_fprintf(FILE *fp, struct nft_chain *c, uint32_t type, uint32_t flags);

#define nft_chain_nlmsg_build_hdr	nft_nlmsg_build_hdr
int nft_chain_nlmsg_parse(const struct nlmsghdr *nlh, struct nft_chain *t);

struct nft_chain_list;

struct nft_chain_list *nft_chain_list_alloc(void);
void nft_chain_list_free(struct nft_chain_list *list);
int nft_chain_list_is_empty(struct nft_chain_list *list);
int nft_chain_list_foreach(struct nft_chain_list *chain_list, int (*cb)(struct nft_chain *t, void *data), void *data);

void nft_chain_list_add(struct nft_chain *r, struct nft_chain_list *list);
void nft_chain_list_add_tail(struct nft_chain *r, struct nft_chain_list *list);
void nft_chain_list_del(struct nft_chain *c);

struct nft_chain_list_iter;

struct nft_chain_list_iter *nft_chain_list_iter_create(struct nft_chain_list *l);
struct nft_chain *nft_chain_list_iter_next(struct nft_chain_list_iter *iter);
void nft_chain_list_iter_destroy(struct nft_chain_list_iter *iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _LIBNFTNL_CHAIN_H_ */
