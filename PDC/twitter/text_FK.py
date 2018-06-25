import string
def main():
    f = open("potus_text.txt","r")
    g = open("potus_text_FK.txt","w")
    for aline in f:
        for letter in aline:
            if letter not in string.ascii_letters + ' ':
                aline = aline.replace(letter,'')
        aline = aline.replace('  ',' ')
        g.write(aline+'.\n')
                
main()
