package dblib

import (
	"bytes"
	"encoding/json"
	"fmt"
	"net/http"
)

type MyCustomDB struct {
	baseURL string
	port    int
}

func NewMyCustomDB(baseURL string, port int) *MyCustomDB {
	return &MyCustomDB{baseURL: baseURL, port: port}
}

func (db *MyCustomDB) SetValueKey(key, value string) (*http.Response, error) {
	url := fmt.Sprintf("%s:%d/keyvalue", db.baseURL, db.port)
	data := map[string]string{key: value}
	payload, err := json.Marshal(data)
	if err != nil {
		return nil, err
	}

	response, err := http.Post(url, "application/json", bytes.NewBuffer(payload))
	if err != nil {
		return nil, err
	}

	return response, nil
}

func (db *MyCustomDB) GetValueByKey(key string) (*http.Response, error) {
	url := fmt.Sprintf("%s:%d/keyvalue", db.baseURL, db.port)
	data := map[string]string{key: "?"}
	payload, err := json.Marshal(data)
	if err != nil {
		return nil, err
	}

	response, err := http.Post(url, "application/json", bytes.NewBuffer(payload))

	if err != nil {
		return nil, err
	}

	return response, nil
}
