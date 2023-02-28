More details on networks: https://habr.com/ru/post/491540/

We need TCP/IP.

# IP (Internet Protocol)
* Each device has zero or more IP addresses
  * IPv4: 4 bytes, typically in decimal, point-separated. Only 4B addresses.
  * IPv4: `127.0.0.1` is "local host", means "this device"
  * IPv6: 16 bytes, not covered, e.g. `[::1]` or `[2607:f8b0:4004:c1b::65]`
* Domain Name System (DNS) is a special system which translates "host name" like `hse.ru` to IP addresses (and other stuff)
  * Not demonstrated: `nslookup` tool
  * Translation is not unique
* Similar IP addresses for physically connected devices form a network
  * E.g. my Wi-Fi router is `192.168.10.254`, my computer is `192.168.10.20`, they see each other
  * My computer also has a separate IP address and a separate network for WSL
* IP can send small packages (~2-64 KiB), one-way only.
* If you would like to go to an IP far away, you may need to hop through multiple devices (routers)
  * Demonstrated: `tracert -w 100 mirror.yandex.ru` (`traceroute` on Linux/macOS)
  * Note how there are multiple "local" IP addresses: see Network Address Translation (NAT) for TCP
  * Note that this is one-way road: you cannot reach my computer at `192.168.10.20` if you're not in my network
  * Global IPs are typically reachable from anywhere with "Internet Access"

# TCP
New term: _connection_.

```
  client (initiates)           server (accepts)
┌───────────────────┐  bytes  ┌────────────────┐
│      ip:port      ├────────►│     ip:port    │
│95.161.246.38:65124│◄────────┤186.2.163.228:80│
└───────────────────┘  bytes  └────────────────┘
```

* TCP port is an integer between 1 and 65535
* TCP socket is a `(ip, port)` pair
* Bytes _reliably_ flow in both directions
  (no duplicates, no reordering, no misses).
* `(source ip, source port, destination ip, destination port)` is a unique connection identifier

```
   server                       clients
                ┌─────────95.161.246.48:65124
                ▼
186.2.163.228:443◄────────95.161.246.48:61536
                ▲
                └─────────217.66.156.214:53612
```

* Source IP address and source port are typically automatically chosen (e.g. port is random, IP is the best to connect to the destination)
* One has to know destination IP address and the destination port
  * There are some standard TCP ports for servers: https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers

# Command line tools
See exercises

* Netcat
  * Start server which waits for a single client: `nc -l -p 10000`
  * Connect client: `nc localhost 10000` (`127.0.0.1` is better so `localhost` is not accidentally IPv6)
  * Reads/writes data line-by-line just like your typical C++ program
* Telnet
  * Client only: `telnet localhost 10000`
  * Sends key strokes immediately, does not display them on the screen.
* Web browser
  * Client only: `http://localhost:10000` (not https, it's encrytped)
