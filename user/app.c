#include "uip.h"
#icnlude "dhcp.h"
/* UDPӦ�ò�  */
void UIP_UDP_APPCALL(){
	/* Զ�����Ӷ˿� */
	switch(uip_udp_conn->rport)	
	{
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
/* TCPӦ�ò�  */
void UIP_APPCALL(){
}