#pragma once
#include "protocolHeader.h"

class packet {
public:
	Ethernet_Header *eth_header;					// ��̫���ײ�
	IP_Header		*ip_header;						// IP�ײ�
	TCP_Header		*tcp_header;					// TCP�ײ�
	UDP_Header		*udp_header;					// UDP�ײ�

	char			*http_msg;						// HTTP����
	char			*packet_data;					// ���ݰ�
	struct pcap_pkthdr	*header;					// �������ݰ����ȣ����ݰ�����ʱ��
	short			num;							// ���ݰ���ţ���1��ʼ
	CString         protocol;						// Э��

	packet();
	packet(const packet& p);
	packet(const struct pcap_pkthdr* header, const char* pkt_data, const short& packet_num);
	packet& operator=(const packet& p);
	~packet();

	bool isEmpty() const;

	int decodeEthernet();
	int decodeIP(char *L2Payload);
	int decodeTCP(char *L3Payload);
	int decodeUDP(char *L3Payload);
	int decodeHTTP(char *L4Payload);

	int getIPHeaderLength() const;
	int getIPHeaderLengthRaw() const;
	int getIPFlags() const;
	int getIPFlagsMF() const;
	int getIPFlagDF() const;
	int getIPOffset() const;

	int getTCPHeaderLength() const;
	int getTCPHeaderLengthRaw() const;
	short getTCPFlags()		const;
	int getTCPFlagsURG()	const;
	int getTCPFlagsACK()	const;
	int getTCPFlagsPSH()	const;
	int getTCPFlagsRST()	const;
	int getTCPFlagsSYN()	const;
	int getTCPFlagsFIN()	const;

	int getL4PayloadLength() const;
};