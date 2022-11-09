# Terminal Tools
Here i just plan on including some useful terminal tools as well as optional configurations and flags. 

## Debugging

## Networking
### Netcat
Netcat is a very useful command line utility for a variety of different network functions, its really useful for scanning and sending data. Here are some examples below
#### TCP Scan
```
nc -nv -w 1 -z [IP_ADDRESS] [PORT]
```
- ```-w ``` specifies connection timeout in seconds
- ```-z ``` zero IO mode (dont send any data)
- ```-n``` no name resolution
- ```-v``` Increase verbosity

#### UDP Scan
```
nv -nv -u -z -w 1 [IP_ADDRESS] [PORT]
```
- ``` -u``` is UDP mode

*Note: This is pretty unreliable with a firewall because it relies on an ICMP unreachable to call something closed*

#### Listen on a port
```
netcat -l -p [PORT]
```
- ```-l``` specifies a listening port
- ```-p``` specifies port to listen on

### Tcpdump
TCPdump is a useful command line utility for sniffing packets on a  network. Below ive syntax with some useful flags
#### Capture Traffic on an IP/Port
```
tcpdump -i eth0 -nn -s0 -v -A src [IP_ADDRESS] and dst port [PORT]
```
- ```-i``` - Specified interface to capture on, in this case we're using ```eth1```
- ```-nn``` 1 ```n``` disables name resolution 2 ```n```s disable name and port resolution
- ```-v``` increase verbosity
- ```-A``` include ASCII strings to help readability 


