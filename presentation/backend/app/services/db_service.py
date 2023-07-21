from app.db_lib.dblib import MyCustomDB
import requests

class DBService:
    
    def __init__(self, base_url: str, port: int) -> None:
        self.db = MyCustomDB(base_url, port)

    def set_value_key(self, key: str, value: str) -> None:
        self.db.set_value_key(key, value)

    def get_value_by_key(self, key: str) -> str:
        response = self.db.get_value_by_key(key)
        return response.json().get(key, None)

