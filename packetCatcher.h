#pragma once
#include "pcap.h"
#include "packetPool.h"
#include "atltime.h"

#define WM_TEXTIT (WM_USER + 101)
#define WM_PKTCATCH (WM_USER + 100)

const int MODE_CAPTURE_LIVE = 0;
const int MODE_CAPTURE_OFFLINE = 1;
const int READ_PACKET_TIMEOUT = 1000;

UINT capture_thread(LPVOID pParam);
void packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);


class packetCatcher {
private:
	pcap_t* m_adhandle;		// 网卡描述符
	packetPool* m_pool;		// 数据包池的指针
	pcap_dumper_t *m_dumper;// 转储文件描述符
	CString m_dev;			// 网卡/文件信息
public:
	packetCatcher();
	packetCatcher(packetPool* pool);
	~packetCatcher();

	bool setPool(packetPool* pool);												// 初始化数据包池
	bool openAdapter(int selItemIndexOfDevList, const CTime& currentTime);		// 打开对应网卡
	bool openAdapter(CString path);												// 开启路径下储存的网卡信息
	bool closeAdapter();														// 关闭网卡
	void startCapture(int mode);												// 开启抓包线程
	void stopCapture();															// 停止抓包线程
	CString getDevName();														// 获取设备名称
};