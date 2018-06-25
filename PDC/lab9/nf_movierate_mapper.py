def mapper(key, value):
    words=key.split(',')
    Wmr.emit(words[0], words[2])
