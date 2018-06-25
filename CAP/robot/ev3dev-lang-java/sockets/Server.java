/**
 * Server.java
 * 
 * Requires one command line argument:
 *   1. port number on this machine (use 3333 by default)
 */

import java.net.*;
import java.io.*;

class Server {
	public static void main(String args[]) throws Exception {
		int port = Integer.parseInt(args[0]);

		System.out.println("Initializing for network communication...");
		ServerSocket sockServer = new ServerSocket(port);

		System.out.println("Waiting for an incoming connection... ");
		Socket sock = sockServer.accept();

		DataInputStream inStream = new DataInputStream(sock.getInputStream());
		DataOutputStream outStream = new DataOutputStream(sock.getOutputStream());
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));

		String message = "";
		String reply   = "";

		while( !message.equals("EOT") ) {
			System.out.print("Message: ");
			message = buff.readLine();
			outStream.writeUTF(message);
			outStream.flush();

			// receive the ACK message from the EV3
			reply = inStream.readUTF();

			if( reply.equals("ACK")) {
				System.out.println("Success!");
			} else {
				System.err.println("Message failed to send.");
				System.exit(1);
			}
		}

		inStream.close();
		sock.close();
		sockServer.close();

		return;
    }
}