#include "common.h"

/* 协议的应用举例 */
/* 验证消息 */
int verify(struct base *bs)
{
	if (验证应用 ID：bs->appid 失败) {
		return -1; 
	} else {
		return bs->type;
	}
}

/* 处理消息 */
int handle_msg(union msg *msg)
{
	int type = verify(&msg->bs);
	if (-1 == type) return -1;
	switch (type) {
	case CHAT_MSG:  /* 聊天消息 */
		handle_chat((struct msg *) msg);
		break;
	case LOGIN:     /* 登录消息 */
		handle_login((struct login *) msg);
		break;
	}
}

