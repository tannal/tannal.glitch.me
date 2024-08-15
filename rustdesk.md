

# inbox

# dev

连接建立过程
RustDesk使用了一个名为hbbs(ID/Rendezvous服务器)的中继服务器来帮助建立连接。基本流程如下：

a) 客户端注册：
客户端启动后，会向hbbs服务器注册自己的ID和网络信息。

rust

复制
// src/client.rs
pub async fn register_peer(&mut self, peer_pk: Vec<u8>) -> ResultType<()> {
    let mut msg_out = Message::new();
    msg_out.set_register_peer(RegisterPeer {
        id: self.get_id(),
        peer_pk: peer_pk,
        ..Default::default()
    });
    self.send(msg_out).await?;
    Ok(())
}
b) 连接请求：
当一个客户端想要连接另一个客户端时，它会向hbbs服务器发送连接请求。

rust

复制
// src/client.rs
pub async fn request_relay(&mut self, relay_server: String) -> ResultType<Vec<u8>> {
    let mut msg_out = Message::new();
    msg_out.set_request_relay(RequestRelay {
        relay_server: relay_server,
        ..Default::default()
    });
    self.send(msg_out).await?;
    Ok(self.recv_relay().await?)
}
c) NAT穿透尝试：
hbbs服务器会尝试帮助两个客户端进行NAT穿透，实现直接连接。

d) 中继连接：
如果NAT穿透失败，hbbs服务器会提供一个中继服务器(hbbr)的地址，客户端通过这个中继服务器进行通信。

数据传输
一旦连接建立，RustDesk使用自定义的协议进行数据传输。主要包括以下几种类型的数据：

a) 屏幕更新
b) 鼠标/键盘事件
c) 文件传输
d) 音频数据

例如，发送鼠标事件的代码：

rust

复制
// src/client/input_service.rs
pub fn send_mouse(&mut self, msg: MouseEvent) {
    self.tx_input.send(MessageInput::Mouse(msg)).ok();
}
加密
RustDesk使用公钥加密来保护通信安全。每个客户端都有一个唯一的ID和对应的公私钥对。

rust

复制
// src/common.rs
pub fn generate_pk(id: &str) -> (Vec<u8>, Vec<u8>) {
    let mut rng = rand::thread_rng();
    let pkcs8_bytes = Ed25519KeyPair::generate_pkcs8(&mut rng).expect("failed to generate key");
    let key_pair = Ed25519KeyPair::from_pkcs8(&pkcs8_bytes).expect("failed to parse key");
    (key_pair.public_key().as_ref().to_vec(), pkcs8_bytes.to_vec())
}
网络优化
RustDesk使用了多种技术来优化网络性能：

a) 自适应比特率：根据网络条件调整视频质量
b) 帧差异编码：只传输变化的屏幕部分
c) 硬件加速：利用GPU进行编解码

核心原理总结
使用中继服务器(hbbs)辅助连接建立
优先尝试P2P直连，失败后使用中继服务器(hbbr)
自定义协议进行高效的数据传输
公钥加密保证安全性
多种优化技术提高性能和用户体验

rendezvous