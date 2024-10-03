#ifndef _LIBNFTNL_RULE_EXPR_H_
#define _LIBNFTNL_RULE_EXPR_H_

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct nft_rule_expr;

enum {
	NFT_RULE_EXPR_ATTR_NAME = 0,
	NFT_RULE_EXPR_ATTR_BASE,
};

struct nft_rule_expr *nft_rule_expr_alloc(const char *name);
void nft_rule_expr_free(struct nft_rule_expr *expr);

bool nft_rule_expr_is_set(const struct nft_rule_expr *expr, uint16_t type);
void nft_rule_expr_set(struct nft_rule_expr *expr, uint16_t type, const void *data, uint32_t data_len);
#define nft_rule_expr_set_data nft_rule_expr_set
void nft_rule_expr_set_u8(struct nft_rule_expr *expr, uint16_t type, uint8_t data);
void nft_rule_expr_set_u16(struct nft_rule_expr *expr, uint16_t type, uint16_t data);
void nft_rule_expr_set_u32(struct nft_rule_expr *expr, uint16_t type, uint32_t data);
void nft_rule_expr_set_u64(struct nft_rule_expr *expr, uint16_t type, uint64_t data);
void nft_rule_expr_set_str(struct nft_rule_expr *expr, uint16_t type, const char *str);

const void *nft_rule_expr_get(const struct nft_rule_expr *expr, uint16_t type, uint32_t *data_len);
#define nft_rule_expr_get_data nft_rule_expr_get
uint8_t nft_rule_expr_get_u8(const struct nft_rule_expr *expr, uint16_t type);
uint16_t nft_rule_expr_get_u16(const struct nft_rule_expr *expr, uint16_t type);
uint32_t nft_rule_expr_get_u32(const struct nft_rule_expr *expr, uint16_t type);
uint64_t nft_rule_expr_get_u64(const struct nft_rule_expr *expr, uint16_t type);
const char *nft_rule_expr_get_str(const struct nft_rule_expr *expr, uint16_t type);

struct nlmsghdr;

void nft_rule_expr_build_payload(struct nlmsghdr *nlh, struct nft_rule_expr *expr);

int nft_rule_expr_snprintf(char *buf, size_t buflen, struct nft_rule_expr *expr, uint32_t type, uint32_t flags);

enum {
	NFT_EXPR_PAYLOAD_DREG	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_PAYLOAD_BASE,
	NFT_EXPR_PAYLOAD_OFFSET,
	NFT_EXPR_PAYLOAD_LEN,
};

enum {
	NFT_EXPR_META_KEY	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_META_DREG,
	NFT_EXPR_META_SREG,
};

enum {
	NFT_EXPR_CMP_SREG	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_CMP_OP,
	NFT_EXPR_CMP_DATA,
};

enum {
	NFT_EXPR_IMM_DREG	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_IMM_DATA,
	NFT_EXPR_IMM_VERDICT,
	NFT_EXPR_IMM_CHAIN,
};

enum {
	NFT_EXPR_CTR_PACKETS	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_CTR_BYTES,
};

enum {
	NFT_EXPR_BITWISE_SREG	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_BITWISE_DREG,
	NFT_EXPR_BITWISE_LEN,
	NFT_EXPR_BITWISE_MASK,
	NFT_EXPR_BITWISE_XOR,
};

enum {
	NFT_EXPR_TG_NAME	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_TG_REV,
	NFT_EXPR_TG_INFO,
};

enum {
	NFT_EXPR_MT_NAME	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_MT_REV,
	NFT_EXPR_MT_INFO,
};

enum {
	NFT_EXPR_NAT_TYPE		= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_NAT_FAMILY,
	NFT_EXPR_NAT_REG_ADDR_MIN,
	NFT_EXPR_NAT_REG_ADDR_MAX,
	NFT_EXPR_NAT_REG_PROTO_MIN,
	NFT_EXPR_NAT_REG_PROTO_MAX,
	NFT_EXPR_NAT_FLAGS,
};

enum {
	NFT_EXPR_LOOKUP_SREG	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_LOOKUP_DREG,
	NFT_EXPR_LOOKUP_SET,
	NFT_EXPR_LOOKUP_SET_ID,
};

enum {
	NFT_EXPR_LOG_PREFIX	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_LOG_GROUP,
	NFT_EXPR_LOG_SNAPLEN,
	NFT_EXPR_LOG_QTHRESHOLD,
	NFT_EXPR_LOG_LEVEL,
	NFT_EXPR_LOG_FLAGS,
};

enum {
	NFT_EXPR_EXTHDR_DREG	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_EXTHDR_TYPE,
	NFT_EXPR_EXTHDR_OFFSET,
	NFT_EXPR_EXTHDR_LEN,
};

enum {
	NFT_EXPR_CT_DREG	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_CT_KEY,
	NFT_EXPR_CT_DIR,
	NFT_EXPR_CT_SREG,
};

enum {
	NFT_EXPR_BYTEORDER_DREG	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_BYTEORDER_SREG,
	NFT_EXPR_BYTEORDER_OP,
	NFT_EXPR_BYTEORDER_LEN,
	NFT_EXPR_BYTEORDER_SIZE,
};

enum {
	NFT_EXPR_LIMIT_RATE	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_LIMIT_UNIT,
};

enum {
	NFT_EXPR_REJECT_TYPE	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_REJECT_CODE,
};

enum {
	NFT_EXPR_QUEUE_NUM	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_QUEUE_TOTAL,
	NFT_EXPR_QUEUE_FLAGS,
};

enum {
	NFT_EXPR_MASQ_FLAGS	= NFT_RULE_EXPR_ATTR_BASE,
};

enum {
	NFT_EXPR_REDIR_REG_PROTO_MIN	= NFT_RULE_EXPR_ATTR_BASE,
	NFT_EXPR_REDIR_REG_PROTO_MAX,
	NFT_EXPR_REDIR_FLAGS,
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _LIBNFTNL_RULE_EXPR_H_ */
