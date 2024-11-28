#ifndef silverchain_UniversalSocket_imp
#define silverchain_UniversalSocket_imp



#include <string.h>
#include <stdio.h>
#include <stdint.h>






#if defined(__linux__)

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#endif

#if defined(_WIN32)

#include <winsock2.h>
#include <ws2tcpip.h>

#endif

#endif

#ifndef silverchain_UniversalSocket_mac
#define silverchain_UniversalSocket_mac

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#define UNI_AF_INET AF_INET
#define UNI_INADDR_ANY INADDR_ANY
#define UNI_FD_SET FD_SET
#define UNI_FD_CLR FD_CLR
#define UNI_FD_ISSET FD_ISSET
#define UNI_FD_ZERO FD_ZERO
#define UNI_SOCK_STREAM SOCK_STREAM
#define UNI_SOCK_DGRAM SOCK_DGRAM
#define UNI_SOCK_RAW SOCK_RAW
#define UNI_MSG_PEEK MSG_PEEK
#define UNI_MSG_WAITALL MSG_WAITALL
#define UNI_SO_RCVTIMEO SO_RCVTIMEO
#define UNI_SO_SNDTIMEO SO_SNDTIMEO
#define UNI_SO_KEEPALIVE SO_KEEPALIVE
#define UNI_SO_BROADCAST SO_BROADCAST
#define UNI_SO_LINGER SO_LINGER
#define UNI_AF_UNSPEC AF_UNSPEC
#define UNI_IPPROTO_TCP IPPROTO_TCP
#define UNI_IPPROTO_UDP IPPROTO_UDP
#define UNI_MSG_OOB MSG_OOB
#define UNI_AF_INET6 AF_INET6
#define UNI_SHUT_RD SHUT_RD
#define UNI_SHUT_WR SHUT_WR
#define UNI_SHUT_RDWR SHUT_RDWR

#define UNI_SO_REUSEADDR SO_REUSEADDR
#define UNI_SO_RCVBUF SO_RCVBUF
#define UNI_SOL_SOCKET SOL_SOCKET
#define UNI_AF_INET6 AF_INET6

#define UNI_INET6_ADDRSTRLEN INET6_ADDRSTRLEN




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#if defined(__linux__)

#define UNI_INVALID_SOCKET -1
#define UNI_SOCKET_ERROR -1
#define UNI_EAGAIN EAGAIN
#define UNI_EWOULDBLOCK EWOULDBLOCK

#define UNI_ECONNREFUSED ECONNREFUSED
#define UNI_ETIMEDOUT ETIMEDOUT
#define UNI_EINPROGRESS EINPROGRESS
#define UNI_EADDRNOTAVAIL EADDRNOTAVAIL
#define UNI_ENETUNREACH ENETUNREACH

#endif


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end



#if defined(_WIN32)

#define UNI_INVALID_SOCKET INVALID_SOCKET
#define UNI_SOCKET_ERROR SOCKET_ERROR
#define UNI_EAGAIN WSAEWOULDBLOCK
#define UNI_EWOULDBLOCK WSAEWOULDBLOCK

#define UNI_ECONNREFUSED WSAECONNREFUSED
#define UNI_ETIMEDOUT WSAETIMEDOUT
#define UNI_EINPROGRESS WSAEINPROGRESS
#define UNI_EADDRNOTAVAIL WSAEADDRNOTAVAIL
#define UNI_ENETUNREACH WSAENETUNREACH

#endif








#endif

#ifndef silverchain_UniversalSocket_types
#define silverchain_UniversalSocket_types

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

typedef struct sockaddr Universal_sockaddr;

typedef struct sockaddr_in Universal_sockaddr_in;

typedef struct sockaddr_in6 Universal_sockaddr_in6;

typedef struct sockaddr_storage Universal_sockaddr_storage;

typedef struct addrinfo Universal_addrinfo;

typedef struct in_addr Universal_in_addr;

typedef struct in6_addr Universal_in6_addr;






//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

#if defined(__linux__)

typedef int Universal_socket_int;

typedef socklen_t Universal_socket_len;

typedef unsigned int Universal_DWORD;

#endif


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end




#if defined(_WIN32)

typedef SOCKET Universal_socket_int;

typedef int Universal_socket_len;

typedef DWORD Universal_DWORD;

typedef unsigned long in_addr_t;

#endif

#endif

#ifndef silverchain_UniversalSocket_dec
#define silverchain_UniversalSocket_dec

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end



extern const char* Universal_inet_ntoa(Universal_in_addr addr);





//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

extern ssize_t Universal_recv (int fd, void *buf, size_t n, int flags);

extern ssize_t Universal_send (int fd, const void *buf, size_t n, int flags);

extern const char *Universal_inet_ntop(int af, const void *src, char *dst, Universal_socket_len size);

extern int Universal_inet_pton(int af, const char *src, void *dst);

uint32_t Universal_ntohl(uint32_t netlong);

uint16_t Universal_htons(uint16_t value);

uint16_t Universal_ntohs(uint16_t value);

extern in_addr_t Universal_inet_addr(const char *ip);




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

extern int Universal_bind (int fd,Universal_sockaddr_in  *addrin , Universal_socket_len len);

extern int Universal_accept (int fd, Universal_sockaddr_in *addrin,
		   Universal_socket_len *adrr_len);

