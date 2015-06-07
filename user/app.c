#include "uip.h"
#icnlude "dhcp.h"
/* UDP应用层  */
void UIP_UDP_APPCALL(){
	/* 远程连接端口 */
	switch(uip_udp_conn->rport)	
	{
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
/* TCP应用层  */
void UIP_APPCALL(){
}