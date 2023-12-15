# build linux kernel

https://blog.jm233333.com/linux-kernel/build-and-run-a-tiny-linux-kernel-on-qemu/#generate-a-initramfs-with-busybox


https://kdlp.underground.software/course/spring2023/assignments/A3.md

https://farabimahmud.github.io/emulate-raspberry-pi3-in-qemu/




```patch

diff --git a/include/uapi/linux/sysinfo.h b/include/uapi/linux/sysinfo.h
index 435d5c23f0c0..c1a57491f1a4 100644
--- a/include/uapi/linux/sysinfo.h
+++ b/include/uapi/linux/sysinfo.h
@@ -12,6 +12,7 @@ struct sysinfo {
        __kernel_ulong_t freeram;       /* Available memory size */
        __kernel_ulong_t sharedram;     /* Amount of shared memory */
        __kernel_ulong_t bufferram;     /* Memory used by buffers */
+       __kernel_ulong_t cacheram;      /* Memory used by caches */
        __kernel_ulong_t totalswap;     /* Total swap space size */
        __kernel_ulong_t freeswap;      /* swap space still available */
        __u16 procs;                    /* Number of current processes */
diff --git a/kernel/sys.c b/kernel/sys.c
index e219fcfa112d..bd402c7c8209 100644
--- a/kernel/sys.c
+++ b/kernel/sys.c
@@ -2825,6 +2825,7 @@ static int do_sysinfo(struct sysinfo *info)
        info->freeswap <<= bitcount;
        info->totalhigh <<= bitcount;
        info->freehigh <<= bitcount;
+       info->cacheram = 42;
 
 out:
        return 0;


```