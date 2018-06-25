def reducer(key, iter):
    sum = []
    for s in iter:
        sum.append(s)
    Wmr.emit(key, ', '.join(sum))
