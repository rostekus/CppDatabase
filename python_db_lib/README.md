# Python DB Library

The **Python DB Library** is a simple Python package that provides a class, `MyDB`, to interact with a custom database via HTTP. It allows you to set and retrieve key-value pairs from the database using HTTP POST and GET requests.

## Installation

To install the library, you can use `pip`:

```bash
pip install -e .
```

## Usage

```python
from python_db_lib import MyDB

# Create an instance of MyDB with the base URL and port of your custom database server.
db = MyDB(base_url='http://your-database-server', port=8000)

# Set a value with a key.
response = db.setvaluekey('my_key', 'my_value')
print(response.text)

# Get the value associated with a key.
response = db.getvaluebykey('my_key')
print(response.text)
```
