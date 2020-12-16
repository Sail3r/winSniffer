#pragma once
#include "packetHeader.h"
#include "stdafx.h"

/* MAC��ַת��ΪCString��ʽ */
CString MACAddr2CString(const MAC_Address& addr);

/* IP��ַת��ΪCString��ʽ */
CString IPAddr2CString(const IP_Address& addr);

/* IPv6��ַת��ΪCString��ʽ */
CString IPv6Addr2CString(const IPv6_Address& addr);