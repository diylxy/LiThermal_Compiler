#ifndef _LIBNFTNL_RULE_H_
#define _LIBNFTNL_RULE_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#include <libnftnl/common.h>

#ifdef __cplusplus
extern "C" {
#endif

struct nft_rule;
struct nft_rule_expr;

struct nft_rule *nft_rule_alloc(void);
void nft_rule_free(struct nft_rule *);

enum {
	NFT_RULE_ATTR_FAMILY	= 0,
	NFT_RULE_ATTR_TABLE,
	NFT_RULE_ATTR_CHAIN,
	NFT_RULE_ATTR_HANDLE,
	NFT_RULE_ATTR_COMPAT_PROTO,
	NFT_RULE_ATTR_COMPAT_FLAGS,
	NFT_RULE_ATTR_POSITION,
	NFT_RULE_ATTR_USERDATA,
	__NFT_RULE_ATTR_MAX
};
#define NFT_RULE_ATTR_MAX (__NFT_RULE_ATTR_MAX - 1)

void nft_rule_attr_unset(struct nft_rule *r, uint16_t attr);
bool nft_rule_attr_is_set(const struct nft_rule *r, uint16_t attr);
void nft_rule_attr_set(struct nft_rule *r, uint16_t attr, const void *data);
void nft_rule_attr_set_data(struct nft_rule *r, uint16_t attr,
			    const void *data, uint32_t data_len);
void nft_rule_attr_set_u32(struct nft_rule *r, uint16_t attr, uint32_t val);
void nft_rule_attr_set_u64(struct nft_rule *r, uint16_t attr, uint64_t val);
void nft_rule_attr_set_str(struct nft_rule *r, uint16_t attr, const char *str);

const void *nft_rule_attr_get(const struct nft_rule *r, uint16_t attr);
const void *nft_rule_attr_get_data(const struct nft_rule *r, uint16_t attr,
				   uint32_t *data_len);
const char *nft_rule_attr_get_str(const struct nft_rule *r, uint16_t attr);
uint8_t nft_rule_attr_get_u8(const struct nft_rule *r, uint16_t attr);
uint32_t nft_rule_attr_get_u32(const struct nft_rule *r, uint16_t attr);
uint64_t nft_rule_attr_get_u64(const struct nft_rule *r, uint16_t attr);

void nft_rule_add_expr(struct nft_rule *r, struct nft_rule_expr *expr);

struct nlmsghdr;

void nft_rule_nlmsg_build_payload(struct nlmsghdr *nlh, struct nft_rule *t);

int nft_rule_parse(struct nft_rule *r, enum nft_parse_type type,
		   const char *data, struct nft_parse_err *err);
int nft_rule_parse_file(struct nft_rule *r, enum nft_parse_type type,
			FILE *fp, struct nft_parse_err *err);
int nft_rule_snprintf(char *buf, size_t size, struct nft_rule *t, uint32_t type, uint32_t flags);
int nft_rule_fprintf(FILE *fp, struct nft_rule *r, uint32_t type, uint32_t flags);

#define nft_rule_nlmsg_build_hdr	nft_nlmsg_build_hdr
int nft_rule_nlmsg_parse(const struct nlmsghdr *nlh, struct nft_rule *t);

int nft_rule_expr_foreach(struct nft_rule *r,
			  int (*cb)(struct nft_rule_expr *e, void *data),
			  void *data);

struct nft_rule_expr_iter;

struct nft_rule_expr_iter *nft_rule_expr_iter_create(struct nft_rule *r);
struct nft_rule_expr *nft_rule_expr_iter_next(struct nft_rule_expr_iter *iter);
void nft_rule_expr_iter_destroy(struct nft_rule_expr_iter *iter);

struct nft_rule_list;

struct nft_rule_list *nft_rule_list_alloc(void);
void nft_rule_list_free(struct nft_rule_list *list);
int nft_rule_list_is_empty(struct nft_rule_list *list);
void nft_rule_list_add(struct nft_rule *r, struct nft_rule_list *list);
void nft_rule_list_add_tail(struct nft_rule *r, struct nft_rule_list *list);
void nft_rule_list_del(struct nft_rule *r);
int nft_rule_list_foreach(struct nft_rule_list *rule_list, int (*cb)(struct nft_rule *t, void *data), void *data);

struct nft_rule_list_iter;

struct nft_rule_list_iter *nft_rule_list_iter_create(struct nft_rule_list *l);
struct nft_rule *nft_rule_list_iter_cur(struct nft_rule_list_iter *iter);
struct nft_rule *nft_rule_list_iter_next(struct nft_rule_list_iter *iter);
void nft_rule_list_iter_destroy(struct nft_rule_list_iter *iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _LIBNFTNL_RULE_H_ */
