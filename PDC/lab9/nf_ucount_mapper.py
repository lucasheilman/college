def mapper(key, value):
    words=key.split(',')
    Wmr.emit(words[1], '1')
