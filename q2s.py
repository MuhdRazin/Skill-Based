import socket
from _thread import *

server_sock = socket.socket()

host = ''
port = 4308
threadC = 0

try:
        server_sock.bind((host, port))
except socket.error as e:
        print(str(e))

server_sock.listen(5)

def threaded_client(connection):
        connection.send(str.encode('WELCOME'))
        while True:
                data = connection.recv(2048)
                if not data:
                        break
                fh = int(data.decode('utf-8'))
                cl = (fh - 32) * (5/9)
                reply = 'The value in celcius: ' + str(cl) + 'C'
                connection.sendall(str.encode(reply))
        connection.close()

while True:
 client, addr = server_sock.accept()
 print('Connected to : '+addr[0]+str(addr[1]))

 start_new_thread(threaded_client,(client,))
 threadC += 1
 print('Thread number '+str(threadC))

server_sock.close()
