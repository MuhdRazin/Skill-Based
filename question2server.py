import socket

server_sock = socket.socket()

host = ''

port = 8080

server_sock.bind(('',port))

server_sock.listen(5)

def threaded_client(connection):
 data= connection.recv(1024)

 fh = int(data.decode('utf-8'))
 cc = (fh - 32)*(5/9)
 reply = 'Server says : '+str(cc)+'C'
 connection.sendall(str.encode(reply))


while True:
 Client, address = server_sock.accept()
 print('Connected to:'+address[0]+':'+str(address[1]))

 start_new_thread(threaded_client,(Client,))
 ThreadedCount +=1
 print('Thread Number:'+str(ThreadCount))

server_sock.close()
