#ifndef _COMMON_H
#define _COMMON_H

/* 协议的定义举例 */
/* 用于对一个未知类型的消息进行验证和分类 */
struct base {
	unsigned char appid[4];
	unsigned char type;
};

/* 聊天消息 */
struct msg {
	unsigned char appid[4];
	unsigned char type;
	unsigned int from;
	unsigned int to;
	unsigned long datetime;
	unsigned char check_sum;
	unsigned short length;
	char msg[0];
} __attribute__((packed));

/* 登录请求 */
struct login {
	unsigned char appid[4];
	unsigned char type;
	unsigned int uid;
	unsigned char passwd[30];	
	unsigned char check_sum;
} __attribute__((packed));

/* 共用体 */
union msg {
	struct base bs;
	struct msg ms;
	struct login lg;
};

#endif
