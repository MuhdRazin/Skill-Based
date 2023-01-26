import socket
from _thread import *

server_sock = socket.socket()

host = ''
port = 4308
ThreadCount = 0

try:
        server_sock.bind((host, port))
except socket.error as e:
        print(str(e))

print('Waiting for a Connection..')
server_sock.listen(5)

def threaded_client(connection):
        connection.send(str.encode('Welcome to the Server'))
        while True:
                data = connection.recv(2048)
                if not data:
                        break
                fh = int(data.decode('utf-8'))
                cl = (fh - 32) * (5/9)
                reply = 'Server Says: ' + str(cl) + 'C'
                connection.sendall(str.encode(reply))
        connection.close()

while True:
        Client, address = server_sock.accept()
        print('Connected to: ' + address[0] + ':' + str(address[1]))

        start_new_thread(threaded_client, (Client, ))
        ThreadCount += 1
        print('Thread Number: ' + str(ThreadCount))

server_sock.close()