extern int Universal_listen (int fd, int n);

extern int Universal_connect(int sockfd, const Universal_sockaddr *addr, socklen_t addrlen);




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end





int Universal_getaddrinfo(const char *node, const char *service, const Universal_addrinfo *hints, Universal_addrinfo **res);






//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


extern char *Universal_GetLastError();









//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

extern int Universal_start_all ();

extern int Universal_close (int fd);

extern int Universal_end ();




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

int Universal_socket (int domain, int type, int protocol);

int Universal_ZeroMemory(void *ptr, size_t num);

void Universal_freeaddrinfo(Universal_addrinfo *addrinfo_ptr);

int Universal_setsockopt(
    Universal_socket_int sockfd,
    int level,
    int optname,
    const void *optval,
    Universal_socket_len optlen
);

int Universal_getsockopt(
    Universal_socket_int sockfd,
    int level,
    int optname,
    void *optval,
    Universal_socket_len *optlen
);






#endif

#ifndef silverchain_UniversalSocket_def
#define silverchain_UniversalSocket_def

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

extern ssize_t Universal_recv (int fd, void *buf, size_t n, int flags){
    return recv(fd, buf, n,flags);
}
extern ssize_t Universal_send (int fd, const void *buf, size_t n, int flags){
    return send(fd,buf,n,flags);
}

extern const char *Universal_inet_ntop(int af, const void *src, char *dst, Universal_socket_len size){
    return 0;//inet_ntop(af, src, dst, size);
}

extern int Universal_inet_pton(int af, const char *src, void *dst){
    return 0;// inet_pton(af, src, dst);
}

extern uint32_t Universal_ntohl(uint32_t netlong){
    return ntohl(netlong);
}

uint16_t Universal_htons(uint16_t value) {
    return htons(value);
}

uint16_t Universal_ntohs(uint16_t value) {
    return ntohs(value);
}

extern in_addr_t Universal_inet_addr(const char *ip) {
  return inet_addr(ip);
}



//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

extern int Universal_bind (int fd, Universal_sockaddr_in  *addrin , Universal_socket_len len){
    return bind(fd,(const struct sockaddr *)addrin,len);
}
extern int Universal_accept (int fd, Universal_sockaddr_in *addrin, Universal_socket_len *adrr_len){
    return accept(fd,( struct sockaddr *)addrin, adrr_len);
}
extern int Universal_listen (int fd, int n){
   return  listen(fd,n);
}

extern int Universal_connect(int sockfd, const Universal_sockaddr *addr, socklen_t addrlen){
    return connect(sockfd, addr, addrlen);
}


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end





const char* Universal_gai_strerror(int e_code){
    return gai_strerror(e_code);
}


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

int Universal_socket (int domain, int type, int protocol){
    return socket(domain,type,protocol);
}

int Universal_ZeroMemory(void *ptr, size_t num){

    if (ptr == NULL || num <= 0) {
        return -1;
    }

    memset(ptr, 0, (unsigned long long)num);
    return 0;
}

int Universal_getaddrinfo(const char *node, const char *service, const Universal_addrinfo *hints, Universal_addrinfo **res){
    return 0;//getaddrinfo(node, service, hints, res);
}


void Universal_freeaddrinfo(Universal_addrinfo *addrinfo_ptr){
    //freeaddrinfo(addrinfo_ptr);
}

int Universal_setsockopt(
    Universal_socket_int sockfd,
    int level,
    int optname,
    const void *optval,
    Universal_socket_len optlen
){
    return setsockopt(sockfd, level, optname, (const char *)optval, optlen);
}

int Universal_getsockopt(
    Universal_socket_int sockfd,
    int level,
    int optname,
    void *optval,
    Universal_socket_len *optlen
){
    return getsockopt(sockfd, level, optname, (char *)optval, optlen);
}




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#if defined(__linux__)

extern const char* Universal_inet_ntoa(Universal_in_addr addr) {
  static char buffer[INET_ADDRSTRLEN];
  return inet_ntop(UNI_AF_INET, &addr, buffer, INET_ADDRSTRLEN);
}

#endif




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#if defined(__linux__)


extern char *Universal_GetLastError(){
  return strerror(errno);
}



#endif







//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

#if defined(__linux__)

extern int Universal_start_all (){
    return 0;
}

extern int Universal_end (){
    return 0;
}

extern int Universal_close (int fd){
    return close(fd);
}

#endif


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#if defined(_WIN32)

extern const char* Universal_inet_ntoa(Universal_in_addr addr) {
  return inet_ntoa(addr);
}

#endif




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#if defined(_WIN32)


extern char *Universal_GetLastError(){

  static char errorBuffer[256];

  DWORD dwError = WSAGetLastError();
  if (dwError == 0) {
      return "Nenhum erro";
  }

  FormatMessage(
      FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
      NULL,
      dwError,
      0,
      errorBuffer,
      sizeof(errorBuffer),
      NULL
  );

  return errorBuffer;
}



#endif





//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end
#if defined(_WIN32)

extern int Universal_start_all (){
    WSADATA wsa;
    int error = WSAStartup(MAKEWORD(2, 2), &wsa);
    return error;
}

extern int Universal_end (){
    WSACleanup();
}

extern int Universal_close (int fd){
    return closesocket(fd);
}

#endif

#endif
