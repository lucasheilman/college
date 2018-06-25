def mapper(key, value):
  try:
    value = int(value)*(-1)
    Wmr.emit(value, key)
  except:
    Wmr.emit(value,key)
