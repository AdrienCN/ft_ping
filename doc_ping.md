/*
Fonctions & MAN :
# getprotobyname (3)
# raw (7)  sock raw info
# socket () socket info
# setsockopt(2)
# getsockopt
# sendto (2)
# recvfrom(2)
# ip (7)
# capabilities(7)

==========================================
Infos & Details 
==========================================


ICMP Protocol: (OSI Layer 3 : Network )
- ICMP protocol allows devices to exchange messages.
- Does not use PORT. 
    Direct HOST to HOST exchange
    No data
    Just info MSG

- 3 msgs : errors, queries, and responses.
        - Error : inform sender about pbm preventing the sender's packets from reaching their destination.
        - Query and response : used to exchange information about network.
                               Query and response messages are always used in pairs 
                               where one device sends a query message and another sends
                               a reply or response to the query message.
                               The ping command uses query-response messages.
https://www.computernetworkingnotes.com/networking-tutorials/icmp-internet-control-message-protocol.html


SOCKET :
    Permet d'ouvrir un canal de communication pour que des devices echange des infos sur le reseau.
    La socket necessite : IP + PORT + PROTOCOLE de communication
    PING = RAW socket

    --> SOCK_STREAM : Stream socket provides a reliable, bidirectional
                        and connection-oriented communication channel between two processes.
                        Data are carried using the Transmission Control Protocol (TCP)

    --> SOCK_DGRAM  : Datagram socket does not guarantee reliability and is connectionless.
                        As a result, the transmission is faster. 
                        Data are carried using the User Datagram Protocol (UDP)

    --> SOCK_RAW ( man 7 raw )   : Create an Internet Protocol (IP) datagram socket. 
                        A Raw socket skips the TCP/UDP transport layer and 
                            sends the packets directly to the network layer
    ! In order to create a raw socket, a process must have the CAP_NET_RAW capability 
        in the user namespace that governs its network namespace.

    


SIGNAUX :
   SIGINT
    Interrompre le programme et print les infos 
    
    SIGQUIT
        Ne pas interrompre et print les current infos
    
    SIGALRM 
        ????




Use ICMP protocol to send ECHO_REQUEST to DESTare used to
 - DEST :
    IPV4 or Domain name

 - ECHO_REQUEST :
    IP and ICMP header + “struct timeval" + arbitrary number of "pad" bytes used to fill out the packet.

==========================================
STEPS 
==========================================

    PARSING :

    ALGO :
        - Build ECHO_REQUEST
        - Open ICMP socket (AF_INT, SOCK_RAW, IPPROTO_RAW ? IPPROTO_ICMP ?) ICMP_FILTER ?
        - Send ECHO_REQUES T
        - Listen for ECHO_REPLY
        - Output 

    PRINT OUTPUT :

    ERROR HANDLING :
    ERROR 01 :
        If ping does not receive any reply packets at all it will exit with code 1. If a packet count and deadline are both specified, and fewer than count packets are received by the time the deadline has arrived, it
       will also exit with code 1.
    ERROR 02 :
        On other error it exits with code 2. Otherwise it exits with code 0. 
    
    ERROR00:
        All good 

==========================================
 Question : 
==========================================
 - How to resolve DNS name ?
 - What composes an ECHO_REQUEST datagram ?
 - RTT ?
 - Default number of packer if not specified ?
 - behaviour if no answer ?
    - Do we quit ?
    - How long to wait ?
    - Do we print something ?

 - Qu'est ce que sont les linux cap ?
 - Comment donner les cap au user qui lance ping ?
 - IPPROTO_ICMP ou  IPPROTO_IP ou IPPROTO_RAW ?
 - Utiliser l'option ICMP_FILTER ?

 x Comment catcher les signaux ?
    --> Pas besoin de faire quoique ce soit.
        Le programme s'occupe de catcher le signal tout seul. 
        Il faut par contre utiliser la fonction sigaction() pour parametrer le comportement a adopter en cas de catch du signal.
        Autrement le programme utilise le comportement par default. ( parametre dans le kernel?)
        ! deconseiller d'utiliser signal qui est deprecated car son comportement n'est pas uniforme entre les implementations.

  x Liste des signaux a catcher ?
    Selon le code source de ping on laisse le comportement par default
    Sauf sur ces 3 signaux
    SIGINT
    SIGALARM
    SIGQUIT

 x How to send packet using the ICMP protocol ? 
    --> open RAW socket




    TO DO
# REFRACTORING / CODING

- Documentation des protode fonctions

# Parsing
- List all possible parsing or CLI errors
- Implement all parsing error
    - IP PARSING
        - parsing false leading 0 . ie : 08.8.8.8 or 8.8.08.8
- use  getopt ?

# SIGNAL HANDLING 
    - use volatile var to store exitsignal and status snapshot  ?
    - Implementer  SIGINT  (Ctrl+C) --> sigexit
    - Implementer SIGQUIT  (Ctrl+\) --> sigstatus 
        - Ne pas quitter le prog en en repetant SIGQUIT+++
    - Implementer SIGALRM           --> sigexit
        - Comment declencher sigalarm ?
        - Trouver le comportement.

# ALGO 

    SOCKET_RAW :

    ICMP_ECHO_REQUEST:
        -





    STATS :
        -RTT (round trip time) min/avg/max/mdev (include duplicate pkt see man )
            -min
            -avg
            -max
            -mdev : avg of how far each ping RTT is from mean RTT
        -Packet loss (DO NOT calculate duplicate pkt)
    
    PRINT :
        -ON START :
            "PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data."
        - RUNNING :
            "64 bytes from 8.8.8.8: icmp_seq=2 ttl=114 time=7.82 ms"

        - SIGQUIT:
            "1/1 packets, 0% loss, min/avg/ewma/max = 7.629/7.629/7.629/7.629 ms"

        - EXIT :
            "--- 8.8.8.8 ping statistics ---
            packets transmitted, 7 received, 0% packet loss, time 6007ms
            rtt min/avg/max/mdev = 7.629/15.844/63.836/19.592 ms
            "

# ERROR HANDLING
- associate struct ou fonction ERR_CODE - ERR_STRING
- DUPLICATE pkts
- BROKEN PKTS


# END CHECKS
- Virer les (void)
- Remove DEBUG OPTION in makefile
*/