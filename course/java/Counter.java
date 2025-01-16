// 删除 package 声明
// package com.example;

public class Counter {
    static {
        System.loadLibrary("counter");
    }

    private static native void initializeNative();
    private native long createWindow();
    private native void processMessages();

    private long windowHandle;

    public Counter() {
        windowHandle = createWindow();
    }

    public void run() {
        processMessages();
    }

    public static void main(String[] args) {
        initializeNative();
        Counter counter = new Counter();
        counter.run();
    }
}
