

import threading
import random
import socket

# array of quotes
qs = ["The days that break you, are the days that make you", "You never fail until you stop trying", "Winners are not people who never fail, but people who never quit", "Do not give up the beginning is always the hardest", "Allah can change the most hopeless situation into the best moment in your life"]

def handle_client(client_s):
    q = random.choice(qs)
    client_s.send(q.encode())
    client_s.close()

server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_sock.bind(("0.0.0.0", 8888))
server_sock.listen(5)

while True:
    cl, addr = server_sock.accept()
    print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")
    client_handler = threading.Thread(target=handle_client, args=(cl,))
    client_handler.start()
