#include "uip.h"
#icnlude "dhcp.h"
#include "resolv.h"
/* UDPӦ�ò�  */
void UIP_UDP_APPCALL(){
	/* Զ�����Ӷ˿� */
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
	/* �������Ӷ˿� */
	switch(uip_udp_conn->lport)	
	{
		case HTONS(68):
			dhcpc_appcall();
			break;
	    default: 
			break;
	}
}