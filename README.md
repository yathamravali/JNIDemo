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
J9Generic_Signal_Number=00000018 Signal_Number=0000000b Error_Value=00000000 Signal_Code=00000002
Handler1=00007FF590C6E7D0 Handler2=00007FF590553670 InaccessibleAddress=00007FF574FD05BA
RDI=00000000015A2700 RSI=000000000166FEE0 RAX=00007FF574FD05BA RBX=0000000000000010
RCX=00000000016F5F58 RDX=00007FF590D1E9C7 R8=0000000000000070 R9=8000000200000000
R10=00007FF591BCD380 R11=00007FF574FD058A R12=0000000000000000 R13=00007FF590D3ECCC
R14=00007FF591BCD700 R15=0000000000000000
RIP=00007FF574FD05A9 GS=0000 FS=0000 RSP=00007FF591BCD420
EFlags=0000000000010202 CS=0033 RBP=00007FF591BCD420 ERR=0000000000000007
TRAPNO=000000000000000E OLDMASK=0000000000000000 CR2=00007FF574FD05BA
xmm0 0000000000000000 (f: 0.000000, d: 0.000000e+00)
xmm1 6e6972705f687361 (f: 1600680832.000000, d: 7.358747e+223)
xmm2 00007ff591bcd8f0 (f: 2445072640.000000, d: 6.951142e-310)
xmm3 0000000000000000 (f: 0.000000, d: 0.000000e+00)
xmm4 00000000000000ff (f: 255.000000, d: 1.259867e-321)
xmm5 7fffffffffffffff (f: 4294967296.000000, d: nan)
xmm6 402f2d50fb076737 (f: 4211566336.000000, d: 1.558851e+01)
xmm7 0000000000000000 (f: 0.000000, d: 0.000000e+00)
xmm8 402f2d515ebfd1e0 (f: 1589629440.000000, d: 1.558851e+01)
xmm9 3fe6cb0f740a3d6b (f: 1946828160.000000, d: 7.122876e-01)
xmm10 3bbcc86800000000 (f: 0.000000, d: 6.095003e-21)
xmm11 bc78ebcb7dee9a3d (f: 2112788992.000000, d: -2.161559e-17)
xmm12 3fd5b6a804f89bfa (f: 83401720.000000, d: 3.392735e-01)
xmm13 3c75400000000000 (f: 0.000000, d: 1.843144e-17)
xmm14 3bc5f644eafafc52 (f: 3942317056.000000, d: 9.301264e-21)
xmm15 402e7f9c1e980d00 (f: 513281280.000000, d: 1.524924e+01)
Module=./libCrash.so
Module_base_address=00007FF574FD0000 Symbol=Java_Crash_printHello
Symbol_address=00007FF574FD058A
Target=2_90_20191106_432135 (Linux 4.15.0-188-generic)
CPU=amd64 (4 logical CPUs) (0x1f27fd000 RAM)
----------- Stack Backtrace -----------
Java_Crash_printHello+0x1f (0x00007FF574FD05A9 [libCrash.so+0x5a9])
(0x00007FF590D10314 [libj9vm29.so+0x141314])
(0x00007FF590D0DA37 [libj9vm29.so+0x13ea37])
(0x00007FF590BFB384 [libj9vm29.so+0x2c384])
(0x00007FF590BE8100 [libj9vm29.so+0x19100])
(0x00007FF590CA9A12 [libj9vm29.so+0xdaa12])
---------------------------------------
JVMDUMP039I Processing dump event "gpf", detail "" at 2022/06/28 03:31:55 - please wait.
JVMDUMP032I JVM requested System dump using '/root/gitrepo/JNIDemo/core.20220628.033155.9590.0001.dmp' in response to an event
JVMDUMP010I System dump written to /root/gitrepo/JNIDemo/core.20220628.033155.9590.0001.dmp
JVMDUMP032I JVM requested Java dump using '/root/gitrepo/JNIDemo/javacore.20220628.033155.9590.0002.txt' in response to an event
JVMDUMP010I Java dump written to /root/gitrepo/JNIDemo/javacore.20220628.033155.9590.0002.txt
JVMDUMP032I JVM requested Snap dump using '/root/gitrepo/JNIDemo/Snap.20220628.033155.9590.0003.trc' in response to an event
JVMDUMP010I Snap dump written to /root/gitrepo/JNIDemo/Snap.20220628.033155.9590.0003.trc
JVMDUMP007I JVM Requesting JIT dump using '/root/gitrepo/JNIDemo/jitdump.20220628.033155.9590.0004.dmp'
JVMDUMP010I JIT dump written to /root/gitrepo/JNIDemo/jitdump.20220628.033155.9590.0004.dmp
JVMDUMP013I Processed dump event "gpf", detail "".

```
