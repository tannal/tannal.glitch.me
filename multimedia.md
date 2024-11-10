
# pipewire

// 核心组件
struct pw_core;        // PipeWire 核心
struct pw_registry;    // 对象注册表
struct pw_context;     // 上下文环境
struct pw_main_loop;   // 主事件循环

[Source Nodes] → [Filter Nodes] → [Sink Nodes]
     ↑              ↑               ↑
     └──────────────┴───────────────┘
           Media Route Bus

// 节点连接
pw_link_new()              // 创建连接
pw_link_disconnect()       // 断开连接

// 端口管理
pw_port_new()             // 创建端口
pw_port_get_direction()   // 获取端口方向

// 缓冲区管理
pw_buffer_new()           // 创建缓冲区
pw_buffer_recycle()       // 回收缓冲区

# AOSP

应用层:     MediaPlayer/AudioTrack/AudioRecord
           ↓
框架层:     AudioManager/AudioService
           ↓
HAL层:      AudioFlinger/AudioPolicyService
           ↓
驱动层:     ALSA/OSS/厂商定制驱动

# IOS

// 框架层次结构
Core Audio
    ├── Audio Toolbox        // 高级音频服务
    ├── Audio Unit           // 音频处理单元
    ├── AVFoundation         // 媒体处理
    └── Audio Session        // 音频会话管理

ffmpeg -hwaccel vulkan -threads 8 -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccel cuda -threads 3 -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c:v libx264 -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccel dxva2 -threads 8 -i Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4 -f lavfi -i aevalsrc=0 -vcodec copy -acodec aac -map 0:0 -map 1:0 -c:v libx264 -pix_fmt yuv420p -shortest -strict experimental -f flv rtmp://192.168.43.246/live/livestream

ffmpeg -hwaccel dxva2 -threads 8 -re -i Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4 -f flv rtmp://192.168.43.246/live/livestream

ffmpeg -hwaccel cuda -threads 3 -preset ultrafast -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccels
ffmpeg -benchmark -hwaccel vdpau -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -f null -


ffmpeg -hwaccel vdpau -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -vcodec libx264 -acodec aac -b:v 1m -b:a 320k -f flv rtmp://localhost/live/livestream


1. JACK:
专业级低延迟
应用间灵活路由
强大的连接管理
跨平台支持
其他常见后端:
Linux: ALSA, PulseAudio
macOS: CoreAudio
Windows: ASIO, WDM
3. 不同后端的特点:
JACK: 专业级应用,复杂路由
ALSA: Linux直接硬件访问
CoreAudio: macOS原生低延迟
ASIO: Windows专业音频
PulseAudio: 桌面普通应用

  "JACK": {
      "features": [
          "低延迟",
          "应用间音频路由",
          "MIDI支持",
          "专业级时钟同步"
      ],
      "platforms": ["Linux", "macOS", "Windows"]
  },

  "ALSA": {  # Linux
      "features": ["直接硬件访问", "MIDI支持"],
      "type": "Linux原生音频系统"
  },

  "CoreAudio": {  # macOS
      "features": ["系统级音频", "低延迟"],
      "type": "macOS原生音频系统"
  },

  "ASIO": {  # Windows
      "features": ["低延迟", "专业音频接口"],
      "type": "专业音频驱动标准"
  },

  "PulseAudio": {
      "features": ["网络音频", "混音支持"],
      "type": "用户级音频服务器"
  }
