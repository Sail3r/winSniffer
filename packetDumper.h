#pragma once
#include "stdafx.h"

class packetDumper {
private:
	CString m_path;
public:
	packetDumper();
	~packetDumper();

	void setPath(CString path);						// ���û���·��
	CString getPath();								// ��ȡ·��

	void dump(CString path);						// ������Ϣ����
	void copyFile(CFile* dst, CFile* src);			// �����ļ�
};