


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
