# Those settings which all accounts should have and which might change
# from time to time are located in /usr/local/lib/generic.cshrc.
# It is _highly_ recommended that you do not remove or modify the 
# next four lines.

if ( -f /usr/local/lib/generic.cshrc ) then
	source /usr/local/lib/generic.cshrc
endif 

#
# umask sets the default permissions on all file creations 077
# sets the file to be readable and writeable only by the owner
#
umask 077

# Useful "mandatory" C Shell stuff
set history=100
set prompt = "`hostname`% "
alias h history

