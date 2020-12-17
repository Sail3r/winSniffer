#pragma once
#include <map>
#include "pcap.h"
#include "packetHeader.h"

class packetPool {
private:
	std::map<int, packet> m_packet;
public:
	packetPool();
	~packetPool();

	void add(const struct pcap_pkthdr* header, const u_char* pkt_data);	// ������ݰ������ݰ���
	void add(packet& pkt);												// ������ݰ������ݰ���
	void remove(int pktNum);											// �����ݰ�����ɾ�����ݰ�
	void clear();														// ������ݰ�����ȫ�����ݰ�
	packet& get(int pktNum);											// ��ȡ���ݰ����ж�Ӧ���ݰ�
	packet& getLast();													// ��ȡ���ݰ��������һ�����ݰ�
	int getSize() const;												// ��ȡ���ݰ��������ݰ�����
	bool isEmpty() const;												// �ж����ݰ����Ƿ�Ϊ��
};