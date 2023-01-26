

import socket

client_sock = socket.socket()

host = '192.168.88.128'
port = 4308

try:
        client_sock.connect((host, port))
except socket.error as e:
        print(str(e))

r = client_sock.recv(1024)
print(r.decode('utf-8'))

while True:
        fh = int(input("Enter the fahrenheit value: "))
        client_sock.sendall(str.encode(str(fh)))

        data = client_sock.recv(1024)
        print(data.decode('utf-8'))

client_sock.close()
