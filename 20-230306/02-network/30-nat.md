# NAT
```
  client (initiates)            router local     router internet              server (accepts)
┌───────────────────┐         ┌──────────────┬───────────────────┐         ┌────────────────┐
│      ip:port      ├────────►│      ip      │      ip:port      ├────────►│     ip:port    │
│192.168.10.20:65124│◄────────┤192.168.10.254│95.161.246.38:23768│◄────────┤186.2.163.228:80│
└───────────────────┘         └──────────────┴───────────────────┘         └────────────────┘
```

1. Router intercepts the connection request from the client.
2. Initiates a new one "on behalf" of the client.
3. Remembers that data flowing to `:23768` should go to the local network to `192.168.10.20:65124`.

Now:

* Client thinks it talks to the server.
* Server thinks it talks to `95.161.246.38:23768`.

But you cannot initiate connection from the outside.

## Port forwarding
If you want to overcome NAT, do like in old local network games:

1. Easiest way: buy(!) a public IP address as a part of VDS/VPS (Virtual Dedicated/Private Server).
  I may set up an instance for your projects, if you wish.
  SSH reverse tunnel (GUI clients should support it as well):
  * https://habr.com/ru/company/ruvds/blog/676596/
  * https://timeweb.cloud/tutorials/network-security/ssh-tunnels#obratnyj-tunnel
2. Use Hamachi or other VPN (Virtual Private Network) _for local network gaming_, not for "private browsing".
3. For HTTP(S) protocol only (subset of TCP): ngrok and alternatives: https://github.com/anderspitman/awesome-tunneling
4. Configure your router with "port forwarding"
