#include "uip.h"
#icnlude "dhcp.h"
#include "resolv.h"
/* UDP应用层  */
void UIP_UDP_APPCALL(){
	/* 远程连接端口 */
	switch(uip_udp_conn->rport)	
	{
		case HTONS(53):
			resolv_appcall();
			break;
		case HTONS(67):
			dhcpc_appcall();
			break;
	    default: 
	       break;
	}
	/* 本地连接端口 */
	switch(uip_udp_conn->lport)	
	{
		case HTONS(68):
			dhcpc_appcall();
			break;
	    default: 
			break;
	}
}