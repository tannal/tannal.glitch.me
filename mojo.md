
# dev

curl -ssL https://magic.modular.com/9f74ec70-7414-4c76-ba7b-57d11445aab9 | bash


(base) a17@17:~/tannalwork/projects$ nvidia-smi
Thu Oct  3 20:02:08 2024       
+-----------------------------------------------------------------------------------------+
| NVIDIA-SMI 560.35.03              Driver Version: 560.35.03      CUDA Version: 12.6     |
|-----------------------------------------+------------------------+----------------------+
| GPU  Name                 Persistence-M | Bus-Id          Disp.A | Volatile Uncorr. ECC |
| Fan  Temp   Perf          Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute M. |
|                                         |                        |               MIG M. |
|=========================================+========================+======================|
|   0  NVIDIA GeForce RTX 4090        Off |   00000000:01:00.0  On |                  Off |
|  0%   49C    P0             63W /  450W |    1359MiB /  24564MiB |      2%      Default |
|                                         |                        |                  N/A |
+-----------------------------------------+------------------------+----------------------+
                                                                                         
+-----------------------------------------------------------------------------------------+
| Processes:                                                                              |
|  GPU   GI   CI        PID   Type   Process name                              GPU Memory |
|        ID   ID                                                               Usage      |
|=========================================================================================|
|    0   N/A  N/A      1466      G   /usr/lib/xorg/Xorg                            391MiB |
|    0   N/A  N/A      2712      G   /usr/bin/gnome-shell                           44MiB |
|    0   N/A  N/A     16003      G   ...erProcess --variations-seed-version         56MiB |
|    0   N/A  N/A    345159      G   ...irefox/4955/usr/lib/firefox/firefox        205MiB |
|    0   N/A  N/A    422256      G   ...erProcess --variations-seed-version         41MiB |
|    0   N/A  N/A   1210729      G   rustdesk                                       29MiB |
|    0   N/A  N/A   3213040      G   ...AAAAAAAIAAAAAAAAAA== --shared-files         15MiB |
|    0   N/A  N/A   3546370      G   ...e/a17/yar/matlab/bin/glnxa64/MATLAB         14MiB |
|    0   N/A  N/A   3546790      G   ...stBeSecure,SameSiteByDefaultCookies          9MiB |
|    0   N/A  N/A   3746319      C   /usr/lib/rustdesk/rustdesk                    422MiB |
|    0   N/A  N/A   3783740      G   /usr/lib/rustdesk/rustdesk                     20MiB |
