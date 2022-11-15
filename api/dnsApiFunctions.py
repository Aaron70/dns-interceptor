import base64
import socket
from dnslib import DNSRecord

def base64Encoder(data):
    data_bytes = data.encode()
    data_b64 = base64.b64encode(data_bytes)
    data_b64_string = data_b64.decode()
    return data_b64_string

def base64Decoder(data):
    data_b64 = data.encode()
    data_bytes = base64.b64decode(data_b64)
    data_string = data_bytes.decode()
    return data_string


def socketUdp(query):
    #msgFromClient       = fun2()
    bytesToSend         = str.encode(query)
    serverAddressPort   = ("127.0.0.1", 53)
    bufferSize          = 1024

    # Create a UDP socket at client side
    UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    # Send to server using created UDP socket
    UDPClientSocket.sendto(bytesToSend, serverAddressPort)
    msgFromServer = UDPClientSocket.recvfrom(bufferSize)
    #client2(msgFromServer)
    msg = "Message from Server {}".format(msgFromServer[0])
    d = DNSRecord.parse(msgFromServer[0])

    #c = BitArray(hex= msgFromServer[0])
    #print(c.bin)
    print(d)
    return d
