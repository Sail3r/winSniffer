#pragma once
#include "packetPool.h"
#include "pcap.h"

/**
*	����������capture_thread()�н��в�������
*/
class threadParam
{
public:
	pcap_t* m_adhandle;
	packetPool* m_pool;
	pcap_dumper_t* m_dumper;
	int				m_mode;

	threadParam();
	threadParam(pcap_t* adhandle, packetPool* pool, pcap_dumper_t* dumper, int mode);
	~threadParam();
};