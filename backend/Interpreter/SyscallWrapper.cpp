
#include "elf32-tiny.h"
#include "SyscallWrapper.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/DataTypes.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/times.h>
#include <time.h>
#include <sys/utsname.h>

using namespace llvm;

#define ARM__NR_SYSCALL_BASE	0x900000

#define ARM__NR_restart_syscall		(ARM__NR_SYSCALL_BASE+  0)
#define ARM__NR_exit			(ARM__NR_SYSCALL_BASE+  1)
#define ARM__NR_fork			(ARM__NR_SYSCALL_BASE+  2)
#define ARM__NR_read			(ARM__NR_SYSCALL_BASE+  3)
#define ARM__NR_write			(ARM__NR_SYSCALL_BASE+  4)
#define ARM__NR_open			(ARM__NR_SYSCALL_BASE+  5)
#define ARM__NR_close			(ARM__NR_SYSCALL_BASE+  6)
#define ARM__NR_creat			(ARM__NR_SYSCALL_BASE+  8)
#define ARM__NR_time			(ARM__NR_SYSCALL_BASE+ 13)
#define ARM__NR_lseek			(ARM__NR_SYSCALL_BASE+ 19)
#define ARM__NR_getpid			(ARM__NR_SYSCALL_BASE+ 20)
#define ARM__NR_access			(ARM__NR_SYSCALL_BASE+ 33)
#define ARM__NR_kill			(ARM__NR_SYSCALL_BASE+ 37)
#define ARM__NR_dup			(ARM__NR_SYSCALL_BASE+ 41)
#define ARM__NR_times			(ARM__NR_SYSCALL_BASE+ 43)
#define ARM__NR_brk			(ARM__NR_SYSCALL_BASE+ 45)
#define ARM__NR_gettimeofday		(ARM__NR_SYSCALL_BASE+ 78)
#define ARM__NR_settimeofday		(ARM__NR_SYSCALL_BASE+ 79)
#define ARM__NR_mmap			(ARM__NR_SYSCALL_BASE+ 90)
#define ARM__NR_munmap			(ARM__NR_SYSCALL_BASE+ 91)
#define ARM__NR_socketcall		(ARM__NR_SYSCALL_BASE+102)
#define ARM__NR_stat			(ARM__NR_SYSCALL_BASE+106)
#define ARM__NR_lstat			(ARM__NR_SYSCALL_BASE+107)
#define ARM__NR_fstat			(ARM__NR_SYSCALL_BASE+108)
#define ARM__NR_uname			(ARM__NR_SYSCALL_BASE+122)
#define ARM__NR__llseek			(ARM__NR_SYSCALL_BASE+140)
#define ARM__NR_readv			(ARM__NR_SYSCALL_BASE+145)
#define ARM__NR_writev			(ARM__NR_SYSCALL_BASE+146)
#define ARM__NR_mmap2			(ARM__NR_SYSCALL_BASE+192)
#define ARM__NR_stat64			(ARM__NR_SYSCALL_BASE+195)
#define ARM__NR_lstat64			(ARM__NR_SYSCALL_BASE+196)
#define ARM__NR_fstat64			(ARM__NR_SYSCALL_BASE+197)
#define ARM__NR_getuid32		(ARM__NR_SYSCALL_BASE+199)
#define ARM__NR_getgid32		(ARM__NR_SYSCALL_BASE+200)
#define ARM__NR_geteuid32		(ARM__NR_SYSCALL_BASE+201)
#define ARM__NR_getegid32		(ARM__NR_SYSCALL_BASE+202)
#define ARM__NR_fcntl64			(ARM__NR_SYSCALL_BASE+221)
#define ARM__NR_exit_group	        (ARM__NR_SYSCALL_BASE+248)


namespace {

uint32_t *GetSyscallTable() {
  static uint32_t syscall_table[] = {
    ARM__NR_restart_syscall,
    ARM__NR_exit,
    ARM__NR_fork,
    ARM__NR_read,
    ARM__NR_write,
    ARM__NR_open,
    ARM__NR_close,
    ARM__NR_creat,
    ARM__NR_time,
    ARM__NR_lseek,
    ARM__NR_getpid,
    ARM__NR_access,
    ARM__NR_kill,
    ARM__NR_dup,
    ARM__NR_times,
    ARM__NR_brk,
    ARM__NR_mmap,
    ARM__NR_munmap,
    ARM__NR_stat,
    ARM__NR_lstat,
    ARM__NR_fstat,
    ARM__NR_uname,
    ARM__NR__llseek,
    ARM__NR_readv,
    ARM__NR_writev,
    ARM__NR_mmap2,
    ARM__NR_stat64,
    ARM__NR_lstat64,
    ARM__NR_fstat64,
    ARM__NR_getuid32,
    ARM__NR_getgid32,
    ARM__NR_geteuid32,
    ARM__NR_getegid32,
    ARM__NR_fcntl64,
    ARM__NR_exit_group,
    ARM__NR_socketcall,
    ARM__NR_gettimeofday,
    ARM__NR_settimeofday
  };
  return syscall_table;
}

