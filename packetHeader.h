#pragma once
#include "protocolHeader.h"
#include <vector>
#include <string>

class packet {
public:
	Ethernet_Header *eth_header;					// eth�ײ�
	IP_Header		*ip_header;						// IPv4�ײ�
	IPv6_Header		*ipv6_header;					// IPv6�ײ�
	ARP_Header		*arp_header;					// ARP�ײ�
	ICMP_Header		*icmp_header;					// ICMP�ײ�
	IGMP_Header		*igmp_header;					// IGMP�ײ�
	TCP_Header		*tcp_header;					// TCP�ײ�
	UDP_Header		*udp_header;					// UDP�ײ�
	
	CString			message;						// ���ݱ���Я������Ϣ����
	u_char			*http_msg;						// HTTP����
	u_char			*packet_data;					// ���ݰ�
	struct pcap_pkthdr	*header;					// �������ݰ����ȣ����ݰ�����ʱ��
	u_short			num;							// ���ݰ���ţ���1��ʼ
	CString         protocol;						// Э��

	packet();
	packet(const packet& p);
	packet(const struct pcap_pkthdr* header, const u_char* pkt_data, const u_short& packet_num);
	packet& operator=(const packet& p);
	~packet();

	bool isEmpty() const;

	int decodeEthernet();							// ����Ethernet���ݰ�
	int decodeIP(u_char* L2Payload);				// ����IP���ݰ�
	int decodeIPv6(u_char* L2Payload);				// ����IPv6���ݰ�
	int decodeARP(u_char* L2Payload);				// ����ARP���ݰ�
	int decodeICMP(u_char* L3Payload);				// ����ICMP���ݰ�
	int decodeIGMP(u_char* L3PayLoad);				// ����IGMP���ݰ�
	int decodeTCP(u_char *L3Payload);				// ����TCP���ݰ�
	int decodeUDP(u_char *L3Payload);				// ����UDP���ݰ�
	int decodeHTTP(u_char *L4Payload);				// ����HTTP���ݰ�

	int getIPHeaderLength() const;					// ��ȡIP���ݰ�ͷ������
	int getIPHeaderLengthRaw() const;				// ��ȡIP���ݰ�ͷ������(RAW)
	int getIPFlags() const;							// ��ȡIP���ݰ���־λ
	int getIPFlagsMF() const;						// ��ȡIP���ݰ�MF��־λ
	int getIPFlagDF() const;						// ��ȡIP���ݰ�DF��־λ
	int getIPOffset() const;						// ��ȡIP���ݰ�Ƭƫ����
	
	bool search(CString keyword);					// ����������Ϣ�������ݰ�

	u_short getICMPID()	const;						// ��ȡICMP���ݰ�ID
	u_short getICMPSeq() const;						// ��ȡICMP���ݰ�Seq

	int getTCPHeaderLength() const;					// ��ȡTCP���ݰ�ͷ������
	int getTCPHeaderLengthRaw() const;				// ��ȡTCP���ݰ�ͷ������(RAW)
	u_short getTCPFlags()		const;				// ��ȡTCP���ݰ���־λ
	int getTCPFlagsURG()	const;					// ��ȡTCP���ݰ�URG��־λ
	int getTCPFlagsACK()	const;					// ��ȡTCP���ݰ�ACK��־λ
	int getTCPFlagsPSH()	const;					// ��ȡTCP���ݰ�PSH��־λ
	int getTCPFlagsRST()	const;					// ��ȡTCP���ݰ�RST��־λ
	int getTCPFlagsSYN()	const;					// ��ȡTCP���ݰ�SYN��־λ
	int getTCPFlagsFIN()	const;					// ��ȡTCP���ݰ�FIN��־λ

	int getL4PayloadLength() const;					// ��ȡ���ݰ����Ĳ㸺�س���
};

CString getIPMessage(packet pkt);					// ��ȡIP���ݰ���Ӧ��Ϣ
CString getIPv6Message(packet pkt);					// ��ȡIPv6���ݰ���Ӧ��Ϣ
CString getARPMessage(packet pkt);					// ��ȡARP���ݰ���Ӧ��Ϣ