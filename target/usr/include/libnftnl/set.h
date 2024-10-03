#ifndef _LIBNFTNL_SET_H_
#define _LIBNFTNL_SET_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#include <libnftnl/common.h>

enum {
	NFT_SET_ATTR_TABLE,
	NFT_SET_ATTR_NAME,
	NFT_SET_ATTR_FLAGS,
	NFT_SET_ATTR_KEY_TYPE,
	NFT_SET_ATTR_KEY_LEN,
	NFT_SET_ATTR_DATA_TYPE,
	NFT_SET_ATTR_DATA_LEN,
	NFT_SET_ATTR_FAMILY,
	NFT_SET_ATTR_ID,
	NFT_SET_ATTR_POLICY,
	NFT_SET_ATTR_DESC_SIZE,
	__NFT_SET_ATTR_MAX
};
#define NFT_SET_ATTR_MAX (__NFT_SET_ATTR_MAX - 1)

struct nft_set;

struct nft_set *nft_set_alloc(void);
void nft_set_free(struct nft_set *s);

bool nft_set_attr_is_set(const struct nft_set *s, uint16_t attr);
void nft_set_attr_unset(struct nft_set *s, uint16_t attr);
void nft_set_attr_set(struct nft_set *s, uint16_t attr, const void *data);
void nft_set_attr_set_data(struct nft_set *s, uint16_t attr, const void *data,
			   uint32_t data_len);
void nft_set_attr_set_u32(struct nft_set *s, uint16_t attr, uint32_t val);
void nft_set_attr_set_str(struct nft_set *s, uint16_t attr, const char *str);

const void *nft_set_attr_get(struct nft_set *s, uint16_t attr);
const void *nft_set_attr_get_data(struct nft_set *s, uint16_t attr,
				  uint32_t *data_len);
const char *nft_set_attr_get_str(struct nft_set *s, uint16_t attr);
uint32_t nft_set_attr_get_u32(struct nft_set *s, uint16_t attr);

struct nlmsghdr;

#define nft_set_nlmsg_build_hdr	nft_nlmsg_build_hdr
void nft_set_nlmsg_build_payload(struct nlmsghdr *nlh, struct nft_set *s);
int nft_set_nlmsg_parse(const struct nlmsghdr *nlh, struct nft_set *s);
int nft_set_elems_nlmsg_parse(const struct nlmsghdr *nlh, struct nft_set *s);

int nft_set_snprintf(char *buf, size_t size, struct nft_set *s, uint32_t type, uint32_t flags);
int nft_set_fprintf(FILE *fp, struct nft_set *s, uint32_t type, uint32_t flags);

struct nft_set_list;

struct nft_set_list *nft_set_list_alloc(void);
void nft_set_list_free(struct nft_set_list *list);
int nft_set_list_is_empty(struct nft_set_list *list);
void nft_set_list_add(struct nft_set *s, struct nft_set_list *list);
void nft_set_list_add_tail(struct nft_set *s, struct nft_set_list *list);
void nft_set_list_del(struct nft_set *s);
int nft_set_list_foreach(struct nft_set_list *set_list, int (*cb)(struct nft_set *t, void *data), void *data);

struct nft_set_list_iter;
struct nft_set_list_iter *nft_set_list_iter_create(struct nft_set_list *l);
struct nft_set *nft_set_list_iter_cur(struct nft_set_list_iter *iter);
struct nft_set *nft_set_list_iter_next(struct nft_set_list_iter *iter);
void nft_set_list_iter_destroy(struct nft_set_list_iter *iter);

int nft_set_parse(struct nft_set *s, enum nft_parse_type type,
		  const char *data, struct nft_parse_err *err);
int nft_set_parse_file(struct nft_set *s, enum nft_parse_type type,
		       FILE *fp, struct nft_parse_err *err);

/*
 * Set elements
 */

enum {
	NFT_SET_ELEM_ATTR_FLAGS,
	NFT_SET_ELEM_ATTR_KEY,
	NFT_SET_ELEM_ATTR_VERDICT,
	NFT_SET_ELEM_ATTR_CHAIN,
	NFT_SET_ELEM_ATTR_DATA,
};

struct nft_set_elem;

struct nft_set_elem *nft_set_elem_alloc(void);
void nft_set_elem_free(struct nft_set_elem *s);

void nft_set_elem_add(struct nft_set *s, struct nft_set_elem *elem);

void nft_set_elem_attr_unset(struct nft_set_elem *s, uint16_t attr);
void nft_set_elem_attr_set(struct nft_set_elem *s, uint16_t attr, const void *data, uint32_t data_len);
void nft_set_elem_attr_set_u32(struct nft_set_elem *s, uint16_t attr, uint32_t val);
void nft_set_elem_attr_set_str(struct nft_set_elem *s, uint16_t attr, const char *str);

const void *nft_set_elem_attr_get(struct nft_set_elem *s, uint16_t attr, uint32_t *data_len);
const char *nft_set_elem_attr_get_str(struct nft_set_elem *s, uint16_t attr);
uint32_t nft_set_elem_attr_get_u32(struct nft_set_elem *s, uint16_t attr);

bool nft_set_elem_attr_is_set(const struct nft_set_elem *s, uint16_t attr);

#define nft_set_elem_nlmsg_build_hdr	nft_nlmsg_build_hdr
void nft_set_elems_nlmsg_build_payload(struct nlmsghdr *nlh, struct nft_set *s);
void nft_set_elem_nlmsg_build_payload(struct nlmsghdr *nlh, struct nft_set_elem *e);

int nft_set_elem_parse(struct nft_set_elem *e, enum nft_parse_type type,
		       const char *data, struct nft_parse_err *err);
int nft_set_elem_parse_file(struct nft_set_elem *e, enum nft_parse_type type,
			    FILE *fp, struct nft_parse_err *err);
int nft_set_elem_snprintf(char *buf, size_t size, struct nft_set_elem *s, uint32_t type, uint32_t flags);
int nft_set_elem_fprintf(FILE *fp, struct nft_set_elem *se, uint32_t type, uint32_t flags);

int nft_set_elem_foreach(struct nft_set *s, int (*cb)(struct nft_set_elem *e, void *data), void *data);

struct nft_set_elems_iter;
struct nft_set_elems_iter *nft_set_elems_iter_create(struct nft_set *s);
struct nft_set_elem *nft_set_elems_iter_cur(struct nft_set_elems_iter *iter);
struct nft_set_elem *nft_set_elems_iter_next(struct nft_set_elems_iter *iter);
void nft_set_elems_iter_destroy(struct nft_set_elems_iter *iter);

int nft_set_elems_nlmsg_build_payload_iter(struct nlmsghdr *nlh,
					   struct nft_set_elems_iter *iter);

#endif /* _LIBNFTNL_SET_H_ */
