def reducer(key, iter):
    sum1 = 0
    sum = 0
    for s in iter:
        sum = sum + int(s)
        sum1 = sum1 + 1
    Wmr.emit(key, str(sum/sum1))
