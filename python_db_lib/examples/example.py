import python_db_lib as db

mydb = db.MyDB("http://localhost", 8080)

mydb.setvaluekey("hello", "value_hello")
print(mydb.getvaluebykey("hello"))
