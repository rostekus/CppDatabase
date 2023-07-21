from fastapi import APIRouter, HTTPException, Depends
from app.services.db_service import DBService

router = APIRouter()

@router.post("/set_value")
def set_value(key: str, value: str, db_service: DBService = Depends()) -> None:
    db_service.set_value_key(key, value)
    return {"message": f"Value for key '{key}' set successfully."}

@router.get("/get_value")
def get_value(key: str, db_service: DBService = Depends()) -> str:
    value = db_service.get_value_by_key(key)
    if value is None:
        raise HTTPException(status_code=404, detail=f"Value for key '{key}' not found.")
    return {"key": key, "value": value}

