FROM ubuntu

RUN apt update && apt install -y gcc vim wget

RUN wget https://busybox.net/downloads/binaries/1.35.0-x86_64-linux-musl/busybox -O /root/busybox 
RUN chmod +x /root/busybox

COPY . /root

WORKDIR /root
