import string
def mapper(key, value):
    words = value.split()
    for word in words:
        word.lower()
        word.strip(string.punctuation)
        Wmr.emit(word,key)
