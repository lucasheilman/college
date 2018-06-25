import socket
import threading
import sys
import os

class Server:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    connections = []
    def __init__(self, port):
        self.sock.bind(('0.0.0.0', int(port)))
        self.sock.listen(1)
    
    def handler(self, c, a):
        while True:
            data = c.recv(1024)
            data = str(data, 'utf-8')
            response = "Sorry, I don't know"
            for item in QAs:
                if item[0] == data:
                    response = item[1]
            for connection in self.connections:
                connection.send(bytes(response, 'utf-8'))
            if not data:
                self.connections.remove(c)
                c.close()
                break
            if response == "Sorry, I don't know":
                with open("Unknown.txt", "a") as myfile:
                    myfile.write(data +'\n')
                myfile.close()
    
    def run(self):
        while True:
            c, a = self.sock.accept()
            cThread = threading.Thread(target=self.handler, args=(c,a))
            cThread.daemon = True
            cThread.start()
            self.connections.append(c)

class Client:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def sendMsg(self):
        while True:
            self.sock.send(bytes(input(""), 'utf-8'))

    def __init__(self, address, port):
        self.sock.connect((address, int(port)))
        
        iThread = threading.Thread(target=self.sendMsg)
        iThread.daemon = True
        iThread.start()
        while True:
            data = self.sock.recv(1024)
            if not data:
                break
            print(str(data, 'utf-8'))

pid=open("a-ipid.txt","w")
pid.write(str(os.getpid()))
pid.close()     
f = open("QA.txt","r") #opens file with name of "test.txt"
linelist = []
for line in f:
    linelist.append(line)
f.close()
QAs = []
for x in range(0,len(linelist),2):
    question = linelist[x]
    answer = linelist[x+1]
    QAs.append([question[3:-1],answer[3:-1]])

if (len(sys.argv) > 2):
    client = Client(sys.argv[1], sys.argv[2])
else:
    server = Server(sys.argv[1])
    server.run()
