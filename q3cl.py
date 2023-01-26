import socket

client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_sock.connect(("192.168.88.128", 8888))

r = client_sock.recv(4096).decode()
print(r)

client_sock.close()
