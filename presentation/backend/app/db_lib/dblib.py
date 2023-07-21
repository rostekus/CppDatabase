import requests

class MyCustomDB:
    def __init__(self, base_url: str, port: int) -> None:
        self.base_url = base_url
        self.port = port

    def set_value_key(self, key: str, value: str) -> requests.Response:
        url = f"{self.base_url}:{self.port}/keyvalue"
        response = requests.post(url, json={key: value})
        response.raise_for_status()
        return response

    def get_value_by_key(self, key: str) -> requests.Response:
        url = f"{self.base_url}:{self.port}/keyvalue"
        response = requests.get(url, json={key: "?"})
        response.raise_for_status()
        return response

