import requests
from os.path import join


class MyDB:
    def __init__(self, base_url: str, port: int) -> None:
        self.base_url = base_url
        self.port = port

    def setvaluekey(self, key: str, value: str) -> requests.Response:
        url = join(f"{self.base_url}:{self.port}", "keyvalue")
        response = requests.post(url, json={key: value})
        response.raise_for_status()
        return response

    def getvaluebykey(self, key: str) -> requests.Response:
        url = join(f"{self.base_url}:{self.port}", "keyvalue")
        response = requests.get(url, json={key: "?"})
        response.raise_for_status()
        return response
