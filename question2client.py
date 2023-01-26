import socket

client_sock = socket.socket()

port = 8080

client_sock.connect(('192.168.88.128',port))

data = client_sock.recv(1024)

while True:
 fh = int(input("Enter the fahrenheit value : "))

client_sock.sendall(str.encode(str(fh)))

data = client_sock.recv(1024)
print(data.decode('utf-8'))

client_sock.close()
