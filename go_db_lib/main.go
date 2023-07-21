package main

import (
	"fmt"
	"go_custom_db_lib/dblib"
	"io/ioutil"
)

func main() {
	db := dblib.NewMyCustomDB("http://your-database-server", 8000)

	response, err := db.SetValueKey("my_key", "my_value")
	if err != nil {
		fmt.Println("Error:", err)
		return
	}
	defer response.Body.Close()

	fmt.Println("Set response status:", response.Status)

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
