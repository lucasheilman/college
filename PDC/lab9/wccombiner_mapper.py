def mapper(key, value):
    words=key.split()
    d = {}
    for word in words:
        d[word] = d.get(word, default = 0) + 1
    for key, value in dic.items():
        Wmr.emit(key, value)
