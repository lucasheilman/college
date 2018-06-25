def reducer(key,iter):
    sum = 0
    for s in iter:
        sum = sum + 1
    Wmr.emit(key, str(sum))
