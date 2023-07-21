# Go Lib DB

`go-lib-db` is a simple Golang library that provides a client to interact with a custom database via HTTP. It allows you to set and retrieve key-value pairs from the database using HTTP POST and GET requests.

## Usage

To use the `go-lib-db` library in your Go code, import the package and create an instance of `MyCustomDB` with the base URL and port of your custom database server:

```go
package main

import (
	"fmt"
	"github.com/your-username/go-lib-db/dblib"
	"io/ioutil"
)

func main() {
	// Create an instance of MyCustomDB with the base URL and port of your custom database server.
	db := dblib.NewMyCustomDB("http://your-database-server", 8000)

	// Set a value with a key.
	response, err := db.SetValueKey("my_key", "my_value")
	if err != nil {
		fmt.Println("Error:", err)
		return
	}
	defer response.Body.Close()

	fmt.Println("Set response status:", response.Status)

	// Get the value associated with a key.
	response, err = db.GetValueByKey("my_key")
	if err != nil {
		fmt.Println("Error:", err)
		return
	}
	defer response.Body.Close()

	value, err := ioutil.ReadAll(response.Body)
	if err != nil {
		fmt.Println("Error reading response:", err)
		return
	}

	fmt.Println("Get response body:", string(value))
}


```