  uint32_t GetInt(OiMachineModel *MM, uint32_t num) {
    return MM->Bank[5 + num];
  }
  void SetInt(OiMachineModel *MM, uint32_t num, int32_t val) {
    MM->Bank[4 + num] = (uint32_t) val;
  }
  void SetBuffer(OiMachineModel *MM, int argn, unsigned char* buf,
                 unsigned int size) {
    memcpy(&MM->Mem->memory[MM->Bank[5+argn]],buf,size);
  }
  void GetBuffer(OiMachineModel *MM, int argn, unsigned char* buf,
                 unsigned int size) {
    memcpy(buf,&MM->Mem->memory[MM->Bank[5+argn]],size);
  }
  

}

void ProcessSyscall(OiMachineModel *MM) {
#ifndef NDEBUG
  raw_ostream &DebugOut = outs();
#else
  raw_ostream &DebugOut = nulls();
#endif
#define DEBUG_SYSCALL(x) DebugOut << "Executing syscall: " << x
#define SET_BUFFER_CORRECT_ENDIAN(x,y,z) memcpy(&MM->Mem->memory[MM->Bank[5+x]],y,z)
#define CORRECT_STAT_STRUCT(buf)
#define CORRECT_SOCKADDR_STRUCT_TO_HOST(buf)                      
#define CORRECT_SOCKADDR_STRUCT_TO_GUEST(buf)                          
#define CORRECT_TIMEVAL_STRUCT(buf)                                     
#define CORRECT_TIMEZONE_STRUCT(buf)                                    

  const uint32_t *sctbl = GetSyscallTable();
  const uint32_t syscall = MM->Bank[4];
  
  if (syscall == sctbl[0]) {        // restart_syscall

  } else if (syscall == sctbl[1]) { // exit
    DEBUG_SYSCALL("exit");
    int exit_status = GetInt(MM, 0);
    exit(exit_status);
  } else if (syscall == sctbl[2]) { // fork
    int ret = ::fork();
    SetInt(MM, 0, ret);
    return;
  } else if (syscall == sctbl[3]) { // read
    DEBUG_SYSCALL("read");
    int fd = GetInt(MM, 0);
    unsigned count = GetInt(MM, 2);
    unsigned char *buf = (unsigned char*) malloc(count);
    int ret = ::read(fd, buf, count);
    SetBuffer(MM, 1, buf, ret);
    SetInt(MM, 0, ret);
    free(buf);
    return;

  } else if (syscall == sctbl[4]) { // write
    DEBUG_SYSCALL("write");
    int fd = GetInt(MM, 0);
    unsigned count = GetInt(MM, 2);
    unsigned char *buf = (unsigned char*) malloc(count);
    GetBuffer(MM, 1, buf, count);
    int ret = ::write(fd, buf, count);
    SetInt(MM, 0, ret);
    free(buf);
    return;

  } else if (syscall == sctbl[5]) { // open
    DEBUG_SYSCALL("open");
    unsigned char pathname[100];
    GetBuffer(MM, 0, pathname, 100);
    int flags = GetInt(MM, 1);
    int mode = GetInt(MM, 2);
    int ret = ::open((char*)pathname, flags, mode);
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[6]) { // close
    DEBUG_SYSCALL("close");
    int fd = GetInt(MM, 0);
    int ret;
    // Silently ignore attempts to close standard streams (newlib may try to do so when exiting)
    if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
      ret = 0;
    else
      ret = ::close(fd);
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[7]) { // creat
    DEBUG_SYSCALL("creat");
    unsigned char pathname[100];
    GetBuffer(MM, 0, pathname, 100);
    int mode = GetInt(MM, 1);
    int ret = ::creat((char*)pathname, mode);
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[8]) { // time
    DEBUG_SYSCALL("time");
    time_t param;
    time_t ret = ::time(&param);
    if (GetInt(MM, 0) != 0 && ret != (time_t)-1)
      SET_BUFFER_CORRECT_ENDIAN(0, (unsigned char *)&param,(unsigned) sizeof(time_t));
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[9]) { // lseek
    DEBUG_SYSCALL("lseek");
    off_t offset = GetInt(MM, 1);
    int whence = GetInt(MM, 2);
    int fd = GetInt(MM, 0);
    int ret;
    ret = ::lseek(fd, offset, whence);
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[10]) { // getpid
    DEBUG_SYSCALL("getpid");
    pid_t ret = getpid();
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[11]) { // access
    DEBUG_SYSCALL("access");
    unsigned char pathname[100];
    GetBuffer(MM, 0, pathname, 100);
    int mode = GetInt(MM, 1);
    int ret = ::access((char*)pathname, mode);
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[12]) { // kill
    DEBUG_SYSCALL("kill");
    SetInt(MM, 0, 0); 
    return;

  } else if (syscall == sctbl[13]) { // dup
    DEBUG_SYSCALL("dup");
    int fd = GetInt(MM, 0);
    int ret = dup(fd);
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[14]) { // times
    DEBUG_SYSCALL("times");
    struct tms buf;
    clock_t ret = ::times(&buf);
    if (ret != (clock_t)-1)
      SET_BUFFER_CORRECT_ENDIAN(0, (unsigned char*)&buf, 
                                (unsigned)sizeof(struct tms));
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[15]) { // brk
    DEBUG_SYSCALL("brk");
    int ptr = GetInt(MM, 0);
    llvm_unreachable("brk unimplemented!");
    //SetInt(MM, 0, ref.ac_dyn_loader.mem_map.brk((Elf32_Addr)ptr));
    return;

  } else if (syscall == sctbl[16]) { // mmap
    DEBUG_SYSCALL("mmap");
    // Supports only anonymous mappings
    int flags = GetInt(MM, 3);
    Elf32_Addr addr = GetInt(MM, 0);
    Elf32_Word size = GetInt(MM, 1);
    llvm_unreachable("mmap unimplemented!");
    if ((flags & 0x20) == 0) { // Not anonymous
      SetInt(MM, 0, -EINVAL);
    } else {
      //      SetInt(MM, 0, ref.ac_dyn_loader.mem_map.mmap_anon(addr, size));
    }
    return;

  } else if (syscall == sctbl[17]) { // munmap
    DEBUG_SYSCALL("munmap");
    Elf32_Addr addr = GetInt(MM, 0);
    Elf32_Word size = GetInt(MM, 1);
    llvm_unreachable("munmap unimplemented!");
    //    if (ref.ac_dyn_loader.mem_map.munmap(addr, size))
    //            SetInt(MM, 0, 0);
    //    else
      SetInt(MM, 0, -EINVAL);
    return;

  } else if (syscall == sctbl[18]) { // stat
    DEBUG_SYSCALL("stat");
    unsigned char pathname[256];
    GetBuffer(MM, 0, pathname, 256);
    struct stat buf;
    int ret = ::stat((char *)pathname, &buf);
    if (ret >= 0) {
      CORRECT_STAT_STRUCT(buf);
      SetBuffer(MM, 1, (unsigned char*)&buf, sizeof(struct stat));
    }
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[19]) { // lstat
    DEBUG_SYSCALL("lstat");
    unsigned char pathname[256];
    GetBuffer(MM, 0, pathname, 256);
    struct stat buf;
    int ret = ::lstat((char *)pathname, &buf);
    if (ret >= 0) {
      CORRECT_STAT_STRUCT(buf);
      SetBuffer(MM, 1, (unsigned char*)&buf, sizeof(struct stat));
    }
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[20]) { // fstat
    DEBUG_SYSCALL("fstat");
    int fd = GetInt(MM, 0);
    struct stat buf;
    int ret = ::fstat(fd, &buf);
    if (ret >= 0) {
      CORRECT_STAT_STRUCT(buf);
      SetBuffer(MM, 1, (unsigned char*)&buf, sizeof(struct stat));
    }
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[21]) { // uname
    DEBUG_SYSCALL("uname");
    struct utsname *buf = (struct utsname*) malloc(sizeof(utsname));
    int ret = ::uname(buf);
    SetBuffer(MM, 0, (unsigned char *) buf, sizeof(utsname));
    free(buf);
    SetInt(MM, 0, ret);
    return; 

  } else if (syscall == sctbl[22]) { // _llseek
    DEBUG_SYSCALL("_llseek");
    unsigned fd = GetInt(MM, 0);
    unsigned long offset_high = GetInt(MM, 1);
    unsigned long offset_low = GetInt(MM, 2);
    off_t ret_off;
    int ret;
    unsigned whence = GetInt(MM, 4);
    if (offset_high == 0) {
      ret_off = ::lseek(fd, offset_low, whence);
      if (ret_off >= 0) {
	loff_t result = ret_off;
	SET_BUFFER_CORRECT_ENDIAN(3, (unsigned char*)&result,
                                  (unsigned) sizeof(loff_t));
	ret = 0;
      } else {
	ret = -1;
      }
    } else {
      ret = -1;
    }
    SetInt(MM, 0, ret);
    return; 

  } else if (syscall == sctbl[23]) { // readv
    DEBUG_SYSCALL("readv");
    int ret;
    int fd = GetInt(MM, 0);
    int iovcnt = GetInt(MM, 2);
    int *addresses = (int *) malloc(sizeof(int)*iovcnt);
    struct iovec *buf = (struct iovec *) malloc(sizeof(struct iovec)*iovcnt);
    GetBuffer(MM, 1, (unsigned char *) buf, sizeof(struct iovec)*iovcnt);
    for (int i = 0; i < iovcnt; i++) {
      addresses[i] = (int) buf[i].iov_base;
      unsigned char *tmp = (unsigned char *) malloc(buf[i].iov_len);
      buf[i].iov_base = (void *)tmp;
    }
    ret = ::readv(fd, buf, iovcnt);
    for (int i = 0; i < iovcnt; i++) {
      SetInt(MM, 1, addresses[i]);
      SetBuffer(MM, 1, (unsigned char *)buf[i].iov_base, buf[i].iov_len);
      free (buf[i].iov_base);
    }
    free(addresses);
    free(buf);
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[24]) { // writev
    DEBUG_SYSCALL("writev");
    int ret;
    int fd = GetInt(MM, 0);
    int iovcnt = GetInt(MM, 2);
    struct iovec *buf = (struct iovec *) malloc(sizeof(struct iovec)*iovcnt);
    GetBuffer(MM, 1, (unsigned char *) buf, sizeof(struct iovec)*iovcnt);
    for (int i = 0; i < iovcnt; i++) {
      unsigned char *tmp;
      //      buf[i].iov_base = (void *) 
        //        CORRECT_ENDIAN((unsigned) buf[i].iov_base, sizeof(void *));
      //      buf[i].iov_len  = buf[i].iov_len;
      SetInt(MM, 1, (int) buf[i].iov_base);
      tmp = (unsigned char *) malloc(buf[i].iov_len);
      buf[i].iov_base = (void *)tmp;
      GetBuffer(MM, 1, tmp, buf[i].iov_len);
    }
    ret = ::writev(fd, buf, iovcnt);
    for (int i = 0; i < iovcnt; i++) {
      free (buf[i].iov_base);
    }
    free(buf);
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[25]) { // mmap2
    SetInt(MM,0, sctbl[16]);
    return ProcessSyscall(MM); //redirect to mmap

  } else if (syscall == sctbl[26]) { // stat64
    DEBUG_SYSCALL("stat64");
    unsigned char pathname[256];
    GetBuffer(MM, 0, pathname, 256);
    struct stat64 buf;
    int ret = ::stat64((char *)pathname, &buf);
    if (ret >= 0) {
      CORRECT_STAT_STRUCT(buf);
      SetBuffer(MM, 1, (unsigned char*)&buf, sizeof(struct stat64));
    }
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[27]) { // lstat64
    DEBUG_SYSCALL("lstat64");
    unsigned char pathname[256];
    GetBuffer(MM, 0, pathname, 256);
    struct stat64 buf;
    int ret = ::lstat64((char *)pathname, &buf);
    if (ret >= 0) {
      CORRECT_STAT_STRUCT(buf);
      SetBuffer(MM, 1, (unsigned char*)&buf, sizeof(struct stat64));
    }
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[28]) { // fstat64
    DEBUG_SYSCALL("fstat64");
    int fd = GetInt(MM, 0);
    struct stat64 buf;
    int ret = ::fstat64(fd, &buf);
    if (ret >= 0) {
      CORRECT_STAT_STRUCT(buf);
      SetBuffer(MM, 1, (unsigned char*)&buf, sizeof(struct stat64));
    }
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[29]) { // getuid32
    DEBUG_SYSCALL("getuid32");
    uid_t ret = ::getuid();
    SetInt(MM, 0, (int)ret);
    return;

  } else if (syscall == sctbl[30]) { // getgid32
    DEBUG_SYSCALL("getgid32");
    gid_t ret = ::getgid();
    SetInt(MM, 0, (int)ret);
    return;

  } else if (syscall == sctbl[31]) { // geteuid32
    DEBUG_SYSCALL("geteuid32");
    uid_t ret = ::geteuid();
    SetInt(MM, 0, (int)ret);
    return;

  } else if (syscall == sctbl[32]) { // getegid32
    DEBUG_SYSCALL("getegid32");
    gid_t ret = ::getegid();
    SetInt(MM, 0, (int)ret);
    return;

  } else if (syscall == sctbl[33]) { // fcntl64
    DEBUG_SYSCALL("fcntl64");
    int ret = -EINVAL;
    SetInt(MM, 0, ret);
    return;

  } else if (syscall == sctbl[34]) { // exit_group
    DEBUG_SYSCALL("exit_group");
    int exit_status = GetInt(MM, 0);
    exit(exit_status);
    return;
  } else if (syscall == sctbl[35]) { // socketcall
    DEBUG_SYSCALL("socketcall");
    // See target toolchain include/linux/net.h and include/asm/unistd.h
    // for detailed information on socketcall translation. This works
    // form ARM.
    int ret;
    int call = GetInt(MM, 0);
    unsigned char tmp[256];
    GetBuffer(MM, 1, tmp, 256);
    unsigned *args = (unsigned*) tmp;
    switch (call) {
    case 1: // Assuming 1 = SYS_SOCKET
      {
        DEBUG_SYSCALL("\tsocket");
        ret = ::socket(args[0], args[1], args[2]);
        break;
      }
    case 2: // Assuming 2 = SYS_BIND
      {
        DEBUG_SYSCALL("\tbind");
        struct sockaddr buf;
        SetInt(MM, 0, args[1]);
        GetBuffer(MM, 0, (unsigned char*)&buf, sizeof(struct sockaddr));
        CORRECT_SOCKADDR_STRUCT_TO_HOST(buf);
        ret = ::bind(args[0], &buf, args[2]);
        break;
      }
    case 3: // Assuming 3 = SYS_CONNECT
      {
        DEBUG_SYSCALL("\tconnect");
        struct sockaddr buf;
        SetInt(MM, 0, args[1]);
        GetBuffer(MM, 0, (unsigned char*)&buf, sizeof(struct sockaddr));
        CORRECT_SOCKADDR_STRUCT_TO_HOST(buf);
        ret = ::connect(args[0], &buf, args[2]);
        break;
      }
    case 4: // Assuming 4 = SYS_LISTEN
      {
        DEBUG_SYSCALL("\tlisten");
        ret = ::listen(args[0], args[1]);
        break;
      }
    case 5: // Assuming 5 = SYS_ACCEPT
      {
        struct sockaddr addr;
        socklen_t addrlen;
        DEBUG_SYSCALL("\taccept");
        ret = ::accept(args[0], &addr, &addrlen);
        CORRECT_SOCKADDR_STRUCT_TO_GUEST(addr);
        //        addrlen = CORRECT_ENDIAN(addrlen, sizeof(socklen_t));
        SetInt(MM, 0, args[1]);
        SetBuffer(MM, 0, (unsigned char*)&addr, sizeof(struct sockaddr));
        SetInt(MM, 0, args[2]);
        SetBuffer(MM, 0, (unsigned char*)&addrlen, sizeof(socklen_t));
        break;
      }
    default:
      llvm_unreachable("Unimplemented socketcall() call number #");
      break;
    }
    SetInt(MM, 0, ret);
    return;
  } else if (syscall == sctbl[36]) { // gettimeofday
    DEBUG_SYSCALL("gettimeofday");
    int ret = -EINVAL;
    struct timezone tz;
    struct timeval tv;
    ret = ::gettimeofday(&tv, &tz);
    CORRECT_TIMEVAL_STRUCT(tv);
    CORRECT_TIMEZONE_STRUCT(tz);
    SetBuffer(MM, 0, (unsigned char*)&tv, sizeof(struct timeval));
    SetBuffer(MM, 1, (unsigned char*)&tz, sizeof(struct timezone));   
    SetInt(MM, 0, ret);
    return;
  } else if (syscall == sctbl[37]) { // settimeofday
    DEBUG_SYSCALL("settimeofday");
    int ret = -EPERM;
    llvm_unreachable("settimeofday: Ignored attempt to change host date");
    SetInt(MM, 0, ret);
    return;
  }

  /* Default case */
  SetInt(MM, 0, -EINVAL);
  return;
}
#undef DEBUG_SYSCALL
#undef SET_BUFFER_CORRECT_ENDIAN
#undef CORRECT_STAT_STRUCT
#undef CORRECT_SOCKADDR_STRUCT_TO_HOST
#undef CORRECT_SOCKADDR_STRUCT_TO_GUEST
#undef CORRECT_TIMEVAL_STRUCT                                     
#undef CORRECT_TIMEZONE_STRUCT
