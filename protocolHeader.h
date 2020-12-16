#pragma once

#define ETHERNET_HEADER_LENGTH	14
#define UDP_HEADER_LENGTH		8
#define DNS_HEADER_LENGTH		12

#define ETHERNET_TYPE_IP		0x0800
#define ETHERNET_TYPE_IPv6		0x86DD
#define ETHERNET_TYPE_ARP		0x0806

#define PROTOCOL_ICMP			1
#define PROTOCOL_IGMP			2		
#define PROTOCOL_TCP			6
#define PROTOCOL_UDP			17

#define PORT_HTTP				80

#define ARP_OPCODE_REQUEST		1
#define ARP_OPCODE_REPLY		2

/**
*	@brief	ICMP Type
*/
#define ICMP_TYPE_ECHO_REPLY													0
#define	ICMP_TYPE_DESTINATION_UNREACHABLE										3
#define ICMP_TYPE_SOURCE_QUENCH													4
#define ICMP_TYPE_REDIRECT														5
#define ICMP_TYPE_ECHO															8
#define ICMP_TYPE_ROUTER_ADVERTISEMENT											9
#define ICMP_TYPE_ROUTER_SOLICITATION											10
#define ICMP_TYPE_TIME_EXCEEDED													11
#define ICMP_TYPE_PARAMETER_PROBLEM												12
#define ICMP_TYPE_TIMESTAMP														13
#define ICMP_TYPE_TIMESTAMP_REPLY												14

/**
*	@brief	ICMP Code
*/
#define ICMP_TYPE_DESTINATION_UNREACHABLE_CODE_NET_UNREACHABLE					0
#define ICMP_TYPE_DESTINATION_UNREACHABLE_CODE_HOST_UNREACHABLE					1
#define ICMP_TYPE_DESTINATION_UNREACHABLE_CODE_PROTOCOL_UNREACHABLE				2
#define ICMP_TYPE_DESTINATION_UNREACHABLE_CODE_PORT_UNREACHABLE					3
#define ICMP_TYPE_DESTINATION_UNREACHABLE_CODE_FRAGMENTATION_NEEDED_AND_DF_SET	4
#define ICMP_TYPE_DESTINATION_UNREACHABLE_CODE_SOURCE_ROUTE_FAILED				5

#define ICMP_TYPE_SOURCE_QUENCH_CODE											0

#define ICMP_TYPE_REDIRECT_CODE_REDIRECT_DATAGRAMS_FOR_THE_NETWORK				0
#define ICMP_TYPE_REDIRECT_CODE_REDIRECT_DATAGRAMS_FOR_THE_HOST					1
#define ICMP_TYPE_REDIRECT_CODE_REDIRECT_DATAGRAMS_FOR_THE_TOS_AND_NETWORK		2
#define ICMP_TYPE_REDIRECT_CODE_REDIRECT_DATAGRAMS_FOR_THE_TOS_AND_HOST			3

#define ICMP_TYPE_ECHO_CODE														0

#define ICMP_TYPE_ROUTER_ADVERTISEMENT_CODE										0
#define ICMP_TYPE_ROUTER_SOLICITATION_CODE										0

#define ICMP_TYPE_TIME_EXCEEDED_CODE_TTL_EXCEEDED_IN_TRANSIT					0
#define ICMP_TYPE_TIME_EXCEEDED_CODE_FRAGMENT_REASSEMBLY_TIME_EXCEEDE			1

#define ICMP_TYPE_PARAMETER_PROBLEM_CODE_POINTER_INDICATES_THE_ERROR			0	

#define ICMP_TYPE_TIMESTAMP_CODE												0

/* 6λ Mac��ַ */
typedef struct MAC_Address {
	u_char bytes[6];
}MAC_Address;

/* 4λIP��ַ */
typedef struct IP_Address {
	u_char bytes[4];
}IP_Address;

typedef struct IPv6_Address {
	u_char bytes[16];
}IPv6_Address;

