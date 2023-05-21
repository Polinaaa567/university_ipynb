def check_password(old_f):
   def new_f(*args, **kwargs):
       password = input()
       if password != "123":
           print("В доступе отказано")
           return None
       return old_f(*args, **kwargs)
   return new_f()


@check_password
def f1(*args, **kwargs):
   print("Доступ разрешён")
