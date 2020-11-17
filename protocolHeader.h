#pragma once

#define ETHERNET_HEADER_LENGTH 14
#define UDP_HEADER_LENGTH 8

#define ETHERNET_TYPE_IP 0x0800
#define ETHERNET_TYPE_ARP 0x0806

#define PROTOCOL_TCP 6
#define PROTOCOL_UDP 17

#define PORT_HTTP 80

typedef struct MAC_Address {
	char bytes[6];
}MAC_Address;

typedef struct IP_Address {
	char bytes[4];
}IP_Address;

typedef struct Ethernet_Header {
	MAC_Address dst;
	MAC_Address src;
	short eth_type;
}Ethernet_Header;

typedef struct IP_Header {
	char		ver_headerLen;			// �汾��(4 bits) + �ײ�����(4 bits)
	char		service;				// ��������
	short		total_len;				// �ܳ���
	short		identifier;				// ��ʶ
	short		flags_offset;			// ��־(3 bits) + Ƭƫ��(13 bits)
	char		ttl;					// ����ʱ��
	char		protocol;				// �ϲ�Э��
	short		checksum;				// �ײ�У���
	IP_Address	src;					// Դ��ַ
	IP_Address	dst;					// Ŀ�ĵ�ַ
	int			option_padding; 		// ѡ������

}IP_Header;

typedef struct TCP_Header {
	short		src;					// Դ�˿�
	short		dst;    				// Ŀ�Ķ˿�
	int 		seq;					// ���
	int 		ack;					// ȷ�Ϻ�
	short		headerLen_rsv_flags;	// �ײ�����(4 bits) + ����(6 bits) + 
										// URG(1 bit) + ACK(1 bit) + PSH(1 bit) + RST(1 bit) + SYN(1 bit) + FIN(1 bit)
	short		win_size;				// ���ڴ�С
	short		checksum;				// У���
	short		urg_ptr;				// ����ָ��
	int 		option;					// ѡ��

}TCP_Header;

typedef struct UDP_Header {
	short		src;					// Դ�˿�
	short		dst;					// Ŀ�Ķ˿�
	short		len;					// ����
	short		checksum;				// У���

}UDP_Header;