import string
def mapper(key,value):
    words = value.split()
    for x in range(1,len(words)+1):
        for y in range(len(words)-x+1):
            word = ' '.join(words[y:y+x])
            word = word.lower()
            for letter in word:
                if letter not in string.ascii_lowercase+' 1234567890':
                    word = word.replace(letter,'')
            word = ' '.join(word.split())
            if word != '':
                Wmr.emit('''"'''+str(word)+'''"''', '1')