/* ������·��Ethernet */
typedef struct Ethernet_Header {
	MAC_Address dst;	// Ŀ��MAC��ַ
	MAC_Address src;	// ԴMAC��ַ
	u_short eth_type;	// ����
}Ethernet_Header;

/* IP���ݰ�ͷ�� */
typedef struct IP_Header {
	u_char		ver_headerLen;			// �汾��(4 bits) + �ײ�����(4 bits)
	u_char		tos;					// ��������
	u_short		total_len;				// �ܳ���
	u_short		identifier;				// ��ʶ
	u_short		flags_offset;			// ��־(3 bits) + Ƭƫ��(13 bits)
	u_char		ttl;					// ����ʱ��
	u_char		protocol;				// Э��
	u_short		checksum;				// �ײ�У���
	IP_Address	src;					// Դ��ַ
	IP_Address	dst;					// Ŀ�ĵ�ַ
	u_int		option_padding; 		// ѡ������				
}IP_Header;

/* ipv6���ݰ�ͷ�� */
typedef struct IPv6_Header {
	u_char			version;				// �汾��(4bits)
	u_char			traffic;				// ���ȼ�(8bits)
	u_short			label;					// ����ʶ(20bits��
	u_char			length[2];				// ���ĳ��ȣ�16 bit��
	u_char			next_header;			// ��һͷ����8 bit��
	u_char			limits;					// �������ƣ�8 bit��
	IPv6_Address	src;					// ԴIPv6��ַ��128 bit��
	IPv6_Address	dst;					// Ŀ��IPv6��ַ��128 bit��
} ipv6_header;

/* ARP���ݰ�ͷ�� */
typedef struct ARP_Header {
	u_short		hw_type;				// 16λӲ������
	u_short		protocol_type;			// 16λЭ������
	u_char		hw_len;					// 8λӲ������
	u_char		protocol_len;			// 8λЭ�鳤��
	u_short		opcode;					// 16λ������
	MAC_Address	src_mac;				// ԴMAC��ַ
	IP_Address	src_ip;					// ԴIP��ַ
	MAC_Address	dst_mac;				// Ŀ��MAC��ַ
	IP_Address	dst_ip;					// Ŀ��IP��ַ
	u_char		padding[18];			// ���
}ARP_Header;

/* ICMP���ݰ�ͷ�� */
typedef struct ICMP_Header {
	u_short		icmp_type;				// ����
	u_char		icmp_code;				// ����
	u_short		icmp_checksum;			// У���
	u_short		icmp_id;				// ICMP ID
	u_short		icmp_seq;				// ���к�
	u_short		icmp_timestamp;			// ʱ���
}ICMP_Header;

/* IGMP���ݰ�ͷ�� */
typedef struct IGMP_Header {
	u_short		igmp_type;				// ����
	u_short		max_resp;				// �����Ӧʱ��
	u_short		igmp_checksum;			// У���
	IP_Address	group_addr;				// ���ַ
}IGMP_Header;

/* TCP���ݰ�ͷ�� */
typedef struct TCP_Header {
	u_short		src;					// 16λԴ�˿�
	u_short		dst;    				// 16λĿ�Ķ˿�
	u_int 		seq;					// 32λ���
	u_int 		ack;					// 32λȷ�Ϻ�
	u_short		headerLen_rsv_flags; 	// �ײ�����(4 bits) + ����(6 bits) +  
										// URG(1 bit) + ACK(1 bit) + PSH(1 bit) + RST(1 bit) + SYN(1 bit) + FIN(1 bit)
	u_short		win_size;				// 16λ���ڴ�С
	u_short		checksum;				// 16λУ���
	u_short		urg_ptr;				// 16λ����ָ��
	u_int 		option;					// ѡ��
}TCP_Header;

/* UDP���ݰ�ͷ�� */
typedef struct UDP_Header {
	u_short		src;					// Դ�˿�
	u_short		dst;					// Ŀ�Ķ˿�
	u_short		len;					// ����
	u_short		checksum;				// У���

}UDP_Header;
