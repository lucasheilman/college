#run with wc_reducer.py
def mapper(key, value):
    words=value.split()
    for word in words:
        Wmr.emit('1', word)
