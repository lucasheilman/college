== External Documentation ==

To compile: <gcc -o shell shell.c>
To run: <./shell>

== Extra Features ==

List of extra features, what they do, and how to run them:

1. access; checks the rwx permissions on a file: access <path>
2. chdir; changes current directory: chdir <path>
3. getcwd; prints the current directory: getcwd
4. getgid; prints the current group ID: getgid
5. gethostid; prints the current host ID: gethostid
6. getuid; prints the user current ID: getuid
7. rmdir; removes the specified empty directory: rmdir <path>
8. setgid; sets the current group ID: setgid <id>
9. setuid; sets the current user ID: setuid <id>
10. chmod; sets the permissions on the specified file: chmod <path> <mode>
11. mkdir; creates directory at the specified path: mkdir <path>

If none of these features are specified, then the shell attempts to execute a program: <path> <flags>
