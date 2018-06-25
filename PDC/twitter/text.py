def main():
    f = open("potus.txt","r")
    g = open("potus_text.txt","w")
    dic = {}
    thisid = 0
    text = ''
    for aline in f:
        if len(aline) >= 8:
            if aline[5:7] == "id":
                thisid = int((aline[11:-3]))
            if aline[5:9] == "text":
                text = (aline[13:-3])
        if text != '' and thisid != 0:
            dic[thisid] = text
            thisid = 0
            text = ''
    for x in sorted(dic):
        g.write(str(x) + "\t" + dic[x] + "\n")
                
main()
