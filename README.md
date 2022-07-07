# JNIDemo

In this project we will call native code from Java using JNI that crashes in native code

```
java -version
java version "1.8.0"
Java(TM) SE Runtime Environment (build 1.8.0-foreman_2019_10_17_06_18-b00)
IBM J9 VM (build 2.9, JRE 1.8.0 Linux amd64-64-Bit Compressed References 20191106_432135 (JIT enabled, AOT enabled)
OpenJ9   - f0b6be7
OMR      - 18d8f94
IBM      - 233dfb5)
```
Platform details:
```
> lsb_release -a
Distributor ID:	Ubuntu
Description:	Ubuntu 18.04.5 LTS
Release:	18.04
Codename:	bionic
```

## Step 1: Compile the Java Program
`javac Crash.java`

## Step2: Generate a c++ header file for methods defined in Crash.java
`javah -jni Crash`

## Step3: Generate sharedlibrary
`gcc -fPIC -g -I/root/Java8SR6/include -o libCrash.so -shared Crash.c`

## Step4: Enable full core settings to avoid truncated dumps
`ulimit -c unlimited`
`echo "core" > /proc/sys/kernel/core_pattern`

## Step5: Run Java program
`java -Djava.library.path=. Crash`

```
Unhandled exception
Type=Segmentation error vmState=0x00040000
J9Generic_Signal_Number=00000018 Signal_Number=0000000b Error_Value=00000000 Signal_Code=00000001
Handler1=00007F477C3AC7D0 Handler2=00007F4777B9F670 InaccessibleAddress=FFFFFFFFFFFFFFA0
RDI=0000000000000000 RSI=0000000000000000 RAX=FFFFFFFFFFFFFFA0 RBX=0000000000000010
RCX=00007F4778000020 RDX=5920696C61766152 R8=00007F47780008D0 R9=00007F477DEB0C40
R10=0000000000000000 R11=0000000000000000 R12=0000000000000000 R13=00007F477C47CCCC
R14=00007F477D30B700 R15=0000000000000000
RIP=00007F47606CC646 GS=0000 FS=0000 RSP=00007F477D30B400
EFlags=0000000000010206 CS=0033 RBP=00007F477D30B420 ERR=0000000000000007
TRAPNO=000000000000000E OLDMASK=0000000000000000 CR2=FFFFFFFFFFFFFFA0
xmm0 0000000000000000 (f: 0.000000, d: 0.000000e+00)
xmm1 ffffffffffffffff (f: 4294967296.000000, d: -nan)
xmm2 00007f477d30b8f0 (f: 2100345088.000000, d: 6.914203e-310)
xmm3 006e6972705f6873 (f: 1885300864.000000, d: 1.353375e-306)
xmm4 6d006f6c6c654874 (f: 1818577024.000000, d: 1.133139e+217)
xmm5 7fffffffffffffff (f: 4294967296.000000, d: nan)
xmm6 402f2d2832160123 (f: 840302912.000000, d: 1.558820e+01)
xmm7 0000000000000000 (f: 0.000000, d: 0.000000e+00)
xmm8 402f2d27692836f6 (f: 1764243200.000000, d: 1.558819e+01)
xmm9 3fe6ccedb94a6bf9 (f: 3108662272.000000, d: 7.125157e-01)
xmm10 3bbcc86800000000 (f: 0.000000, d: 6.095003e-21)
xmm11 bc78ebcb7dee9a3d (f: 2112788992.000000, d: -2.161559e-17)
xmm12 3fd5b16952053ec8 (f: 1376075520.000000, d: 3.389533e-01)
xmm13 bc7e600000000000 (f: 0.000000, d: -2.634611e-17)
xmm14 bbcb114967c30397 (f: 1740833664.000000, d: -1.146354e-20)
xmm15 402e7f9c1e980d00 (f: 513281280.000000, d: 1.524924e+01)
Module=./libCrash.so
Module_base_address=00007F47606CC000 Symbol=Java_Crash_printHello
Symbol_address=00007F47606CC61A
Target=2_90_20191106_432135 (Linux 4.15.0-188-generic)
CPU=amd64 (4 logical CPUs) (0x1f27fd000 RAM)
----------- Stack Backtrace -----------
Java_Crash_printHello+0x2c (0x00007F47606CC646 [libCrash.so+0x646])
(0x00007F477C44E314 [libj9vm29.so+0x141314])
(0x00007F477C44BA37 [libj9vm29.so+0x13ea37])
(0x00007F477C339384 [libj9vm29.so+0x2c384])
(0x00007F477C326100 [libj9vm29.so+0x19100])
(0x00007F477C3E7A12 [libj9vm29.so+0xdaa12])
---------------------------------------
JVMDUMP039I Processing dump event "gpf", detail "" at 2022/07/07 04:16:02 - please wait.
JVMDUMP032I JVM requested System dump using '/root/gitrepo/JNIDemo/core.20220707.041602.17619.0001.dmp' in response to an event
JVMDUMP010I System dump written to /root/gitrepo/JNIDemo/core.20220707.041602.17619.0001.dmp
JVMDUMP032I JVM requested Java dump using '/root/gitrepo/JNIDemo/javacore.20220707.041602.17619.0002.txt' in response to an event
JVMDUMP010I Java dump written to /root/gitrepo/JNIDemo/javacore.20220707.041602.17619.0002.txt
JVMDUMP032I JVM requested Snap dump using '/root/gitrepo/JNIDemo/Snap.20220707.041602.17619.0003.trc' in response to an event
JVMDUMP010I Snap dump written to /root/gitrepo/JNIDemo/Snap.20220707.041602.17619.0003.trc
JVMDUMP007I JVM Requesting JIT dump using '/root/gitrepo/JNIDemo/jitdump.20220707.041602.17619.0004.dmp'
JVMDUMP010I JIT dump written to /root/gitrepo/JNIDemo/jitdump.20220707.041602.17619.0004.dmp
JVMDUMP013I Processed dump event "gpf", detail "".

```
