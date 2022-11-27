import base64
import socket
from dnslib import DNSRecord

def base64Encoder(data):
    message = data
    message_bytes = message.encode('ascii')
    base64_bytes = base64.b64encode(message_bytes)
    base64_message = base64_bytes.decode('ascii')
    return base64_message

def base64Decoder(data):
    base64_img_bytes = data.encode('utf-8')
    decoded = base64.decodebytes(base64_img_bytes)
    return decoded

def socketUdp(query,IPserverDNS):
    bytesToSend         = query
    serverAddressPort   = (IPserverDNS, 53)
    bufferSize          = 1024
    # Create a UDP socket at client side
    UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    # Send to server using created UDP socket
    UDPClientSocket.sendto(bytesToSend, serverAddressPort)
    msgFromServer = UDPClientSocket.recvfrom(bufferSize)
    msg = "Message from Server {}".format(msgFromServer[0])
    d = DNSRecord.parse(msgFromServer[0])
    return msgFromServer[0]
