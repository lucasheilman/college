def reducer(key, values):
  for value in values:
    Wmr.emit(key,value)
