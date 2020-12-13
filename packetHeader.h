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

	int decodeEthernet();
	int decodeIP(u_char* L2Payload);
	int decodeIPv6(u_char* L2Payload);
	int decodeARP(u_char* L2Payload);
	int decodeICMP(u_char* L3Payload);
	int decodeIGMP(u_char* L3PayLoad);
	int decodeTCP(u_char *L3Payload);
	int decodeUDP(u_char *L3Payload);
	int decodeHTTP(u_char *L4Payload);

	int getIPHeaderLength() const;
	int getIPHeaderLengthRaw() const;
	int getIPFlags() const;
	int getIPFlagsMF() const;
	int getIPFlagDF() const;
	int getIPOffset() const;
	
	void search(CString keyword);

	u_short getICMPID()	const;
	u_short getICMPSeq() const;

	int getTCPHeaderLength() const;
	int getTCPHeaderLengthRaw() const;
	u_short getTCPFlags()		const;
	int getTCPFlagsURG()	const;
	int getTCPFlagsACK()	const;
	int getTCPFlagsPSH()	const;
	int getTCPFlagsRST()	const;
	int getTCPFlagsSYN()	const;
	int getTCPFlagsFIN()	const;

	int getL4PayloadLength() const;
};

CString getIPMessage(packet pkt);
CString getIPv6Message(packet pkt);
CString getARPMessage(packet pkt);