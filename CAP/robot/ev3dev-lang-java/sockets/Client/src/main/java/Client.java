/**
 * Client.java
 *
 * Requires two command line arguments:
 *   1. name of the host to connect to (localhost when on same machine)
 *   2. port number (use 3333 by default)
 */

import java.net.*;  
import java.io.*;

class Client {
    public static void main(String args[]) throws Exception {
    	String host = args[0];
    	int port = Integer.parseInt(args[1]);

    	System.out.println("Initializing for network communication... ");
		Socket sock = new Socket(host, port);


		DataInputStream inStream = new DataInputStream(sock.getInputStream());
		DataOutputStream outStream = new DataOutputStream(sock.getOutputStream());
	
		String message = "";
		String reply   = "ACK";

		while( !message.equals("EOT") ) {
			System.out.println("Waiting for a message...");
			message = inStream.readUTF();
			System.out.println("Server: " + message);

			outStream.writeUTF(reply);
			outStream.flush();
		}

		inStream.close();
		outStream.close();
		sock.close();

		return;
	}
}